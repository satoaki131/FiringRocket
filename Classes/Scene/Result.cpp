#include "Scene/Result.h"

cocos2d::Scene* Result::scene()
{
	auto scene = cocos2d::Scene::create();
	auto layer = Result::create();
	scene->addChild(layer);
	return scene;
}

bool Result::init()
{
	if (!Layer::init())
	{
		return false;
	}

	return true;
}