#include "GameScene.h"

using namespace cocos2d;

Scene* GameScene::scene()
{
	auto scene = Scene::create();
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


	
	return true;
}


void GameScene::update(float delta)
{
	
}

void GameScene::Update(float delta)
{

}

