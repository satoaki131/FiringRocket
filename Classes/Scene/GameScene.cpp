#include "Scene/GameScene.h"
#include "Scene/Result.h"

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

	_background = cocos2d::Sprite::create("Texture/MainBackGround.png");
	_background->setPosition(visibleSize / 2);
	_background->setScaleY(1.5f);
	this->addChild(_background);

	auto label = Score::Init(30);
	player.Init(dispatcher, this, visibleSize);
	this->scheduleUpdate();

	this->addChild(player._fire[LEFT], 1);
	this->addChild(player._fire[RIGHT], 1);
	this->addChild(player.getPlayerTexture(), 1);
	this->addChild(label, 1);
	_score = Score::Update(30);
	this->addChild(_score, 1);

	return true;
}


void GameScene::update(float delta)
{
	player.Update();
	enemy_ufo.Update();
	//if (enemy_ufo.ActiveCheck() && !enemy_ufo.)
	//{
	//	this->addChild(enemy_ufo.getUFOTexture(), 1);
	//}
	//if (!enemy_ufo.ActiveCheck())
	//{
	//	this->removeChild(enemy_ufo.getUFOTexture(), 1);
	//}

	this->removeChild(_score);
	_score = Score::Update(30);
	this->addChild(_score);
	Collision();
	BackGroundMove();
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
	//player�̃|�W�V��������
	auto pos = player.getPos();
	
	//��ʊO�ɂ�������Q�[���I�[�o�[
	if (pos.y > visibleSize.height + 50)
	{
		this->unscheduleUpdate();
		cocos2d::Director::getInstance()->replaceScene(
			cocos2d::TransitionFade::create(2.0f, Result::scene(), cocos2d::Color3B::RED)
			);
	}
	else if (pos.y < -50)
	{
		this->unscheduleUpdate();
		cocos2d::Director::getInstance()->replaceScene(
			cocos2d::TransitionFade::create(2.0f, Result::scene(), cocos2d::Color3B::RED)
			);
	}
}

void GameScene::BackGroundMove()
{

}

