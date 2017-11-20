#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "ui/UIWidget.h"
#include "SimpleAudioEngine.h"

#include "basic.h"
#include "./Element/character.h"

class HelloWorld : public cocos2d::Layer
{
private:

public:
	HelloWorld();
	~HelloWorld();

	character * player;

	cocos2d::Point pt[4];
	cocostudio::ComAudio * bkmusic;
	cocos2d::Node * helloscene;
	cocos2d::Node * character[5];
	cocos2d::Color3B player_color[5];
	cocos2d::ui::Text * difficulty_text;
	cocos2d::ui::Button * btn_character_left;
	cocos2d::ui::Button * btn_character_right;
	cocos2d::ui::Button * btn_level_left;
	cocos2d::ui::Button * btn_level_right;
	cocos2d::ui::Button * btn_music;
	cocos2d::ui::Button * btn_play;
	cocostudio::timeline::ActionTimeline * time_line[5];

	bool ch_action = true;
	bool scene_btn = true;
	bool music_open = true;
	char diff[3][10] = { "Difficult","Normal","Easy" }; //Level
	char run_character[5][25] = { RUN_1, RUN_2, RUN_3, RUN_4, NULL }; //跑步人字串
	int number_level = 1;
	unsigned int get_number = 0;

	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();
	void doStep(float dt);

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();
	//virtual void setVisible(bool visible);

	void action_character();

	//button
	void bt_character_event_left(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
	void bt_character_event_right(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
	void bt_level_event_left(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
	void bt_level_event_right(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
	void bt_music_event(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
	void bt_play_event(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);

	//觸碰
	cocos2d::EventListenerTouchOneByOne *_listener1;
	bool onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰開始事件
	void onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰移動事件
	void onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰結束事件 

																	   // implement the "static create()" method manually
	CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
