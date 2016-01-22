#include "GameScene.h"

using namespace cocos2d;
using namespace std;

Scene* GameScene::CreateScene()
{
	auto scene = Scene::create();
	GameScene* layer = GameScene::create();
	scene->addChild(layer);

	return scene;
}

bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	this->schedule(schedule_selector(GameScene::Update));
	return true;
}


void  GameScene::Update(float delta)
{
	//ƒtƒŒ[ƒ€ˆ—

}

