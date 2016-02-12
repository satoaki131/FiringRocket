#include "Scene/Result.h"
#include "Scene/Title.h"
#include "Manager/Score.h"

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

	auto dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
	auto keylistener = cocos2d::EventListenerKeyboard::create();
	keylistener->onKeyPressed = CC_CALLBACK_2(Result::onKeyPressed, this);
	dispatcher->addEventListenerWithSceneGraphPriority(keylistener, this);
	visiblesize = cocos2d::Director::getInstance()->getVisibleSize();
	auto score = Score::getNowScore();
	//ハイスコアかどうか確認
	auto highscoreflug = Score::HighscoreCheck(score);

	if (highscoreflug) //ハイスコアなら
	{
		fountain = cocos2d::ParticleSystemQuad::create("Particle/Fountain.plist");
		fountain->setPosition(visiblesize.width / 2, -70);
		this->addChild(fountain, 1);

		auto score_label = cocos2d::Label::createWithTTF("Score :", "fonts/JKG-M_3.ttf", 50);
		score_label->setPosition(visiblesize.width / 2 - 70, visiblesize.height / 2);
		this->addChild(score_label, 1);

		auto scoredraw = Score::DisplayScore(50);
		scoredraw->setPosition(visiblesize.width / 2 + 75, visiblesize.height / 2);
		this->addChild(scoredraw, 1);
	}
	else //違うとき
	{
		auto score_label = cocos2d::Label::createWithTTF("Score :", "fonts/JKG-M_3.ttf", 50);
		score_label->setPosition(visiblesize.width / 2 - 70, visiblesize.height / 2);
		this->addChild(score_label, 1);

		auto scoredraw = Score::DisplayScore(50);
		scoredraw->setPosition(visiblesize.width / 2 + 75, visiblesize.height / 2);
		this->addChild(scoredraw, 1);
	}

	return true;
}

void Result::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_ENTER)
	{
		Score::ResetScore();
		cocos2d::Director::getInstance()->replaceScene(
			cocos2d::TransitionFade::create(2.0f, Title::scene(), cocos2d::Color3B::BLACK)
			);
	}
}

