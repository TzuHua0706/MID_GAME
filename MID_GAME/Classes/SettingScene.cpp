#include "HelloWorldScene.h"
#include "SettingScene.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocos2d::ui;
using namespace cocostudio::timeline;

SettingScene::SettingScene() {}
SettingScene::~SettingScene() {
	removeAllChildren();
	delete btn_x;
}
bool SettingScene::init()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	if (!Layer::init())
	{
		return false;
	}

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/new icon.plist");

	//背景
	Sprite * bg = Sprite::create("res/setting_bg.png");
	bg->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	bg->setOpacity(250);
	this->addChild(bg,1);

	auto text = Label::createWithTTF("Background Music", "fonts/Marker Felt.ttf", 24);
	text->setAlignment(cocos2d::TextHAlignment::CENTER);
	text->setColor(Color3B(204, 108, 106));
	text->setPosition(580, 560);
	this->addChild(text, 2);

	//Slider BGmusic
	slider_bkmusic = Slider::create();
	slider_bkmusic->loadBarTexture("scene101/sliderTrack.png");
	slider_bkmusic->loadProgressBarTexture("scene101/sliderProgress.png");
	slider_bkmusic->loadSlidBallTextures("scene101/sliderballnormal.png", "scene101/sliderballpressed.png", "scene101/sliderballnormal.png");
	slider_bkmusic->setPercent(100);
	slider_bkmusic->setColor(Color3B(118,206,184));
	slider_bkmusic->setPosition(Point(640, 530));
	slider_bkmusic->setScale(1.1);
	this->addChild(slider_bkmusic, 2);
	slider_bkmusic->addEventListener(CC_CALLBACK_2(SettingScene::sliderEvent, this));
	
	//X Button
	btn_x = new C3SButton("x.png", "x_t.png", "x.png", true);
	btn_x->img_btn->setPosition(795, 620);
	btn_x->img_btn->setScale(0.8f);
	this->addChild(btn_x->img_btn, 2);

	//Touch
	_listener1 = EventListenerTouchOneByOne::create();
	_listener1->onTouchBegan = CC_CALLBACK_2(SettingScene::onTouchBegan, this);
	_listener1->onTouchMoved = CC_CALLBACK_2(SettingScene::onTouchMoved, this);
	_listener1->onTouchEnded = CC_CALLBACK_2(SettingScene::onTouchEnded, this);

	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener1, this);	//加入剛創建的事件聆聽器

	return true;
}
void SettingScene::get_bg(RenderTexture* sc) {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Sprite * bg = Sprite::createWithTexture(sc->getSprite()->getTexture());
	bg->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	bg->setFlipY(true);
	bg->setColor(Color3B(115, 115, 115));
	this->addChild(bg);
}
void SettingScene::get_slider(float percent) {
	slider_bkmusic->setPercent(percent * 100);
}
void SettingScene::sliderEvent(cocos2d::Ref* sender, cocos2d::ui::Slider::EventType type) {
	m_percent = slider_bkmusic->getPercent();
}
bool SettingScene::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)//觸碰開始事件
{
	Point touchLoc = pTouch->getLocation();
	if (btn_x->getrect().containsPoint(touchLoc)) {
		btn_x->touch();
	}
	return true;
}
void SettingScene::onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) //觸碰移動事件
{
	Point touchLoc = pTouch->getLocation();
}
void SettingScene::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) //觸碰結束事件 
{
	Point touchLoc = pTouch->getLocation();
	if (btn_x->touch_flag) {
		btn_x->end();
		HelloWorld * layer = HelloWorld::create();
		layer->bkmusic->setBackgroundMusicVolume(m_percent*0.01);
		Director::sharedDirector()->popScene();
	}
}