#pragma once

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "ui/UIWidget.h"

#include "./Element/C3SButton.h"
#include "basic.h"

class SettingScene : public cocos2d::Layer
{
private:
	C3SButton * btn_x;
public:
	SettingScene();
	~SettingScene();

	virtual bool init();

	void get_bg(cocos2d::RenderTexture* sc);
	void sliderEvent(cocos2d::Ref* sender, cocos2d::ui::Slider::EventType type);

	//觸碰
	cocos2d::EventListenerTouchOneByOne *_listener1;
	bool onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰開始事件
	void onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰移動事件
	void onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰結束事件 

	CREATE_FUNC(SettingScene);
};