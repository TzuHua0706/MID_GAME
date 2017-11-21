#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "CObstacle.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace ui;

CObstacle::CObstacle() {}
CObstacle::~CObstacle() {}

cocos2d::Node * CObstacle::set_obstacle(float scale) {
	auto Obstacle = CSLoader::createNode("triangleNode.csb");
	Obstacle->setPosition(150, 280);
	Obstacle->setScale(scale);
	auto chAction = (ActionTimeline *)CSLoader::createTimeline("triangleNode.csb");
	auto MoveAction = cocos2d::MoveTo::create(3.0f, Point(2000, 280));
	Obstacle->runAction(chAction);
	Obstacle->runAction(MoveAction);
	chAction->gotoFrameAndPlay(0, 35, false);
	return(Obstacle);
}
