#pragma once

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "ui/UIWidget.h"
#include "SimpleAudioEngine.h"

#include "basic.h"
#include "./Element/character.h"
#include "./Element/CObstacle.h"

class GameScene : public cocos2d::Layer
{
private:

public:
	GameScene();
	~GameScene();

	character * ch;
	CObstacle * g_obstacle;

	cocos2d::Node * gamescene;
	cocos2d::Node * character;
	cocos2d::Node * obstacle;
	cocostudio::ComAudio * bkmusic;
	cocos2d::ui::Button * btn_music;
	cocos2d::ui::Button * btn_home;
	cocos2d::Rect jump;
	cocos2d::Rect rect_ch;
	cocos2d::Rect rect_ob;

	bool jump_flag = true;
	bool scene_btn = true;
	bool music_open = true;
	float ob_time = 0;
	float fin_time = 0;
	char animation_character[NUMBER][25] = { RUN_1, RUN_2, RUN_3, RUN_4 };

	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();
	void doStep(float dt);

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	void actionFinished();
	void get_character(unsigned int number, cocos2d::Color3B color);
	void bt_music_event(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
	void bt_home_event(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);

	//觸碰
	cocos2d::EventListenerTouchOneByOne *_listener1;
	bool onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰開始事件
	void onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰移動事件
	void onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰結束事件 

	CREATE_FUNC(GameScene);
};