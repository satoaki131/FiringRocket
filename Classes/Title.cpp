#include "Title.h"
#include "GameScene.h"

cocos2d::Scene* Title::scene()
{
	auto scene = cocos2d::Scene::create();
	auto layer = Title::create();
	scene->addChild(layer);
	return scene;
}
bool Title::init() 
{
	run = 0;
	if (!Layer::init())
	{
		return false;
	}
	this->schedule(schedule_selector(Title::Update));
	return true;
}

void Title::Update(float delta)
{
	run++;
	if (run == 60)
	{
		cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(2.0f, GameScene::CreateScene(), cocos2d::Color3B::WHITE));
	}
}
