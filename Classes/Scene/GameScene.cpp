#include "Scene/GameScene.h"

cocos2d::Scene* GameScene::scene()
{
	auto scene = cocos2d::Scene::create();
	auto layer = GameScene::create();
	scene->addChild(layer);
	
	return scene;
}

bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//�f�B���N�^�N���X����
	auto dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();

	//�L�[�{�[�h�֘A
	auto keylistener = cocos2d::EventListenerKeyboard::create();
	keylistener->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
	dispatcher->addEventListenerWithSceneGraphPriority(keylistener, this);
	

	//�E�B���h�E�T�C�Y����
	visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

	auto label = Score::Init();
	player.Init(dispatcher, this, visibleSize);
	this->scheduleUpdate();

	this->addChild(player._fire[LEFT], 1);
	this->addChild(player._fire[RIGHT], 1);
	this->addChild(player.getPlayerTexture(), 1);
	this->addChild(label, 1);
	_score = Score::Update();
	this->addChild(_score, 1);
	return true;
}


void GameScene::update(float delta)
{
	player.Update();
	this->removeChild(_score);
	_score = Score::Update();
	this->addChild(_score);
	Collision();
}

void GameScene::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_ENTER)
	{
		cocos2d::Director::getInstance()->pushScene(Pause::scene());
	}
}


void GameScene::Collision()
{
	
}

