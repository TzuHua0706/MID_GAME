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
	delete btn_level_left;
	delete btn_level_right;
	delete btn_setting;
	delete btn_play;
	delete btn_character_left;
	delete btn_character_right;
	delete btn_music;
	//delete[] player;
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
	bkvolume = bkmusic->getBackgroundMusicVolume(); 

	//Animation
	auto dancer = (ActionTimeline *)CSLoader::createTimeline("MainScene.csb");
	helloscene->runAction(dancer);
	dancer->gotoFrameAndPlay(0, 72, true);

	//Music Button
	btn_music = new C3SButton("music.png", "music_t.png", "music_n.png", true); //music_n不是禁用，第三種圖
	btn_music->img_btn->setPosition(45, 680);
	btn_music->img_btn->setScale(0.8f);
	helloscene->addChild(btn_music->img_btn);

	//Character Button left
	btn_character_left = new C3SButton("next.png", "next_t.png", "next_n.png", true); //music_n不是禁用
	btn_character_left->img_btn->setPosition(200, 306);
	helloscene->addChild(btn_character_left->img_btn);
	//Character Button right
	btn_character_right = new C3SButton("next.png", "next_t.png", "next_n.png", true); //music_n不是禁用
	btn_character_right->img_btn->setPosition(1080, 306);
	btn_character_right->img_btn->setRotation(180);
	helloscene->addChild(btn_character_right->img_btn);

	//Play Button
	btn_play = new C3SButton("start.png", "start_t.png", "start.png", true);
	btn_play->img_btn->setPosition(1100, 80);
	helloscene->addChild(btn_play->img_btn);

	//Level Botton
	btn_level_left = new C3SButton("next.png","next_t.png","next_n.png",true);
	btn_level_left->img_btn->setPosition(510, 130);
	btn_level_left->img_btn->setScale(0.7f);
	helloscene->addChild(btn_level_left->img_btn);
	btn_level_right = new C3SButton("next.png", "next_t.png", "next_n.png", true); 
	btn_level_right->img_btn->setPosition(770, 130);
	btn_level_right->img_btn->setScale(0.7f);
	btn_level_right->img_btn->setRotation(180);
	helloscene->addChild(btn_level_right->img_btn);

	//Setting Botton
	btn_setting = new C3SButton("setting.png", "setting_t.png", "setting.png", true);
	btn_setting->img_btn->setPosition(1235, 680);
	btn_setting->img_btn->setScale(0.8f);
	helloscene->addChild(btn_setting->img_btn);

	//Text
	difficulty_text = (cocos2d::ui::Text *)helloscene->getChildByName("difficulty");

	//Character
	player[0] = new C_character(RUN_1, Color3B(110, 210, 255));
	player[0]->set_character(true);
	player[1] = new C_character(RUN_2, Color3B(255, 100, 100));
	player[1]->set_character(false);
	player[2] = new C_character(RUN_3, Color3B(124, 255, 144));
	player[2]->set_character(false);
	player[3] = new C_character(RUN_4, Color3B(255, 249, 137));
	player[3]->set_character(false);
	player[4] = new C_character(RUN_1, Color3B(110, 210, 255));

	player[3]->character->setPosition(330, 317);
	helloscene->addChild(player[3]->character);
	player[2]->character->setPosition(640, 360);
	helloscene->addChild(player[2]->character);
	player[1]->character->setPosition(950, 317);
	helloscene->addChild(player[1]->character);
	player[0]->character->setPosition(640, 340);
	helloscene->addChild(player[0]->character);

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
	if (play_flag) {
		bkvolume = bkmusic->getBackgroundMusicVolume();
		if (!bkvolume) { btn_music->img_btn->setSpriteFrame(btn_music->Disable); music_open = false; }
		else { btn_music->img_btn->setSpriteFrame(btn_music->Normal); music_open = true; }
	}
}
bool  HelloWorld::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)//觸碰開始事件
{
	Point touchLoc = pTouch->getLocation();
	if (btn_music->getrect().containsPoint(touchLoc)) {
		btn_music->touch();
	}
	if (btn_setting->getrect().containsPoint(touchLoc)) {
		btn_setting->touch();
	}
	if (btn_character_left->getrect().containsPoint(touchLoc)) {
		btn_character_left->touch();
	}
	if (btn_character_right->getrect().containsPoint(touchLoc)) {
		btn_character_right->touch();
	}
	if (btn_level_left->getrect().containsPoint(touchLoc)) {
		btn_level_left->touch();
	}
	if (btn_level_right->getrect().containsPoint(touchLoc)) {
		btn_level_right->touch();
	}
	if (btn_play->getrect().containsPoint(touchLoc)) {
		play_flag = false;
		btn_play->touch();
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
	if (btn_music->touch_flag) {
		btn_music->end();
		music_open = !music_open;
		if (!music_open) {
			bkmusic->setBackgroundMusicVolume(0);
			btn_music->img_btn->setSpriteFrame(btn_music->Disable);
		}
		else {
			if (!bkvolume) bkvolume = 0.5;
			bkmusic->setBackgroundMusicVolume(bkvolume);
			btn_music->img_btn->setSpriteFrame(btn_music->Normal);
		}
	}
	if (btn_setting->touch_flag) {
		btn_setting->end();
		bkvolume = bkmusic->getBackgroundMusicVolume();
		RenderTexture *renderTexture = RenderTexture::create(visibleSize.width, visibleSize.height);
		renderTexture->begin();
		this->getParent()->visit();
		renderTexture->end();
		Scene * scene = Scene::create();
		SettingScene * layer = SettingScene::create();
		layer->get_bg(renderTexture);
		layer->get_slider(bkvolume);
		scene->addChild(layer);
		Director::sharedDirector()->pushScene(scene);
	}
	if (btn_character_left->touch_flag && player[0]->ch_action) {
		btn_character_left->end();
		player[4] = player[0];
		for (int i = 0; i < 5; i++) {
			if (i < 4) {
				player[i] = player[i + 1];
			}
		}
		for (int i = 3; i >= 0; i--) {
			auto MoveAction = cocos2d::MoveTo::create(0.1f, pt[i]);
			player[i]->character->runAction(MoveAction);
			if (i == 0){
				player[i]->ani_character(0);
			}
			else if (i == 2) {
				player[i]->ani_character(2);
			}
			else {
				player[i]->ani_character(1);
			}
		}
	}
	if (btn_character_right->touch_flag && player[0]->ch_action) {
		btn_character_right->end();
		player[4] = player[3];
		for (int i = 3; i >= 0; i--) {
			if (i > 0) {
				player[i] = player[i - 1];
			}
			else {
				player[i] = player[4];
			}
		}
		for (int i = 3; i >= 0; i--) {
			auto MoveAction = cocos2d::MoveTo::create(0.1f, pt[i]);
			player[i]->character->runAction(MoveAction);
			if (i == 0) {
				player[i]->ani_character(0);
			}
			else if (i == 2) {
				player[i]->ani_character(2);
			}
			else {
				player[i]->ani_character(1);
			}
		}
	}
	if (btn_level_left->touch_flag) {
		btn_level_left->end();
		level++;
		if (level >= 2) {
			level = 2;
			btn_level_left->img_btn->setSpriteFrame(btn_level_left->Disable);
			btn_level_left->Method = false;
		}
		else if (level > 0) {
		btn_level_right->img_btn->setSpriteFrame(btn_level_left->Normal);
		btn_level_right->Method = true;
		}
		for (int i = 0; i < 3; i++) {
			if (i == level)
				difficulty_text->setText(diff[i]);
		}
	}
	if (btn_level_right->touch_flag) {
		btn_level_right->end();
		level--;
		if (level <= 0) {
			level = 0;
			btn_level_right->img_btn->setSpriteFrame(btn_level_right->Disable);
			btn_level_right->Method = false;
		}
		else if (level < 2) {
		btn_level_left->img_btn->setSpriteFrame(btn_level_left->Normal);
		btn_level_left->Method = true;
		}
		for (int i = 0; i < 3; i++) {
			if (i == level)
				difficulty_text->setText(diff[i]);
		}
	}
	if (btn_play->touch_flag) {
		btn_play->end();
		removeAllChildren();
		Scene * scene = Scene::create();
		GameScene * layer = GameScene::create();
		layer->get_character(player[0], (level + 2)*0.5, bkvolume);
		scene->addChild(layer);
		Director::sharedDirector()->replaceScene(TransitionFade::create(0.5f, scene));
	}
}