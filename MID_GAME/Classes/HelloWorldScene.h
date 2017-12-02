#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "ui/UIWidget.h"

#include "basic.h"
#include "./Element/C_character.h"
#include "./Element/C3SButton.h"

class HelloWorld : public cocos2d::Layer
{
private:
	C3SButton * btn_level_left;
	C3SButton * btn_level_right;
	C3SButton * btn_setting;
	C3SButton * btn_play;
	C3SButton * btn_character_left;
	C3SButton * btn_character_right;
	C_character * player[5];
public:
	HelloWorld();
	~HelloWorld();

	C3SButton * btn_music;
	cocos2d::Point pt[4];
	cocos2d::Vec2 origin;
	cocos2d::Size visibleSize;
	cocos2d::Node * helloscene;
	cocos2d::ui::Text * difficulty_text;
	cocostudio::ComAudio * bkmusic;

	//bool ch_action = true;
	bool play_flag = true;
	bool music_open = true;
	char diff[3][10] = { "Difficult","Normal","Easy" }; //Level
	int level = 1;
	float bkvolume;

	//void action_character();

	//button
	static cocos2d::Scene* createScene();
	void doStep(float dt); 

	virtual bool init();

	//觸碰
	cocos2d::EventListenerTouchOneByOne *_listener1;
	bool onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰開始事件
	void onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰移動事件
	void onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰結束事件 

	CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__