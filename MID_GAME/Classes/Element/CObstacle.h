#pragma once

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "ui/UIWidget.h"
#include "SimpleAudioEngine.h"
#include "basic.h"

class CObstacle
{
private:

public:
	CObstacle();
	~CObstacle();

	cocos2d::Node * set_obstacle(float scale);
};
#pragma once
