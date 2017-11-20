#include "HelloWorldScene.h"
#include "GameScene.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace ui;

Scene* HelloWorld::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = HelloWorld::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}
HelloWorld::HelloWorld()
{
}
HelloWorld::~HelloWorld()
{

}
// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	helloscene = CSLoader::createNode("MainScene.csb");
	addChild(helloscene);

	//Music
	/*bkmusic = (cocostudio::ComAudio *)helloscene->getChildByName("music_bg")->getComponent("music_bg");
	bkmusic->playBackgroundMusic();*/

	//Music button
	btn_music = dynamic_cast<Button*>(helloscene->getChildByName("Button_music"));
	btn_music->addTouchEventListener(CC_CALLBACK_2(HelloWorld::bt_music_event, this));

	//play button
	btn_play = dynamic_cast<Button*>(helloscene->getChildByName("Button_play"));
	btn_play->addTouchEventListener(CC_CALLBACK_2(HelloWorld::bt_play_event, this));

	//animation
	auto dancer = (ActionTimeline *)CSLoader::createTimeline("MainScene.csb");
	helloscene->runAction(dancer);
	dancer->gotoFrameAndPlay(0, 72, true);

	//character button left
	btn_character_left = dynamic_cast<Button*>(helloscene->getChildByName("Button_left"));
	btn_character_left->addTouchEventListener(CC_CALLBACK_2(HelloWorld::bt_character_event_left, this));
	//character button right
	btn_character_right = dynamic_cast<Button*>(helloscene->getChildByName("Button_right"));
	btn_character_right->addTouchEventListener(CC_CALLBACK_2(HelloWorld::bt_character_event_right, this));

	// Level botton
	btn_level_left = dynamic_cast<Button*>(helloscene->getChildByName("Button_left_0"));
	btn_level_left->addTouchEventListener(CC_CALLBACK_2(HelloWorld::bt_level_event_left, this));
	btn_level_right = dynamic_cast<Button*>(helloscene->getChildByName("Button_right_0"));
	btn_level_right->addTouchEventListener(CC_CALLBACK_2(HelloWorld::bt_level_event_right, this));

	//text
	difficulty_text = (cocos2d::ui::Text *)helloscene->getChildByName("difficulty");

	//color設定
	player_color[0] = Color3B(110, 210, 255);
	player_color[1] = Color3B(255, 100, 100);
	player_color[2] = Color3B(124, 255, 144);
	player_color[3] = Color3B(255, 249, 137);
	player_color[4] = Color3B(0, 0, 0);

	//player animation
	for (int i = 0; i < 4; i++) {
		time_line[i] = (ActionTimeline *)CSLoader::createTimeline(run_character[i]);
	}
	time_line[4] = NULL;

	//character
	character[4] = NULL;
	character[3] = player->set_character(run_character[3], player_color[3], false);
	character[3]->setPosition(307, 317);
	character[3]->runAction(time_line[3]);
	time_line[3]->gotoFrameAndPlay(0, 0, false);
	helloscene->addChild(character[3]);
	character[2] = player->set_character(run_character[2], player_color[2], false);
	character[2]->setPosition(620, 350);
	character[2]->runAction(time_line[2]);
	time_line[2]->gotoFrameAndPlay(0, 0, false);
	character[2]->setScale(0.3);
	helloscene->addChild(character[2]);
	character[1] = player->set_character(run_character[1], player_color[1], false);
	character[1]->setPosition(950, 317);
	character[1]->runAction(time_line[1]);
	time_line[1]->gotoFrameAndPlay(0, 0, false);
	helloscene->addChild(character[1]);
	character[0] = player->set_character(run_character[0], player_color[0], true);
	character[0]->setPosition(615, 340);
	character[0]->runAction(time_line[0]);
	time_line[0]->gotoFrameAndPlay(0, 24, true);
	helloscene->addChild(character[0]);

	//play position
	for (int i = 0; i < 4; i++)
		pt[i] = character[i]->getPosition();

	_listener1 = EventListenerTouchOneByOne::create();	//創建一個一對一的事件聆聽器
	_listener1->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);		//加入觸碰開始事件
	_listener1->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);		//加入觸碰移動事件
	_listener1->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);		//加入觸碰離開事件

	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener1, this);	//加入剛創建的事件聆聽器

	this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::doStep));
	return true;
}
void HelloWorld::doStep(float dt)
{
}
void HelloWorld::bt_play_event(Ref *pSender, Widget::TouchEventType type) {
	if (scene_btn) {
		removeChild(helloscene);
		CCScene * scene = CCScene::create();
		GameScene * layer = GameScene::create();
		layer->get_character(get_number, player_color[0]);
		scene->addChild(layer);
		CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.1f, scene));
		scene_btn = false;
	}
}
void HelloWorld::bt_music_event(Ref *pSender, Widget::TouchEventType type) {
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
void HelloWorld::bt_character_event_left(Ref *pSender, Widget::TouchEventType type)
{
	if (ch_action) {
		switch (type)
		{
		case Widget::TouchEventType::BEGAN:
			break;
		case Widget::TouchEventType::MOVED:
			break;
		case Widget::TouchEventType::ENDED:
			ch_action = false;
			get_number++;
			get_number = get_number % 4;
			player_color[4] = player_color[0];
			time_line[4] = time_line[0];
			character[4] = character[0];
			for (int i = 0; i < 5; i++) {
				if (i < 4) {
					player_color[i] = player_color[i + 1];
					character[i] = character[i + 1];
					time_line[i] = time_line[i + 1];
				}
				else {
					character[i] = NULL; player_color[i] = Color3B(0, 0, 0); time_line[i] = NULL;
				}
			}
			for (int i = 3; i >= 0; i--) {
				auto MoveAction = cocos2d::MoveTo::create(0.1f, pt[i]);
				character[i]->runAction(MoveAction);
			}
			for (int i = 3; i >= 0; i--) {
				if (i == 0) {
					auto callback = CallFunc::create(this, callfunc_selector(HelloWorld::action_character));
					character[i]->runAction(Sequence::create(player->ani_character(character[i], 2, player_color[i]), callback, NULL));
					//character[i]->runAction(player->ani_character(character[i], 2, player_color[i]));
					time_line[i]->gotoFrameAndPlay(0, 24, true);
				}
				else if (i == 2) {
					character[i]->runAction(player->ani_character(character[i], 0, player_color[i]));
					time_line[i]->gotoFrameAndPlay(0, 0, false);
				}
				else {
					character[i]->runAction(player->ani_character(character[i], 1, player_color[i]));
					time_line[i]->gotoFrameAndPlay(0, 0, false);
				}
			}
			break;
		case Widget::TouchEventType::CANCELED:
			break;
		default:break;
		}
	}
}
void HelloWorld::bt_character_event_right(Ref *pSender, Widget::TouchEventType type)
{
	if (ch_action) {
		switch (type)
		{
		case Widget::TouchEventType::BEGAN:
			break;
		case Widget::TouchEventType::MOVED:
			break;
		case Widget::TouchEventType::ENDED:
			ch_action = false;
			get_number--;
			get_number = get_number % 4;
			player_color[4] = player_color[3];
			character[4] = character[3];
			time_line[4] = time_line[3];
			for (int i = 3; i >= 0; i--) {
				if (i > 0) {
					player_color[i] = player_color[i - 1];
					character[i] = character[i - 1];
					time_line[i] = time_line[i - 1];
				}
				else {
					player_color[i] = player_color[4];
					character[i] = character[4];
					time_line[i] = time_line[4];
				}
			}
			character[4] = NULL; player_color[4] = Color3B(0, 0, 0); time_line[4] = NULL;
			for (int i = 3; i >= 0; i--) {
				auto MoveAction = cocos2d::MoveTo::create(0.1f, pt[i]);
				character[i]->runAction(MoveAction);
			}
			for (int i = 3; i >= 0; i--) {
				if (i == 0) {
					auto callback = CallFunc::create(this, callfunc_selector(HelloWorld::action_character));
					character[i]->runAction(Sequence::create(player->ani_character(character[i], 2, player_color[i]), callback, NULL));
					time_line[i]->gotoFrameAndPlay(0, 24, true);
				}
				else if (i == 2) {
					character[i]->runAction(player->ani_character(character[i], 0, player_color[i]));
					time_line[i]->gotoFrameAndPlay(0, 0, false);
				}
				else {
					character[i]->runAction(player->ani_character(character[i], 1, player_color[i]));
					time_line[i]->gotoFrameAndPlay(0, 0, false);
				}
			}
			break;
		case Widget::TouchEventType::CANCELED:
			break;
		default: break;
		}
	}
}
void HelloWorld::bt_level_event_left(Ref *pSender, Widget::TouchEventType type)
{
	switch (type)
	{
	case Widget::TouchEventType::BEGAN:
		number_level++;
		if (number_level >= 2)number_level = 2;
		break;
	case Widget::TouchEventType::MOVED:
		break;
	case Widget::TouchEventType::ENDED:
		for (int i = 0; i < 3; i++) {
			if (i == number_level)
				difficulty_text->setText(diff[i]);
		}
		break;
	case Widget::TouchEventType::CANCELED:
		break;
	default:
		break;
	}
}
void HelloWorld::bt_level_event_right(Ref *pSender, Widget::TouchEventType type)
{
	switch (type)
	{
	case Widget::TouchEventType::BEGAN:
		number_level--;
		if (number_level <= 0)number_level = 0;
		break;
	case Widget::TouchEventType::MOVED:
		break;
	case Widget::TouchEventType::ENDED:
		for (int i = 0; i < 3; i++) {
			if (i == number_level)
				difficulty_text->setText(diff[i]);
		}
		break;
	case Widget::TouchEventType::CANCELED:
		break;
	default:
		break;
	}
}
bool  HelloWorld::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)//觸碰開始事件
{
	Point touchLoc = pTouch->getLocation();
	return true;
}
void  HelloWorld::onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) //觸碰移動事件
{
	Point touchLoc = pTouch->getLocation();
}
void  HelloWorld::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) //觸碰結束事件 
{
	Point touchLoc = pTouch->getLocation();
}
void HelloWorld::action_character()
{
	// do something on complete
	CCLOG("action completed!");
	ch_action = true;
}