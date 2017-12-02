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
	float bkvolume;
public:
	StopScene();
	~StopScene();

	virtual bool init();

	void get_character(C_character * player, float get_level, cocos2d::RenderTexture* sc, float volume);

	//Ĳ�I
	cocos2d::EventListenerTouchOneByOne *_listener1;
	bool onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //Ĳ�I�}�l�ƥ�
	void onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //Ĳ�I���ʨƥ�
	void onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //Ĳ�I�����ƥ� 

	CREATE_FUNC(StopScene);
};