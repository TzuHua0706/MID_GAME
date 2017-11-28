#pragma once

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "ui/UIWidget.h"

#include "basic.h"

class C_character
{
private:
public:
	C_character(const char * player, cocos2d::Color3B color);
	~C_character();

	const char * Player;
	cocos2d::Color3B Color;
	cocos2d::Node * character;
	cocos2d::Node * shadow;
	cocos2d::Node * body;
	cocos2d::Node * sad;
	cocos2d::Node * happy;
	cocos2d::Node * normal;
	cocostudio::timeline::ActionTimeline * ac_character;

	cocos2d::Node * set_character(bool select);
	cocos2d::Spawn * ani_character(int scale);//scale  2最小 1中間 0最大
	cocos2d::EaseOut * jump();
	void face_character(int face);//face 0:normal 1:happy 2:sad

};
