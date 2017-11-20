#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "character.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace ui;

character::character() {}
character::~character() {}

cocos2d::Node * character::set_character(char * name, Color3B color, bool select) {
	auto character_name = CSLoader::createNode(name);
	auto shadow = character_name->getChildByName("shadow");
	auto body = character_name->getChildByName("player");
	auto sad = character_name->getChildByName("sad");
	auto happy = character_name->getChildByName("happy");
	auto normal = character_name->getChildByName("normal");
	if (select) {
		character_name->setScale(1);
		body->setColor(color);
		shadow->setVisible(true);
		normal->setVisible(true);
		sad->setVisible(false);
		happy->setVisible(false);
	}
	//small
	else {
		character_name->setScale(0.7);
		body->setColor(Color3B(115, 115, 115));
		shadow->setVisible(false);
		normal->setVisible(false);
		sad->setVisible(false);
		happy->setVisible(false);
	}
	return(character_name);
}
cocos2d::Spawn * character::ani_character(cocos2d::Node * player,int scale, cocos2d::Color3B color)//scale  0最小 1中間 2最大
{
	auto shadow = player->getChildByName("shadow");
	auto body = player->getChildByName("player");
	auto sad = player->getChildByName("sad");
	auto happy = player->getChildByName("happy");
	auto normal = player->getChildByName("normal");
	if (scale == 2) {
		auto ScaleAction = cocos2d::ScaleTo::create(0.1f, 1);
		auto FadeAction = cocos2d::FadeIn::create(0.1f);
		auto chAction = Spawn::createWithTwoActions(ScaleAction, FadeAction);
		body->setColor(color);
		shadow->setVisible(true);
		normal->setVisible(true);
		sad->setVisible(false);
		happy->setVisible(false);
		return(chAction);
	}
	else if (scale == 1) {
		auto ScaleAction = cocos2d::ScaleTo::create(0.1f, 0.7);
		auto FadeAction = cocos2d::FadeIn::create(0.1f);
		auto chAction = Spawn::createWithTwoActions(ScaleAction, FadeAction);
		body->setColor(Color3B(115, 115, 115));
		shadow->setVisible(false);
		normal->setVisible(false);
		sad->setVisible(false);
		happy->setVisible(false);
		return(chAction);
	}
	else {
		auto ScaleAction = cocos2d::ScaleTo::create(0.1f, 0.3);
		auto FadeAction = cocos2d::FadeOut::create(0.1f);
		auto chAction = Spawn::createWithTwoActions(ScaleAction, FadeAction);
		body->setColor(Color3B(115, 115, 115));
		shadow->setVisible(false);
		normal->setVisible(false);
		sad->setVisible(false);
		happy->setVisible(false);
		return(chAction);
	}
}
cocos2d::EaseOut * character::jump(cocos2d::Node * player) {
	auto shadow = player->getChildByName("shadow");
	auto body = player->getChildByName("player");
	auto face = player->getChildByName("normal");
	Point body_seat = body->getPosition();
	Point face_seat = face->getPosition();
	auto body_jumpAction = cocos2d::JumpTo::create(0.8f, body_seat, 280, 1);
	auto body_jumpSineIn = EaseOut::create(body_jumpAction, 1);
	auto face_jumpAction = cocos2d::JumpTo::create(0.8f, face_seat, 280, 1);
	auto face_jumpSineIn = EaseOut::create(face_jumpAction, 1);
	body->runAction(body_jumpSineIn);
	face->runAction(face_jumpSineIn);
	ScaleBy * scaleby = ScaleBy::create(0.4f, 0.5f);
	auto scalebyBack = scaleby->reverse();
	auto sequence = Sequence::create(scaleby, scalebyBack, NULL);
	shadow->runAction(sequence);

	return(body_jumpSineIn);
}