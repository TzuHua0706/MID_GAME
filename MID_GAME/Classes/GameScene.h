#pragma once

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "ui/UIWidget.h"

#include "basic.h"
#include "./Element/C_character.h"
#include "./Element/C3SButton.h"
#include "./Element/CObstacle.h"

class GameScene : public cocos2d::Layer
{
private:
	CObstacle * g_obstacle[3] = { NULL,NULL,NULL };
	C_character * C_player;
	C3SButton * btn_stop;
public:
	GameScene();
	~GameScene();

	cocos2d::Node * gamescene;
	cocostudio::ComAudio * bkmusic;
	cocos2d::ui::Text * score_text;
	cocos2d::ui::Button * btn_music;
	cocos2d::ui::LoadingBar * blood;
	cocos2d::Rect jump;
	cocos2d::Rect rect_ch;
	cocos2d::Vec2 origin;
	cocos2d::Size visibleSize;

	float level;
	int ob = 0;
	int score = 0;
	char Score[10];
	bool stop_touch = false;
	bool jump_flag = true;
	bool music_flag = true;
	float face_time = 0;
	float ob_time = 0;
	float fin_time = 0;

	void doStep(float dt);

	virtual bool init();

	cocos2d::RenderTexture *renderTexture;
	void jumpFinished();
	void get_character(C_character * player, float get_level);
	void bt_music_event(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);

	//Ĳ�I
	cocos2d::EventListenerTouchOneByOne *_listener1;
	bool onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //Ĳ�I�}�l�ƥ�
	void onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //Ĳ�I���ʨƥ�
	void onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //Ĳ�I�����ƥ� 

	CREATE_FUNC(GameScene);
};