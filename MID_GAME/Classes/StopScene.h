#pragma once

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "ui/UIWidget.h"

#include "./Element/C_character.h"
#include "./Element/C3SButton.h"
#include "basic.h"

class StopScene : public cocos2d::Layer
{
private:
	C3SButton * btn_play;
	C3SButton * btn_replay;
	C3SButton * btn_home;
	C_character * C_Player;
	float Level = 0;
	bool play_touch = false;
	bool replay_touch = false;
	bool home_touch = false;
	bool stop_flag = true;
public:
	StopScene();
	~StopScene();

	virtual bool init();

	void get_character(C_character * player, float get_level, cocos2d::RenderTexture* sc);

	//觸碰
	cocos2d::EventListenerTouchOneByOne *_listener1;
	bool onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰開始事件
	void onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰移動事件
	void onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰結束事件 

	CREATE_FUNC(StopScene);
};