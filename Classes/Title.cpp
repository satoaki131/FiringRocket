#include "Title.h"
#include "GameScene.h"
#include <base/CCEventMouse.h>
#include <base/CCEvent.h>

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
	//�f�B���N�^�N���X����
	auto dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
	//�}�E�X�֘A
	auto mouselistener = cocos2d::EventListenerMouse::create();
	mouselistener->onMouseDown = CC_CALLBACK_1(Title::onMouseDown, this);
	dispatcher->addEventListenerWithSceneGraphPriority(mouselistener, this);

	//�E�B���h�E�T�C�Y����
	cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	//���_����
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	background_pos = cocos2d::Vec2(visibleSize.width / 2 + origin.x + background_pos.x, visibleSize.height / 2 + origin.y + background_pos.y);

	//�����\��(����, Font, FontSize)
	auto title_label = cocos2d::Label::createWithTTF("Firing Rocket", "fonts/JKG-M_3.ttf", 65);
	title_label->setColor(cocos2d::Color3B::ORANGE);
	title_label->setPosition(cocos2d::Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2 + title_label->getContentSize().height));

	auto start_label = cocos2d::Label::createWithTTF("Enter to Start", "fonts/JKG-M_3.ttf", 30);
	start_label->setColor(cocos2d::Color3B::MAGENTA);
	label_pos = cocos2d::Vec2(origin.x + visibleSize.width / 2 + label_pos.x, origin.y + visibleSize.height / 2 + title_label->getContentSize().height + label_pos.y - 150);
	label_angle = 0.1f;
	start_label->setPosition(label_pos);
	start_label->setTag(2);

	auto background = cocos2d::Sprite::create("Title/BackGround.png");
	background->setPosition(background_pos);

	//�ォ�珇�ɕ`�悳��Ă���
	this->addChild(background, 1);
	this->addChild(title_label, 1);
	this->addChild(start_label, 1);

	this->scheduleUpdate();

	return true;
}

void Title::update(float delta)
{
	
	auto start_label = this->getChildByTag(2);
	start_label->setPosition(label_pos);
	label_angle += 0.1f;
	label_pos.y += std::sin(label_angle);

}

void Title::onMouseDown(cocos2d::Event* event)
{
	//pushScene�͑J�ڑO�̏����c�����܂܎��̃V�[����(popScene��1�O�ɖ߂�)�B
	//replaceScene�͑J�ڑO�̃f�[�^�����S�ɏ����Ď��̃V�[���Ɉړ�����
	cocos2d::Director::getInstance()->replaceScene(
		cocos2d::TransitionFade::create(2.0f, GameScene::scene(), cocos2d::Color3B::WHITE)
		);
	this->unscheduleUpdate();
}