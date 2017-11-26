#pragma once

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "ui/UIWidget.h"

#include "basic.h"
#include "./Element/C_character.h"
#include "./Element/C3SButton.h"

class HelloWorld : public cocos2d::Layer
{
private:
	C3SButton * btn_level_left;
	C3SButton * btn_level_right;
	C3SButton * btn_setting;
	C3SButton * btn_play;
	C_character * player[5];
public:
	HelloWorld();
	~HelloWorld();

	cocos2d::Point pt[4];
	cocos2d::Vec2 origin;
	cocos2d::Size visibleSize;
	cocos2d::Node * helloscene;
	cocos2d::ui::Text * difficulty_text;
	cocos2d::ui::Button * btn_character_left;
	cocos2d::ui::Button * btn_character_right;
	cocos2d::ui::Button * btn_music;
	cocostudio::ComAudio * bkmusic;

	bool level_left_touch = false;
	bool level_right_touch = false;
	bool setting_touch = false;
	bool play_touch = false;
	bool ch_action = true;
	bool music_open = true;
	char diff[3][10] = { "Difficult","Normal","Easy" }; //Level
	int level = 1;
	unsigned int get_number = 0;

	void action_character();

	//button
	void bt_character_event_left(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
	void bt_character_event_right(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
	void bt_music_event(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
	static cocos2d::Scene* createScene();
	void doStep(float dt);

	virtual bool init();

	//觸碰
	cocos2d::EventListenerTouchOneByOne *_listener1;
	bool onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰開始事件
	void onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰移動事件
	void onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰結束事件 

	CREATE_FUNC(HelloWorld);
};
