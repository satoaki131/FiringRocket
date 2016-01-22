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

	//ウィンドウサイズ所得
	cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	//原点所得
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	auto Background = cocos2d::Sprite::create("Title/BackGround.png");

	Background->setPosition(cocos2d::Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(Background, 1);

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
