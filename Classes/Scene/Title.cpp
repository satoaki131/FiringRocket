#include "Scene/Title.h"
#include "Scene/GameScene.h"
#include <base/CCEvent.h>
#include "SimpleAudioEngine.h"
#include "Manager/Score.h"

cocos2d::Scene* Title::scene()
{
	auto scene = cocos2d::Scene::create();
	auto layer = Title::create();
	scene->addChild(layer);
	return scene;
}

bool Title::init() 
{
	if (!Layer::init())
	{
		return false;
	}
	//ディレクタクラス所得
	auto dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
	
	
	//マウス関連
	//auto mouselistener = cocos2d::EventListenerMouse::create();
	//mouselistener->onMouseDown = CC_CALLBACK_1(Title::onMouseDown, this);
	//dispatcher->addEventListenerWithSceneGraphPriority(mouselistener, this);

	//キーボード関連
	auto keylistener = cocos2d::EventListenerKeyboard::create();
	keylistener->onKeyPressed = CC_CALLBACK_2(Title::onKeyPressed, this);
	dispatcher->addEventListenerWithSceneGraphPriority(keylistener, this);
	
	//サウンド関連
	//あらかじめ読み込んでおいたほうが良い(やらなくてもいけるが、サイズによっては処理が遅くなるため、やっておいたほうが良い)
	//CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Sound/titleBGM.mp3");
	//再生
	//CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound/titleBGM.mp3", true);
	sound.BGMInit("Sound/titleBGM.mp3");
	sound.BGMPlay(true);
	
	//ウィンドウサイズ所得
	visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	////原点所得
	//origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	background_pos = cocos2d::Vec2(visibleSize.width / 2 + background_pos.x, visibleSize.height / 2 + background_pos.y);

	
	//文字表示(文字, Font, FontSize)
	auto title_label = cocos2d::Label::createWithTTF("Firing Rocket", "fonts/JKG-M_3.ttf", 65);
	title_label->setColor(cocos2d::Color3B::ORANGE);
	title_label->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2 + title_label->getContentSize().height));
	title_label->setTag(1);

	auto start_label = cocos2d::Label::createWithTTF("Enter to Start", "fonts/JKG-M_3.ttf", 30);
	start_label->setColor(cocos2d::Color3B::MAGENTA);
	label_pos = cocos2d::Vec2(visibleSize.width / 2 + label_pos.x, visibleSize.height / 2 + title_label->getContentSize().height + label_pos.y - 150);
	label_angle = 0.1f;
	start_label->setPosition(label_pos);
	start_label->setTag(2);

	
	auto background = cocos2d::Sprite::create("Texture/BackGround.png");
	background->setPosition(background_pos);
	
	//player.Init(dispatcher, this, visibleSize);
	player.getPlayerTexture()->setScale(0.4f);
	player.setPos(cocos2d::Vec2(visibleSize.width / 2, -45));

	//点の描画
	//auto point1 = cocos2d::DrawNode::create();
	//point1->drawDot(cocos2d::Vec2(0, 0), 5.0f, cocos2d::Color4F(1.0f, 1.0f, 1.0f, 1.0f));
	//point1->setTag(5);

	//auto point2 = cocos2d::DrawNode::create();
	//point2->drawDot(cocos2d::Vec2(0, 0), 5.0f, cocos2d::Color4F(1.0f, 0.0f, 1.0f, 1.0f));
	//point2->setTag(6);

	//上から順に描画されていく
	this->addChild(background, 1);
	this->addChild(title_label, 1);
	this->addChild(start_label, 1);
	this->addChild(player._fire[LEFT], 1);
	this->addChild(player._fire[RIGHT], 1);
	this->addChild(player.getPlayerTexture(), 1);
	//this->addChild(point1, 1);
	//this->addChild(point2, 1);

	this->scheduleUpdate();

	return true;
}

void Title::update(float delta)
{
	
	auto start_label = this->getChildByTag(2);
	start_label->setPosition(label_pos);
	label_angle += 0.1f;
	label_pos.y += std::sin(label_angle);
	//player.Update();

	//auto point1 = this->getChildByTag(5);
	//point1->setPosition(player._pos);

	//auto point2 = this->getChildByTag(6);
	//point2->setPosition(player._fire_pos);
}

void Title::onMouseDown(cocos2d::Event* event)
{
	//pushSceneは遷移前の情報を残したまま次のシーンに(popSceneは1つ前に戻る)。
	//replaceSceneは遷移前のデータを完全に消して次のシーンに移動する
	cocos2d::Director::getInstance()->replaceScene(
		cocos2d::TransitionFade::create(2.0f, GameScene::scene(), cocos2d::Color3B::WHITE)
		);
	this->unscheduleUpdate();
}

void Title::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_ENTER)
	{
		//呼ばれる順番の問題
		//scheduleは止めてからシーン移動処理が必要
		this->unscheduleUpdate();
		player._fire[LEFT]->resetSystem();
		player._fire[RIGHT]->resetSystem();
		this->schedule(schedule_selector(Title::LoadGame));
		auto start_label = this->getChildByTag(2);
		auto fade = cocos2d::FadeOut::create(1);
		start_label->runAction(fade);
	}
	
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_SPACE)
	{
		//スコアのリセット
		Score::ResetHighScore();
		Score::_userDefault->deleteValueForKey("HIGHSCORE");
	}
}

void Title::LoadGame(float delta)
{
	player.TitleMove();
	auto pos = player.getPos();
	if (pos.y == visibleSize.height - 150)
	{
		auto title_label = this->getChildByTag(1);
		auto fade = cocos2d::FadeOut::create(0.5);
		title_label->runAction(fade);
		sound.BGMStop();
		cocos2d::Director::getInstance()->replaceScene(
			cocos2d::TransitionFade::create(3.0f, GameScene::scene(), cocos2d::Color3B::WHITE)
			);
	}

	if (pos.y > visibleSize.height + 50)
	{
		this->unschedule(schedule_selector(Title::LoadGame));
	}

}