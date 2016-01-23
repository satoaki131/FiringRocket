#include "Title.h"
#include "GameScene.h"
#include <base/CCEventListenerMouse.h>
#include <base/CCEvent.h>

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

	auto dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
	auto mouselistener = cocos2d::EventListenerMouse::create();
	mouselistener->onMouseDown = CC_CALLBACK_1(Title::onMouseDown, this);
	dispatcher->addEventListenerWithSceneGraphPriority(mouselistener, this);

	//ウィンドウサイズ所得
	cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	//原点所得
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	auto Background = cocos2d::Sprite::create("Title/BackGround.png");

	Background->setPosition(cocos2d::Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(Background, 1);

	this->schedule(schedule_selector(Title::Update));


	return true;
}

void Title::Update(float delta)
{
	//run++;
	//if (run == 120)
	//{
	//	cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(2.0f, GameScene::CreateScene(), cocos2d::Color3B::WHITE));
	//}
}

void Title::onMouseDown(cocos2d::Event* event)
{
	cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(2.0f, GameScene::CreateScene(), cocos2d::Color3B::WHITE));
}