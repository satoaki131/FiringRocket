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
	_highscoreflug = Score::HighscoreCheck(score);
	color_timer = 1;

	//背景関連
	for (int i = 0; i < 200; i++)
	{
		_background.push_back(cocos2d::DrawNode::create());
		_backgroundpos.push_back(cocos2d::Vec2(cocos2d::random(0.0f, visiblesize.width), cocos2d::random(0.0f, visiblesize.height)));
		_background[i]->drawDot(_backgroundpos[i], cocos2d::random(0.1f, 0.8f), cocos2d::Color4F::WHITE);
		this->addChild(_background[i], 1);
	}

	if (_highscoreflug) //ハイスコアなら
	{
		fountain = cocos2d::ParticleSystemQuad::create("Particle/Fountain.plist");
		fountain->setPosition(visiblesize.width / 2, -70);
		this->addChild(fountain, 1);

		_highscore_label = cocos2d::Label::createWithTTF("HIGHSCORE!!", "fonts/JKG-M_3.ttf", 70);
		_highscore_label->setPosition(visiblesize.width / 2, visiblesize.height - 100);
		_color = cocos2d::Color4B(cocos2d::random(0, 255), cocos2d::random(0, 255), cocos2d::random(0, 255), 255);
		_highscore_label->setTextColor(_color);
		this->addChild(_highscore_label, 1);
		Score::_userDefault->setIntegerForKey("HIGHSCORE", score);
	}
	else //違うとき
	{
		//スコアのリセット
		Score::_userDefault->deleteValueForKey("HIGHSCORE");
	}

	//共通部分
	auto score_label = cocos2d::Label::createWithTTF("Score :", "fonts/JKG-M_3.ttf", 50);
	score_label->setPosition(visiblesize.width / 2 - 70, visiblesize.height / 2);
	this->addChild(score_label, 1);

	auto scoredraw = Score::DisplayScore(50);
	scoredraw->setPosition(visiblesize.width / 2 + 75, visiblesize.height / 2);
	this->addChild(scoredraw, 1);

	this->scheduleUpdate();

	return true;
}


void Result::update(float delta)
{
	if (_highscoreflug)
	{
		color_timer--;
		if (color_timer == 0)
		{
			_color = ColorRandom();
			color_timer = 5;
		}
		_highscore_label->setTextColor(_color);
	}
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

cocos2d::Color4B Result::ColorRandom()
{
	std::vector<cocos2d::Color4B> color;
	color.push_back(cocos2d::Color4B::BLUE);
	color.push_back(cocos2d::Color4B::GREEN);
	color.push_back(cocos2d::Color4B::MAGENTA);
	color.push_back(cocos2d::Color4B::RED);
	color.push_back(cocos2d::Color4B::WHITE);
	color.push_back(cocos2d::Color4B::YELLOW);
	color.push_back(cocos2d::Color4B::GRAY);
	color.push_back(cocos2d::Color4B::ORANGE);
	int number = cocos2d::random(0, (int)color.size() - 1);
	return color[number];
}