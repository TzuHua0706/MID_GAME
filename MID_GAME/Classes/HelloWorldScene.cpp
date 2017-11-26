#include "HelloWorldScene.h"
#include "GameScene.h"
#include "SettingScene.h"

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
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	helloscene = CSLoader::createNode("MainScene.csb");
	addChild(helloscene);

	//Music
	bkmusic = (cocostudio::ComAudio *)helloscene->getChildByName("music_bg")->getComponent("music_bg");
	bkmusic->playBackgroundMusic();

	//Music Button
	btn_music = dynamic_cast<Button*>(helloscene->getChildByName("Button_music"));
	btn_music->addTouchEventListener(CC_CALLBACK_2(HelloWorld::bt_music_event, this));

	//Play Button
	btn_play = dynamic_cast<Button*>(helloscene->getChildByName("Button_play"));
	btn_play->addTouchEventListener(CC_CALLBACK_2(HelloWorld::bt_play_event, this));

	//Animation
	auto dancer = (ActionTimeline *)CSLoader::createTimeline("MainScene.csb");
	helloscene->runAction(dancer);
	dancer->gotoFrameAndPlay(0, 72, true);

	//Character Button left
	btn_character_left = dynamic_cast<Button*>(helloscene->getChildByName("Button_left"));
	btn_character_left->addTouchEventListener(CC_CALLBACK_2(HelloWorld::bt_character_event_left, this));
	//Character Button right
	btn_character_right = dynamic_cast<Button*>(helloscene->getChildByName("Button_right"));
	btn_character_right->addTouchEventListener(CC_CALLBACK_2(HelloWorld::bt_character_event_right, this));

	//Level Botton
	btn_level_left = new C3SButton("next.png","next_t.png","next_n.png",true);
	btn_level_left->img_btn->setPosition(510, 130);
	btn_level_left->img_btn->setScale(0.7);
	helloscene->addChild(btn_level_left->img_btn);

	btn_level_right = new C3SButton("next.png", "next_t.png", "next_n.png", true); 
	btn_level_right->img_btn->setPosition(770, 130);
	btn_level_right->img_btn->setScale(0.7);
	btn_level_right->img_btn->setRotation(180);
	helloscene->addChild(btn_level_right->img_btn);

	//Setting Botton
	btn_setting = new C3SButton("setting.png", "setting_t.png", "setting.png", true);
	btn_setting->img_btn->setPosition(1235, 680);
	btn_setting->img_btn->setScale(0.8);
	helloscene->addChild(btn_setting->img_btn);

	//Text
	difficulty_text = (cocos2d::ui::Text *)helloscene->getChildByName("difficulty");

	//Character
	player[0] = new C_character(RUN_1, Color3B(110, 210, 255));
	player[1] = new C_character(RUN_2, Color3B(255, 100, 100));
	player[2] = new C_character(RUN_3, Color3B(124, 255, 144));
	player[3] = new C_character(RUN_4, Color3B(255, 249, 137));
	player[4] = NULL;

	player[3]->character->setPosition(330, 317);
	helloscene->addChild(player[3]->set_character(false));
	player[2]->character->setPosition(640, 360);
	helloscene->addChild(player[2]->set_character(false));
	player[1]->character->setPosition(950, 317);
	helloscene->addChild(player[1]->set_character(false));
	player[0]->character->setPosition(640, 340);
	helloscene->addChild(player[0]->set_character(true));

	//Character Position
	for (int i = 0; i < 4; i++)
		pt[i] = player[i]->character->getPosition();

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
		removeAllChildren();
		Scene * scene = Scene::create();
		GameScene * layer = GameScene::create();
		layer->get_character(player[0], (level + 2)*0.5);
		scene->addChild(layer);
		Director::sharedDirector()->replaceScene(TransitionFade::create(0.5f, scene));
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
			player[4] = player[0];
			for (int i = 0; i < 5; i++) {
				if (i < 4) {
					player[i] = player[i + 1];
				}
				else {
					player[i] = NULL;
				}
			}
			for (int i = 3; i >= 0; i--) {
				auto MoveAction = cocos2d::MoveTo::create(0.1f, pt[i]);
				player[i]->character->runAction(MoveAction);
				if (i == 0) {
					auto callback = CallFunc::create(this, callfunc_selector(HelloWorld::action_character));
					player[i]->character->runAction(Sequence::create(player[i]->ani_character(i), callback, NULL));
				}
				else if (i == 2) {
					player[i]->character->runAction(player[i]->ani_character(i));
				}
				else {
					player[i]->character->runAction(player[i]->ani_character(1));
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
			player[4] = player[3];
			for (int i = 3; i >= 0; i--) {
				if (i > 0) {
					player[i] = player[i - 1];
				}
				else {
					player[i] = player[4];
				}
			}
			player[4] = NULL;
			for (int i = 3; i >= 0; i--) {
				auto MoveAction = cocos2d::MoveTo::create(0.1f, pt[i]);
				player[i]->character->runAction(MoveAction);
				if (i == 0) {
					auto callback = CallFunc::create(this, callfunc_selector(HelloWorld::action_character));
					player[i]->character->runAction(Sequence::create(player[i]->ani_character(i), callback, NULL));
				}
				else if (i == 2) {
					player[i]->character->runAction(player[i]->ani_character(i));
				}
				else {
					player[i]->character->runAction(player[i]->ani_character(1));
				}
			}
			break;
		case Widget::TouchEventType::CANCELED:
			break;
		default: break;
		}
	}
}
bool  HelloWorld::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)//觸碰開始事件
{
	Point touchLoc = pTouch->getLocation();
	if (btn_setting->get_rect().containsPoint(touchLoc)) {
		btn_setting->touch();
		setting_touch = true;
	}
	if (btn_level_left->get_rect().containsPoint(touchLoc)) {
		btn_level_left->touch();
		level_left_touch = true;
	}
	if (btn_level_right->get_rect().containsPoint(touchLoc)) {
		btn_level_right->touch();
		level_right_touch = true;
	}
	return true;
}
void  HelloWorld::onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) //觸碰移動事件
{
	Point touchLoc = pTouch->getLocation();
}
void  HelloWorld::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) //觸碰結束事件 
{
	Point touchLoc = pTouch->getLocation();
	if (setting_touch) {
		setting_touch = false;
		RenderTexture *renderTexture = RenderTexture::create(visibleSize.width, visibleSize.height);
		renderTexture->begin();
		this->getParent()->visit();
		renderTexture->end();
		Scene * scene = Scene::create();
		SettingScene * layer = SettingScene::create();
		layer->get_bg(renderTexture);
		scene->addChild(layer);
		Director::sharedDirector()->pushScene(scene);
	}
	if (level_left_touch) {
		level_left_touch = false;
		level++;
		if (level >= 2) {
			level = 2;
			/*btn_level_left->img_btn->setSpriteFrame(btn_level_left->Disable);
			btn_level_left->Method = false;*/
		}
		/*else if (level > 0) {
		btn_level_right->img_btn->setSpriteFrame(btn_level_left->Normal);
		btn_level_right->Method = true;
		}*/
		for (int i = 0; i < 3; i++) {
			if (i == level)
				difficulty_text->setText(diff[i]);
		}
	}
	if (level_right_touch) {
		level_right_touch = false;
		level--;
		if (level <= 0) {
			level = 0;
			/*btn_level_right->img_btn->setSpriteFrame(btn_level_right->Disable);
			btn_level_right->Method = false;*/
		}
		/*else if (level < 2) {
		btn_level_left->img_btn->setSpriteFrame(btn_level_left->Normal);
		btn_level_left->Method = true;
		}*/
		for (int i = 0; i < 3; i++) {
			if (i == level)
				difficulty_text->setText(diff[i]);
		}
	}
}
void HelloWorld::action_character()
{
	ch_action = true;
}