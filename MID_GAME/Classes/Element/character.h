#pragma once

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "ui/UIWidget.h"
#include "SimpleAudioEngine.h"
#include "basic.h"

class character
{
private:

public:
	character();
	~character();

	cocos2d::Node * set_character(char * name,cocos2d::Color3B color,bool select);
	cocos2d::Spawn * ani_character(cocos2d::Node * player, int scale, cocos2d::Color3B color);//scale  0最小 1中間 2最大
	cocos2d::EaseOut * jump(cocos2d::Node * player);

};
