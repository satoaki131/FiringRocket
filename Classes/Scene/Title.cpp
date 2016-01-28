#include "Scene/Title.h"
#include "Scene/GameScene.h"
#include <base/CCEvent.h>
#include "SimpleAudioEngine.h"

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
	//原点所得
	origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	background_pos = cocos2d::Vec2(visibleSize.width / 2 + origin.x + background_pos.x, visibleSize.height / 2 + origin.y + background_pos.y);

	//点の描画
	//auto point = cocos2d::DrawNode::create();
	//point->drawDot(cocos2d::Vec2(visibleSize / 2), 1.0f, cocos2d::Color4F(1.0f, 1.0f, 1.0f, 1.0f));

	//文字表示(文字, Font, FontSize)
	auto title_label = cocos2d::Label::createWithTTF("Firing Rocket", "fonts/JKG-M_3.ttf", 65);
	title_label->setColor(cocos2d::Color3B::ORANGE);
	title_label->setPosition(cocos2d::Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2 + title_label->getContentSize().height));

	auto start_label = cocos2d::Label::createWithTTF("Enter to Start", "fonts/JKG-M_3.ttf", 30);
	start_label->setColor(cocos2d::Color3B::MAGENTA);
	label_pos = cocos2d::Vec2(origin.x + visibleSize.width / 2 + label_pos.x, origin.y + visibleSize.height / 2 + title_label->getContentSize().height + label_pos.y - 150);
	label_angle = 0.1f;
	start_label->setPosition(label_pos);
	start_label->setTag(2);

	
	auto background = cocos2d::Sprite::create("Texture/BackGround.png");
	background->setPosition(background_pos);
	
	player.KeyInit(dispatcher, this);
	player.setPos(visibleSize, origin);
	//上から順に描画されていく
	this->addChild(background, 1);
	this->addChild(title_label, 1);
	this->addChild(start_label, 1);
	this->addChild(player.getPlayerTexture(), 1);
	

	this->scheduleUpdate();

	return true;
}

void Title::update(float delta)
{
	
	auto start_label = this->getChildByTag(2);
	start_label->setPosition(label_pos);
	label_angle += 0.1f;
	label_pos.y += std::sin(label_angle);
	player.Update(visibleSize, origin);
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
		cocos2d::Director::getInstance()->replaceScene(
			cocos2d::TransitionFade::create(2.0f, GameScene::scene(), cocos2d::Color3B::WHITE)
			//cocos2d::TransitionCrossFade::create(2.0f, GameScene::scene())
			);
		sound.BGMStop();
	}
	
}