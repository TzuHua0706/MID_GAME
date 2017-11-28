#pragma once

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "ui/UIWidget.h"

#include "basic.h"

class C3SButton
{
private:
public:
	C3SButton(const char * normal, const char * touched, const char * disable, bool method);
	~C3SButton();

	const char * Normal;
	const char * Disable;
	const char * Touched;
	bool Method;
	bool touch_flag;
	cocos2d::Rect rect_btn;
	cocos2d::Sprite * img_btn;
	cocos2d::Rect getrect();
	void touch();
	void end();
};
