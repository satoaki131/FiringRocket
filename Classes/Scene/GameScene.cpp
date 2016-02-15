#include "Scene/GameScene.h"
#include "Scene/Result.h"
#include "Manager/Hit.h"

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

	//�w�i�֘A
	for (int i = 0; i < 200; i++)
	{
		_background.push_back(cocos2d::DrawNode::create());
		_backgroundpos.push_back(cocos2d::Vec2(cocos2d::random(0.0f, visibleSize.width), cocos2d::random(0.0f, visibleSize.height)));
		_background[i]->drawDot(_backgroundpos[i], cocos2d::random(0.1f, 0.8f), cocos2d::Color4F::WHITE);
		this->addChild(_background[i], 1);
	}

	//�X�R�A�̕����\��
	auto label = Score::Init(30);
	player.Init(dispatcher, this, visibleSize);
	this->scheduleUpdate();
	Meteo m;
	meteo.push_back(m);
	this->addChild(meteo[0]._part, 1);
	this->addChild(meteo[0].getTexture(), 1);

	enemy_ufo.Init();
	this->addChild(enemy_ufo.getUFOTexture(), 1);
	this->addChild(enemy_ufo._lazer, 1);
	this->addChild(player._fire[LEFT], 1);
	this->addChild(player._fire[RIGHT], 1);
	this->addChild(player.getPlayerTexture(), 1);
	this->addChild(label, 1);
	_score = Score::Update(30);
	this->addChild(_score, 1);

	sound.BGMInit("Sound/Main.mp3");
	//sound.BGMPlay(true);

	return true;
}


void GameScene::update(float delta)
{
	player.Update();
	enemy_ufo.Update(player.getPos());
	for (int i = 0; i < meteo.size(); i++)
	{
		meteo[i].Update(player.getPos());
	}
	this->removeChild(_score);
	_score = Score::Update(30);
	this->addChild(_score);
	Collision();
	BackGroundMove();
	MeteoCreater();
}

void GameScene::MeteoCreater()
{

	for (int i = meteo.size(); i < meteo.size() + 1; i++)
	{
		if (Score::getNowScore() == 60 * 20 * i)
		{
			Meteo m;
			meteo.push_back(m);
			this->addChild(meteo[i]._part, 1);
			this->addChild(meteo[i].getTexture(), 1);
		}
	}
}

void GameScene::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_ENTER)
	{ 
		sound.BGMPause();
		cocos2d::Director::getInstance()->pushScene(Pause::scene());
	}
}


void GameScene::Collision()
{
	//player�̃|�W�V��������
	auto p_pos = player.getPos();

	//UFO�̍��W
	auto e_pos = enemy_ufo.getEnemyPos();
	//���[�U�[�̍��W
	auto l_pos = enemy_ufo.getLazerPos();

	//UFO�ƃv���C���[�̔���
	bool p_eHit = Collision::hit4(p_pos.x, p_pos.y, 40, e_pos.x, e_pos.y, 45);
	if (p_eHit)
	{
		MoveResult();
	}
	//���[�U�[�ƃv���C���[�̔���
	bool p_lHit = Collision::hit4(p_pos.x, p_pos.y, 40, l_pos.x, l_pos.y, 5);
	if (p_lHit)
	{
		MoveResult();
	}

	//覐΂ƃv���C���[�̂����蔻��
	for (int i = 0; i < meteo.size(); i++)
	{
		auto meteo_pos = meteo[i].getPos();
		bool p_mhit = Collision::hit4(p_pos.x, p_pos.y, 40, meteo_pos.x, meteo_pos.y, 30);
		if (p_mhit)
		{
			MoveResult();
		}
	}
	//��ʊO�ɂ�������Q�[���I�[�o�[
	if (p_pos.y > visibleSize.height + 50)
	{
		MoveResult();
	}
	else if (p_pos.y < -50)
	{
		MoveResult();
	}

}

void GameScene::BackGroundMove()
{
	for (int i = 0; i < _background.size(); i++)
	{
		_backgroundpos[i].y -= 0.5f;
		if (_backgroundpos[i].y < -visibleSize.height / 2)
		{
			_backgroundpos[i].y = visibleSize.height;
		}
		_background[i]->setPosition(_backgroundpos[i]);
	}
}


void GameScene::MoveResult()
{
	this->unscheduleUpdate();
	sound.BGMStop();
	player._sound.EffectPlay(false);
	cocos2d::Director::getInstance()->replaceScene(
		cocos2d::TransitionFade::create(2.0f, Result::scene(), cocos2d::Color3B::RED)
		);
}
