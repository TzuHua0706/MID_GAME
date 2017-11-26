#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "C3SButton.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace ui;

C3SButton::C3SButton(char * normal, char * touched, char * disable, bool method) {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/new icon.plist");
	Normal = normal;
	Touched = touched;
	Disable = disable;
	Method = method;
	if (Method) {
		img_btn = Sprite::createWithSpriteFrameName(Normal);
	}
	else {
		img_btn = Sprite::createWithSpriteFrameName(Disable);
	}
}
C3SButton::~C3SButton() {
}
cocos2d::Rect C3SButton::getrect() {
	if (Method) { 
		Size s_btn = img_btn->getContentSize();
		Point p_btn = img_btn->getPosition();
		rect_btn = Rect(p_btn.x - s_btn.width / 2, p_btn.y - s_btn.height / 2, s_btn.width, s_btn.height);
		return(rect_btn);
	}
}
void C3SButton::touch() {
	if (Method) {
		img_btn->setSpriteFrame(Touched);
	}
}
void C3SButton::end() {
	if (Method) {
		img_btn->setSpriteFrame(Normal);
	}
}