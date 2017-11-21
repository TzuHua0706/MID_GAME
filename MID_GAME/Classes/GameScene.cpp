#include "GameScene.h"
#include "HelloWorldScene.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace ui;

Scene* GameScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}
GameScene::GameScene()
{
}
GameScene::~GameScene()
{

}
void GameScene::get_character(unsigned int number, cocos2d::Color3B color) {
	//character = Sprite::createWithSpriteFrameName("cuber01.png");
	character = ch->set_character(animation_character[number], color,true);
	character->setPosition(1050, 390);
	auto chAction = (ActionTimeline *)CSLoader::createTimeline(animation_character[number]);
	character->runAction(chAction);
	chAction->gotoFrameAndPlay(0, 24, true);
	gamescene->addChild(character);
}
bool GameScene::init()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//////////////////////////////
	// 1. super init first
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
	/*bkmusic = (cocostudio::ComAudio *)gamescene->getChildByName("music_bg")->getComponent("music_bg");
	bkmusic->playBackgroundMusic();*/

	//Music button
	btn_music = dynamic_cast<Button*>(gamescene->getChildByName("Button_music"));
	btn_music->addTouchEventListener(CC_CALLBACK_2(GameScene::bt_music_event, this));

	//background line
	auto bg_line = CSLoader::createNode("bg_line.csb");
	bg_line->setPosition(640, 353);
	gamescene->addChild(bg_line);
	auto line_Action = (ActionTimeline *)CSLoader::createTimeline("bg_line.csb");
	bg_line->runAction(line_Action);
	line_Action->gotoFrameAndPlay(0, 10, true);

	//home button
	btn_home = dynamic_cast<Button*>(gamescene->getChildByName("Button_home"));
	btn_home->addTouchEventListener(CC_CALLBACK_2(GameScene::bt_home_event, this));

	//jump
	this->jump = Rect(origin.x + 50, origin.y + 50, visibleSize.width - 100, visibleSize.height - 100);

	//obstacle範圍
	/*Size s_ob = obstacle->getContentSize();
	Point p_ob = obstacle->getPosition();
	rect_ob = Rect(p_ob.x - s_ob.width / 2, p_ob.y - s_ob.height / 2, s_ob.width, s_ob.height);*/
	//character範圍
	/*Size s_ch = character->getContentSize();
	Point p_ch = character->getPosition();
	rect_ch = Rect(p_ch.x - s_ch.width / 2, p_ch.y - s_ch.height / 2, s_ch.width, s_ch.height);*/
	obstacle = g_obstacle->set_obstacle(1);
	gamescene->addChild(obstacle);

	//觸碰
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
	/*fin_time += dt;
	ob_time += dt;
	float scale = ((2 * rand() + 1) % 6 + 4) *0.1;
	if (ob_time >= 1 && fin_time < 20) {
		ob_time = 0;
		obstacle = g_obstacle->set_obstacle(scale);
		gamescene->addChild(obstacle);
	}*/
	//character範圍
	Size s_ch = Size(240, 210);
	Point p_ch = character->getPosition();
	rect_ch = Rect(p_ch.x - s_ch.width / 2, p_ch.y - s_ch.height / 2, s_ch.width, s_ch.height);
	Point p_ob = obstacle->getPosition(); 
	/*p_ob.y = 285;
	if (rect_ch.containsPoint(p_ob)) {
		log("sad");
	}*/
}
void GameScene::bt_home_event(Ref *pSender, Widget::TouchEventType type) {
	if (scene_btn) {
		removeChild(gamescene);
		CCScene * scene = CCScene::create();
		HelloWorld * layer = HelloWorld::create();
		scene->addChild(layer);
		CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.5f, scene));
		scene_btn = false;
	}
}
void GameScene::bt_music_event(Ref *pSender, Widget::TouchEventType type) {
	switch (type)
	{
	case Widget::TouchEventType::BEGAN:
		music_open = !music_open;
		break;
	case Widget::TouchEventType::MOVED:
		break;
	case Widget::TouchEventType::ENDED:
		btn_music->setBright(music_open);
		if (!music_open) { bkmusic->stopBackgroundMusic(); }
		else bkmusic->playBackgroundMusic();
		break;
	case Widget::TouchEventType::CANCELED:
		break;
	default: break;
	}
}
bool  GameScene::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)//觸碰開始事件
{
	Point touchLoc = pTouch->getLocation();
	if (jump.containsPoint(touchLoc)) {
		if (jump_flag) {
			jump_flag = false;
			auto body = character->getChildByName("player");
			auto callback = CallFunc::create(this, callfunc_selector(GameScene::actionFinished));
			body->runAction(Sequence::create(ch->jump(character), callback, NULL));
		}
	}
	if (rect_ch.containsPoint(touchLoc)) { log("sad"); }
	return true;
}
void  GameScene::onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) //觸碰移動事件
{
	Point touchLoc = pTouch->getLocation();
}
void  GameScene::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) //觸碰結束事件 
{
	Point touchLoc = pTouch->getLocation();
}
void GameScene::actionFinished()
{
	jump_flag = true;
}