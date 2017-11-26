#pragma once

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "ui/UIWidget.h"

#include "basic.h"

class CObstacle
{
private:

public:
	CObstacle();
	~CObstacle();


	int score = 0;
	char Score[10];
	float Scale;

	cocos2d::Node * Obstacle;
	cocos2d::MoveTo * MoveAction;
	cocostudio::timeline::ActionTimeline * chAction;

	cocos2d::Node * set_obstacle(float scale);
	bool touch_obstacle(cocos2d::Rect touch, cocos2d::Point pt, cocos2d::ui::LoadingBar * blood);

};
#pragma once
