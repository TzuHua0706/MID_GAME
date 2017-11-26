#include "GameScene.h"
#include "HelloWorldScene.h"
#include "StopScene.h"
#include "GameEndScene.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace ui;

GameScene::GameScene(){}
GameScene::~GameScene(){}
void GameScene::get_character(C_character * player, float get_level) {
	C_player = new C_character(player->Player, player->Color);
	C_player->character->setPosition(1050, 360);
	gamescene->addChild(C_player->set_character(true),1);
	level = get_level;
}
bool GameScene::init()
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	if (!Layer::init())
	{
		return false;
	}

	gamescene = CSLoader::createNode("gameScene.csb");
	addChild(gamescene);

	//animation
	auto dancer = (ActionTimeline *)CSLoader::createTimeline("gameScene.csb");
	gamescene->runAction(dancer);
	dancer->gotoFrameAndPlay(0, 72, true);

	//Music
	bkmusic = (cocostudio::ComAudio *)gamescene->getChildByName("music_bg")->getComponent("music_bg");
	bkmusic->playBackgroundMusic();

	//Music button
	btn_music = dynamic_cast<Button*>(gamescene->getChildByName("Button_music"));
	btn_music->addTouchEventListener(CC_CALLBACK_2(GameScene::bt_music_event, this));

	//LoadingBar Blood
	blood = (cocos2d::ui::LoadingBar *)gamescene->getChildByName("LoadingBar_Blood");

	//Score
	score_text = (cocos2d::ui::Text *)gamescene->getChildByName("score");

	//Background line
	auto bg_line = CSLoader::createNode("bg_line.csb");
	bg_line->setPosition(640, 353);
	gamescene->addChild(bg_line);
	auto line_Action = (ActionTimeline *)CSLoader::createTimeline("bg_line.csb");
	bg_line->runAction(line_Action);
	line_Action->gotoFrameAndPlay(0, 10, true);

	//Stop button
	btn_stop = new C3SButton("stop.png", "stop_t.png", "stop.png", true);
	btn_stop->img_btn->setPosition(1235, 680);
	btn_stop->img_btn->setScale(0.8f);
	gamescene->addChild(btn_stop->img_btn);

	//Jump
	jump = Rect(origin.x - 100, origin.y - 100, visibleSize.width - 100, visibleSize.height - 100);

	//Touch
	_listener1 = EventListenerTouchOneByOne::create();
	_listener1->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	_listener1->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
	_listener1->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);

	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener1, this);	//加入剛創建的事件聆聽器

	this->schedule(CC_SCHEDULE_SELECTOR(GameScene::doStep));
	return true;
}
void GameScene::doStep(float dt)
{
	fin_time += dt;
	ob_time += dt;
	face_time += dt;
	if (fin_time >= 1.5 && fin_time < 2)score_text->setText("2");
	else if (fin_time >= 2.5 && fin_time < 3)score_text->setText("1");
	else if (fin_time >= 3.5 && fin_time < 4)score_text->setText("GO");
	else if (fin_time >= 4.5 && fin_time < 5)score_text->setText("Score : 0");
	else if (fin_time >= 5 && fin_time < 35) {
		//character範圍
		Size s_ch = C_player->body->getContentSize();
		Point p_ch = (C_player->body->getPosition()) + Point(1050, 360);
		rect_ch = Rect(p_ch.x - s_ch.width / 2, p_ch.y - s_ch.height / 2, s_ch.width, s_ch.height);
		if (ob_time >= level && fin_time < 33) {
			float scale = ((2 * rand() + 1) % 6 + 4) *0.1;
			ob_time = 0;
			g_obstacle[ob] = new CObstacle;
			gamescene->addChild(g_obstacle[ob]->set_obstacle(scale));
			ob++;
			ob = ob % 3;
		}
		for (int i = 0; i < 3; i++) {
			if (g_obstacle[i]) {
				Point p_ob = g_obstacle[i]->Obstacle->getPosition();
				if (p_ob.x > p_ch.x - s_ch.width / 2 && p_ob.x < p_ch.x + s_ch.width / 2) {
					if (g_obstacle[i]->touch_obstacle(rect_ch, p_ob, blood)) {
						C_player->face_character(2);
						face_time = 0;
						g_obstacle[i] = NULL;
						stop_touch = false;
					}
					else if (p_ob.x > p_ch.x + s_ch.width / 2 - 11) {
						score += g_obstacle[i]->get_score;
						sprintf(Score, "Score : %d", score);
						score_text->setText(Score);
						C_player->face_character(1);
						face_time = 0;
						stop_touch = false;
					}
				}
				else if(p_ob.x > p_ch.x + s_ch.width / 2) g_obstacle[i] = NULL;
			}
		}
		if (face_time >= 0.5)C_player->face_character(0);
	}
	else if (fin_time >= 35) {
		RenderTexture *renderTexture = RenderTexture::create(visibleSize.width, visibleSize.height);
		renderTexture->begin();
		this->getParent()->visit();
		renderTexture->end();
		Scene * scene = Scene::create();
		GameEndScene * layer = GameEndScene::create();
		layer->end("YOU WIN", C_player, level, renderTexture);
		scene->addChild(layer);
		Director::sharedDirector()->pushScene(scene);
	}
	if(blood->getPercent()==0) {
		RenderTexture *renderTexture = RenderTexture::create(visibleSize.width, visibleSize.height);
		renderTexture->begin();
		this->getParent()->visit();
		renderTexture->end();
		Scene * scene = Scene::create();
		GameEndScene * layer = GameEndScene::create();
		layer->end("GAMEOVER",C_player, level, renderTexture);
		scene->addChild(layer);
		Director::sharedDirector()->pushScene(scene);
	}
}
void GameScene::bt_music_event(Ref *pSender, Widget::TouchEventType type) {
	switch (type)
	{
	case Widget::TouchEventType::BEGAN:
		music_flag = !music_flag;
		break;
	case Widget::TouchEventType::MOVED:
		break;
	case Widget::TouchEventType::ENDED:
		btn_music->setBright(music_flag);
		if (!music_flag) { bkmusic->stopBackgroundMusic(); }
		else bkmusic->playBackgroundMusic();
		break;
	case Widget::TouchEventType::CANCELED:
		break;
	default: break;
	}
}
bool GameScene::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)//觸碰開始事件
{
	Point touchLoc = pTouch->getLocation();
	if (jump.containsPoint(touchLoc)) {
		if (jump_flag) {
			jump_flag = false;
			auto body = C_player->character->getChildByName("player");
			auto callback = CallFunc::create(this, callfunc_selector(GameScene::jumpFinished));
			body->runAction(Sequence::create(C_player->jump(), callback, NULL));
		}
	}
	if (btn_stop->getrect().containsPoint(touchLoc)) {
		btn_stop->touch();
		stop_touch = true;
	}
	return true;
}
void GameScene::onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) //觸碰移動事件
{
	Point touchLoc = pTouch->getLocation();
}
void GameScene::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) //觸碰結束事件 
{
	Point touchLoc = pTouch->getLocation();
	if (stop_touch) {
		btn_stop->end();
		stop_touch = false;
		RenderTexture *renderTexture = RenderTexture::create(visibleSize.width, visibleSize.height);
		renderTexture->begin();
		this->getParent()->visit();
		renderTexture->end();
		Scene * scene = Scene::create();
		StopScene * layer = StopScene::create();
		layer->get_character(C_player, level, renderTexture);
		scene->addChild(layer);
		Director::sharedDirector()->pushScene(scene);
	}
}
void GameScene::jumpFinished()
{
	jump_flag = true;
}