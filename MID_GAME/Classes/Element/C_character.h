#pragma once

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "ui/UIWidget.h"

#include "basic.h"

class C_character : public cocos2d::Node
{
private:
public:
	C_character(const char * player, cocos2d::Color3B color);
	~C_character();

	bool music_open = true;
	bool ch_action = true;
	bool jump_flag = true;
	bool R_flag = true;
	unsigned int eid;
	const char * Player;
	cocos2d::Color3B Color;
	cocos2d::Node * character;
	cocos2d::Node * shadow;
	cocos2d::Node * body;
	cocos2d::Node * sad;
	cocos2d::Node * happy;
	cocos2d::Node * normal;
	cocos2d::Node * sad_eye;
	cocostudio::timeline::ActionTimeline * ac_character;

	void set_character(bool select);
	void ani_character(int scale);//scale  2最小 1中間 0最大
	void action_character();
	void jump(float Volume);
	void jumpFinished();
	void RFinished();
	void face_character(int face);//face 0:normal 1:happy 2:sad

};
