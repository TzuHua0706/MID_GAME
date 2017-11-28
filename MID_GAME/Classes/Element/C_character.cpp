#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "C_character.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace ui;
using namespace CocosDenshion;

C_character::C_character(const char * player, cocos2d::Color3B color) {
	Player = player;
	Color = color;
	character = CSLoader::createNode(Player);
	shadow = character->getChildByName("shadow");
	body = character->getChildByName("player");
	sad = character->getChildByName("sad");
	happy = character->getChildByName("happy");
	normal = character->getChildByName("normal");
	ac_character = (ActionTimeline *)CSLoader::createTimeline(Player);
	SimpleAudioEngine::getInstance()->preloadEffect("thinking cloud.mp3");// 預先載入音效檔
}
C_character::~C_character() {
	SimpleAudioEngine::getInstance()->unloadEffect("thinking cloud.mp3");
}
cocos2d::Node * C_character::set_character(bool select) {
	sad->setVisible(false);
	happy->setVisible(false);
	character->runAction(ac_character);
	if (select) {
		character->setScale(1.0f);
		body->setColor(Color);
		shadow->setVisible(true);
		normal->setVisible(true);
		ac_character->gotoFrameAndPlay(0, 24, true);
	}
	//small
	else {
		character->setScale(0.7f);
		body->setColor(Color3B(115, 115, 115));
		shadow->setVisible(false);
		normal->setVisible(false);
		ac_character->gotoFrameAndPlay(0, 0, false);
	}
	return(character);
}
cocos2d::Spawn * C_character::ani_character(int scale)//scale  2最小 1中間 0最大
{
	sad->setVisible(false);
	happy->setVisible(false);
	if (!scale) {
		auto ScaleAction = cocos2d::ScaleTo::create(0.1f, 1);
		auto FadeAction = cocos2d::FadeIn::create(0.1f);
		auto chAction = Spawn::createWithTwoActions(ScaleAction, FadeAction);
		body->setColor(Color);
		shadow->setVisible(true);
		normal->setVisible(true);
		ac_character->gotoFrameAndPlay(0, 24, true);
		return(chAction);
	}
	else {
		body->setColor(Color3B(115, 115, 115));
		shadow->setVisible(false);
		normal->setVisible(false);
		ac_character->gotoFrameAndPlay(0, 0, false);
		if (scale == 1) {
			auto ScaleAction = cocos2d::ScaleTo::create(0.1f, 0.7f);
			auto FadeAction = cocos2d::FadeIn::create(0.1f);
			auto chAction = Spawn::createWithTwoActions(ScaleAction, FadeAction);
			return(chAction);
		}
		else {
			auto ScaleAction = cocos2d::ScaleTo::create(0.1f, 0.3f); 
			auto FadeAction = cocos2d::FadeOut::create(0.1f);
			auto chAction = Spawn::createWithTwoActions(ScaleAction, FadeAction);
			return(chAction);
		}
	}
}
cocos2d::EaseOut * C_character::jump() {
	//Animation jump
	unsigned int eid = SimpleAudioEngine::getInstance()->playEffect("thinking cloud.mp3");
	auto body_jumpAction = cocos2d::JumpTo::create(0.7f, body->getPosition(), 280, 1);
	auto body_jumpSineIn = EaseOut::create(body_jumpAction, 1); 
	if (normal) {
		auto face_jumpAction = cocos2d::JumpTo::create(0.7f, normal->getPosition(), 280, 1);
		auto face_jumpSineIn = EaseOut::create(face_jumpAction, 1);
		normal->runAction(face_jumpSineIn);
	}
	if (sad) {
		auto face_jumpAction = cocos2d::JumpTo::create(0.7f, sad->getPosition(), 280, 1);
		auto face_jumpSineIn = EaseOut::create(face_jumpAction, 1);
		sad->runAction(face_jumpSineIn);
	}
	if (happy) {
		auto face_jumpAction = cocos2d::JumpTo::create(0.7f, happy->getPosition(), 280, 1);
		auto face_jumpSineIn = EaseOut::create(face_jumpAction, 1);
		happy->runAction(face_jumpSineIn);
	}
	ScaleBy * scaleby = ScaleBy::create(0.35f, 0.5f);
	auto scalebyBack = scaleby->reverse();
	auto sequence = Sequence::create(scaleby, scalebyBack, NULL);
	shadow->runAction(sequence);
	return(body_jumpSineIn);
}
void C_character::face_character(int face) {//face 0:normal 1:happy 2:sad
	if (face == 0) {
		normal->setVisible(true);
		sad->setVisible(false);
		happy->setVisible(false);
	}
	else if (face == 1) {
		normal->setVisible(false);
		sad->setVisible(false);
		happy->setVisible(true);
	}
	else {
		normal->setVisible(false);
		sad->setVisible(true);
		happy->setVisible(false);
	}
}