#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "CObstacle.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace ui;

CObstacle::CObstacle() {
	Obstacle = CSLoader::createNode("triangleNode.csb");
	Obstacle->setPosition(150, 280);
	MoveAction = cocos2d::MoveTo::create(2.0f, Point(1400, 280));
	chAction = (ActionTimeline *)CSLoader::createTimeline("triangleNode.csb");
	get_score = 0;
}
CObstacle::~CObstacle() {}

cocos2d::Node * CObstacle::set_obstacle(float scale) {
	Scale = scale;
	Obstacle->setScale(scale);
	Obstacle->runAction(chAction);
	chAction->gotoFrameAndPlay(0, 35, false);
	auto delay = DelayTime::create(0.4f);
	Obstacle->runAction(Sequence::create(delay, MoveAction, NULL));
	if (Scale > 0.7) {
		get_score = 10;
	}
	else if (Scale > 0.5) {
		get_score = 5;
	}
	else {
		get_score = 3;
	}
	return(Obstacle);
}
bool CObstacle::touch_obstacle(cocos2d::Rect touch, Point pt, ui::LoadingBar * blood) {
	if (touch.containsPoint(pt)) {
		if (Scale > 0.7) {
			float t = blood->getPercent();
			t = t - 30;
			blood->setPercent(t);
		}
		else if(Scale > 0.5){
			float t = blood->getPercent();
			t = t - 10;
			blood->setPercent(t);
		}
		else {
			float t = blood->getPercent();
			t = t - 5;
			blood->setPercent(t);
		}
		return(true);
	}
	return(false);
}