#include "Object/Player.h"
#include <base/CCEvent.h>

Player::Player()
{
	_texture = cocos2d::Sprite::create("Texture/Rocket.png");
	_pos = cocos2d::Vec2(0, 0);
	_angle = 0.0f;
}


Player::~Player()
{
}

void Player::KeyInit(cocos2d::EventDispatcher* dispatcher, cocos2d::Node* node)
{
	keylistener = cocos2d::EventListenerKeyboard::create();
	keylistener->onKeyPressed = CC_CALLBACK_2(Player::onKeyPressed, this);
	dispatcher->addEventListenerWithSceneGraphPriority(keylistener, node);
}


void Player::Update(cocos2d::Vec2 window_size, cocos2d::Vec2 origin)
{
	setPos(window_size, origin);
	setRot();
}


void Player::setPos(cocos2d::Vec2 window_size, cocos2d::Vec2 origin)
{
	_texture->setPosition(window_size.x / 2 + origin.x + _pos.x, window_size.y / 2 + origin.y + _pos.y);
	//_pos.y -= 0.5f;
}

void Player::setRot()
{
	_texture->setRotation(_angle);
}

cocos2d::Sprite* Player::getPlayerTexture(){ return _texture; }

void Player::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW 
		|| keyCode == cocos2d::EventKeyboard::KeyCode::KEY_A)
	{
		_angle -= 1.0f;
	}
	else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW
		|| keyCode == cocos2d::EventKeyboard::KeyCode::KEY_D)
	{
		_angle += 1.0f;
	}
	
}




