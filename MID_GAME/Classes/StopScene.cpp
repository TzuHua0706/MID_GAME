#include "GameScene.h"
#include "HelloWorldScene.h"
#include "StopScene.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace ui;

StopScene::StopScene(){}
StopScene::~StopScene(){
	removeAllChildren();
}
bool StopScene::init()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	if (!Layer::init())
	{
		return false;
	}

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/new icon.plist");

	btn_play = new C3SButton("play.png", "play_t.png", "play.png",true);
	btn_play->img_btn->setPosition(455, 360);
	this->addChild(btn_play->img_btn, 2);

	btn_replay = new C3SButton("replay.png", "replay_t.png", "replay.png", true);
	btn_replay->img_btn->setPosition(620, 360);
	this->addChild(btn_replay->img_btn, 2);

	btn_home = new C3SButton("home.png", "home_t.png", "home.png", true);
	btn_home->img_btn->setPosition(785, 360);
	this->addChild(btn_home->img_btn, 2);

	//Touch
	_listener1 = EventListenerTouchOneByOne::create();
	_listener1->onTouchBegan = CC_CALLBACK_2(StopScene::onTouchBegan, this);
	_listener1->onTouchMoved = CC_CALLBACK_2(StopScene::onTouchMoved, this);
	_listener1->onTouchEnded = CC_CALLBACK_2(StopScene::onTouchEnded, this);

	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener1, this);	//加入剛創建的事件聆聽器

	return true;
}
void StopScene::get_character(C_character * player, float get_level, RenderTexture* sc) {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Sprite * bg = Sprite::createWithTexture(sc->getSprite()->getTexture());
	bg->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	bg->setFlipY(true);
	bg->setColor(Color3B(115, 115, 115));
	this->addChild(bg);
	C_Player = new C_character(player->Player, player->Color);
	Level = get_level;
}
bool StopScene::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)//觸碰開始事件
{
	Point touchLoc = pTouch->getLocation();
	if (btn_play->get_rect().containsPoint(touchLoc)) {
		btn_play->touch();
		play_touch = true;
	}
	if (btn_replay->get_rect().containsPoint(touchLoc)) {
		btn_replay->touch();
		replay_touch = true;
	}
	if (btn_home->get_rect().containsPoint(touchLoc)) {
		btn_home->touch();
		home_touch = true;
	}
	return true;
}
void StopScene::onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) //觸碰移動事件
{
	Point touchLoc = pTouch->getLocation();
}
void StopScene::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) //觸碰結束事件 
{
	Point touchLoc = pTouch->getLocation();
	if(play_touch){
		play_touch = false;
		GameScene * layer = GameScene::create();
		layer->bkmusic->playBackgroundMusic();
		Director::sharedDirector()->popScene();
	}
	if (replay_touch) {
		replay_touch = false;
		removeAllChildren();
		Scene * scene = Scene::create();
		GameScene * layer = GameScene::create();
		layer->get_character(C_Player, Level);
		scene->addChild(layer);
		Director::sharedDirector()->replaceScene(scene);
	}
	if (home_touch) {
		home_touch = false;
		removeAllChildren();
		Scene * scene = Scene::create();
		HelloWorld * layer = HelloWorld::create();
		scene->addChild(layer);
		Director::sharedDirector()->replaceScene(TransitionFade::create(0.5f, scene));
	}
}