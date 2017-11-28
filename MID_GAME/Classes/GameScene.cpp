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
	//�C���i��characer
	C_small = new C_character(player->Player, player->Color);
	C_small->character->setPosition(1180, 50);
	gamescene->addChild(C_small->set_character(true), 1);
	C_small->character->setScale(0.35f);
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
	dancer = (ActionTimeline *)CSLoader::createTimeline("gameScene.csb");
	gamescene->runAction(dancer);
	dancer->gotoFrameAndPlay(0, 72, true);

	//Music
	bkmusic = (cocostudio::ComAudio *)gamescene->getChildByName("music_bg")->getComponent("music_bg");
	bkmusic->playBackgroundMusic();

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

	//Music button
	btn_music = new C3SButton("music.png", "music_t.png", "music_n.png", true); //music_n���O�T�ΡA�ĤT�ع�
	btn_music->img_btn->setPosition(45, 680);
	btn_music->img_btn->setScale(0.8f);
	gamescene->addChild(btn_music->img_btn);

	//Stop button
	btn_stop = new C3SButton("stop.png", "stop_t.png", "stop.png", true);
	btn_stop->img_btn->setPosition(1235, 680);
	btn_stop->img_btn->setScale(0.8f);
	gamescene->addChild(btn_stop->img_btn);

	//�C���i��
	loading_game = (cocos2d::ui::LoadingBar *)gamescene->getChildByName("LoadingBar_game");
	loading_game->setDirection(LoadingBar::Direction::LEFT);
	loading_game->setPercent(100);

	//Jump
	jump = Rect(origin.x - 100, origin.y - 100, visibleSize.width - 100, visibleSize.height - 100);

	//Touch
	_listener1 = EventListenerTouchOneByOne::create();
	_listener1->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	_listener1->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
	_listener1->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);

	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener1, this);	//�[�J��Ыت��ƥ��ť��

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
	else if (fin_time >= 5 && fin_time < 45) {
		float t = loading_game->getPercent();
		if (t >= dt * 2.5)  t = t - dt * 2.5;
		else t = 0;
		loading_game->setPercent(t); 
		Point pt = C_small->character->getPosition();
		if (pt.x >= 100)  pt.x = pt.x - dt * 27;
		else pt.x = 100;
		C_small->character->setPosition(pt.x, 50);
		//character�d��
		Size s_ch = C_player->body->getContentSize();
		Point p_ch = (C_player->body->getPosition()) + Point(1050, 360);
		rect_ch = Rect(p_ch.x - s_ch.width / 2, p_ch.y - s_ch.height / 2, s_ch.width, s_ch.height);
		//float set_time = (rand() % 6)*0.05;
		if (ob_time >= level && fin_time < 43) {
			float scale = ((2 * rand() + 1) % 6 + 4) *0.1;
			if (scale < 0.5)scale = 0.5;
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
					}
				}
				else if (p_ob.x > p_ch.x + s_ch.width / 2 && g_obstacle[i]->score_flag) {
					score += g_obstacle[i]->get_score;
					sprintf(Score, "Score : %d", score);
					score_text->setText(Score);
					C_player->face_character(1);
					face_time = 0;
					g_obstacle[i] = NULL;
				}
		 	}
		}
		if (face_time >= 0.5)C_player->face_character(0);
	}
	if (score >= 100) {
		if (!fire_time)
			dancer->gotoFrameAndPlay(73, 132, true);
		fire_time += dt;
	}
	if (fire_time >= 1.0f && fire) {
		fire = false;
		dancer->gotoFrameAndPlay(0, 72, true);
	}
	else if (fin_time >= 45) {
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
bool GameScene::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)//Ĳ�I�}�l�ƥ�
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
	if (btn_music->getrect().containsPoint(touchLoc)) {
		btn_music->touch();
	}
	if (btn_stop->getrect().containsPoint(touchLoc)) {
		btn_stop->touch();
	}
	return true;
}
void GameScene::onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) //Ĳ�I���ʨƥ�
{
	Point touchLoc = pTouch->getLocation();
}
void GameScene::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) //Ĳ�I�����ƥ� 
{
	Point touchLoc = pTouch->getLocation();
	if (btn_music->touch_flag) {
		btn_music->end();
		music_open = !music_open;
		if (!music_open) {
			bkmusic->stopBackgroundMusic();
			btn_music->img_btn->setSpriteFrame(btn_music->Disable);
		}
		else {
			bkmusic->playBackgroundMusic();
			btn_music->img_btn->setSpriteFrame(btn_music->Normal);
		}
	}
	if (btn_stop->touch_flag) {
		btn_stop->end();
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