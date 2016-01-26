#include "Object/Player.h"
#include <base/CCEvent.h>

Player::Player()
{
	texture = cocos2d::Sprite::create("Texture/Rocket.png");
	_pos = cocos2d::Vec2(0, 0);
	auto keylistener = cocos2d::EventListenerKeyboard::create();
	keylistener->onKeyPressed = CC_CALLBACK_2(Player::onKeyPressed, this);
	//cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(keylistener, 1);
}


Player::~Player()
{
}

void Player::Update()
{

}


void Player::setPos(cocos2d::Vec2 window_size, cocos2d::Vec2 origin)
{
	texture->setPosition(window_size.x / 2 + origin.x + _pos.x, window_size.y / 2 + origin.y + _pos.y);
}


void Player::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		_pos.x -= 0.5f;
	}
}


