#include "Scene/Pause.h"
#include "Scene/GameScene.h"
cocos2d::Scene* Pause::scene()
{
	auto scene = cocos2d::Scene::create();
	auto layer = Pause::create();
	scene->addChild(layer);

	return scene;
}

bool Pause::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
	visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	auto keylistener = cocos2d::EventListenerKeyboard::create();
	keylistener->onKeyPressed = CC_CALLBACK_2(Pause::onKeyPressed, this);
	dispatcher->addEventListenerWithSceneGraphPriority(keylistener, this);

	auto font = cocos2d::Label::createWithTTF("Pause", "fonts/JKG-M_3.ttf", 50);
	font->setColor(cocos2d::Color3B::YELLOW);
	font->setPosition(cocos2d::Vec2(visibleSize.width, visibleSize.height));

	return true;
}

void Pause::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_ENTER)
	{
		cocos2d::Director::getInstance()->popScene();
	}
}


