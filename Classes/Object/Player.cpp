#include "Object/Player.h"
#include <base/CCEvent.h>

Player::Player()
{
	_texture = cocos2d::Sprite::create("Texture/Rocket.png");
	_pos = cocos2d::Vec2(0, 0);
	_angle = 0.0f;
	_rad = _angle * (M_PI / 180);
	_keyPressed[LEFT] = false;
	_keyPressed[RIGHT] = false;
	_movepos = cocos2d::Vec2(_pos.x + (20 * std::cos(_rad + (M_PI / 180))), _pos.y + (20 * std::sin(_rad + (M_PI / 180)))); 
	_moveamount = _movepos - _pos;
	_movespeed = 0.1f;
}


Player::~Player()
{
}

cocos2d::Sprite* Player::getPlayerTexture(){ return _texture; }

void Player::Init(cocos2d::EventDispatcher* dispatcher, cocos2d::Node* node, cocos2d::Size window_size)
{
	_pos = cocos2d::Vec2(window_size.width / 2, window_size.height / 2);

	keylistener = cocos2d::EventListenerKeyboard::create();
	keylistener->onKeyPressed = CC_CALLBACK_2(Player::onKeyPressed, this);
	keylistener->onKeyReleased = CC_CALLBACK_2(Player::onKeyRereased, this);
	dispatcher->addEventListenerWithSceneGraphPriority(keylistener, node);

	_texture->setScale(0.4f);
}


void Player::Update()
{
	setPos();
	setRot();
	MoveAction();
}


void Player::setPos()
{
	_movepos = cocos2d::Vec2(_pos.x + (20 * std::cos(_rad + (M_PI / 2))), _pos.y + (20 * std::sin(_rad + (M_PI / 2))));
	_moveamount = _movepos - _pos;
	_texture->setPosition(_pos);

}

void Player::setRot()
{
	_texture->setRotation(-_angle);
}


void Player::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW 
		|| keyCode == cocos2d::EventKeyboard::KeyCode::KEY_A)
	{
		_keyPressed[LEFT] = true;
	}
	else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW
		|| keyCode == cocos2d::EventKeyboard::KeyCode::KEY_D)
	{
		_keyPressed[RIGHT] = true;
	}
	
}

void Player::onKeyRereased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW
		|| keyCode == cocos2d::EventKeyboard::KeyCode::KEY_A)
	{
		_keyPressed[LEFT] = false;
	}
	else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW
		|| keyCode == cocos2d::EventKeyboard::KeyCode::KEY_D)
	{
		_keyPressed[RIGHT] = false;
	}
}

void Player::MoveAction()
{
	if (_keyPressed[LEFT])
	{
		_angle -= 1.0f;
		_rad = _angle * (M_PI / 180);
		_pos += _moveamount * _movespeed;
	}

	if (_keyPressed[RIGHT])
	{
		_angle += 1.0f;
		_rad = _angle * (M_PI / 180);
		_pos += _moveamount * _movespeed;
	}

	if (_keyPressed[LEFT] && _keyPressed[RIGHT])
	{
		_pos -= _moveamount * _movespeed;
	}
	else if (!_keyPressed[LEFT] && !_keyPressed[RIGHT])
	{
		_pos.y -= 0.5f;
	}
}


