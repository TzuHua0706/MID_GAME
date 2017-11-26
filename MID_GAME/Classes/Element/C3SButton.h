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
	C3SButton(char * normal, char * touched, char * disable, bool method);
	~C3SButton();

	char * Normal;
	char * Touched;
	char * Disable;
	bool Method;
	cocos2d::Rect rect_btn;
	cocos2d::Sprite * img_btn;
	cocos2d::Rect get_rect();
	void touch();
};
