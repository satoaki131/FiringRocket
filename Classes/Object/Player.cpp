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
	_fire_move[LEFT] = cocos2d::Vec2(65, -65);
	_fire_pos[LEFT] = cocos2d::Vec2(_pos.x + (_fire_move[LEFT].x * std::cos(_fire_rad[LEFT])), _pos.y + (_fire_move[LEFT].y * std::sin(_fire_rad[LEFT])));
	_fire_angle[LEFT] = 103.0f;
	_fire_rad[LEFT] = _fire_angle[LEFT] * (M_PI / 180);
	_fire[LEFT] = cocos2d::ParticleSystemQuad::create("Particle/Fire.plist");
	_fire[RIGHT] = cocos2d::ParticleSystemQuad::create("Particle/Fire.plist");
	_fire_move[RIGHT] = cocos2d::Vec2(65, -65);
	_fire_pos[RIGHT] = cocos2d::Vec2(_pos.x + (_fire_move[RIGHT].x * std::cos(_fire_rad[RIGHT])), _pos.y + (_fire_move[RIGHT].y * std::sin(_fire_rad[RIGHT])));
	_fire_angle[RIGHT] = 83.0f;
	_fire_rad[RIGHT] = _fire_angle[RIGHT] * (M_PI / 180);
	_visiblesize = cocos2d::Director::getInstance()->getVisibleSize();
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
	_fire[LEFT]->stopSystem();
	_fire[RIGHT]->stopSystem();
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
	_fire_pos[LEFT] = cocos2d::Vec2(_pos.x + (_fire_move[LEFT].x * std::cos(_fire_rad[LEFT])), _pos.y + (_fire_move[LEFT].y * std::sin(_fire_rad[LEFT])));
	_fire_pos[RIGHT] = cocos2d::Vec2(_pos.x + (_fire_move[RIGHT].x * std::cos(_fire_rad[RIGHT])), _pos.y + (_fire_move[RIGHT].y * ::sin(_fire_rad[RIGHT])));
	_texture->setPosition(_pos);
	if (_fire[LEFT]->isActive())
	{
		_fire[LEFT]->setPosition(_fire_pos[LEFT]);
	}
	if (_fire[RIGHT]->isActive())
	{
		_fire[RIGHT]->setPosition(_fire_pos[RIGHT]);
	}
}

void Player::setRot()
{
	if (_fire[LEFT]->isActive())
	{
		_fire[LEFT]->setRotation(-_angle);
	}
	if (_fire[RIGHT]->isActive())
	{
		_fire[RIGHT]->setRotation(-_angle);
	}
	_texture->setRotation(-_angle);
}

cocos2d::Vec2 Player::getPos(){	return _pos; }

void Player::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW 
		|| keyCode == cocos2d::EventKeyboard::KeyCode::KEY_A)
	{
		_keyPressed[LEFT] = true;
		_fire[LEFT]->resetSystem();
	}
	else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW
		|| keyCode == cocos2d::EventKeyboard::KeyCode::KEY_D)
	{
		_keyPressed[RIGHT] = true;
		_fire[RIGHT]->resetSystem();
	}
	
}

void Player::onKeyRereased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW
		|| keyCode == cocos2d::EventKeyboard::KeyCode::KEY_A)
	{
		_keyPressed[LEFT] = false;
		_fire[LEFT]->stopSystem();
	}
	else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW
		|| keyCode == cocos2d::EventKeyboard::KeyCode::KEY_D)
	{
		_keyPressed[RIGHT] = false;
		_fire[RIGHT]->stopSystem();
	}
}

void Player::MoveAction()
{
	if (_keyPressed[LEFT])
	{
		_angle -= 1.0f;
		_rad = _angle * (M_PI / 180);
		_fire_angle[LEFT] += 1.0f;
		_fire_angle[RIGHT] += 1.0f;
		_fire_rad[LEFT] = _fire_angle[LEFT] * (M_PI / 180);
		_fire_rad[RIGHT] = _fire_angle[RIGHT] * (M_PI / 180);
		_pos += _moveamount * _movespeed;
	}

	if (_keyPressed[RIGHT])
	{
		_angle += 1.0f;
		_rad = _angle * (M_PI / 180);
		_fire_angle[LEFT] -= 1.0f;
		_fire_angle[RIGHT] -= 1.0f;
		_fire_rad[LEFT] = _fire_angle[LEFT] * (M_PI / 180);
		_fire_rad[RIGHT] = _fire_angle[RIGHT] * (M_PI / 180);
		_pos += _moveamount * _movespeed;
	}

	if (_keyPressed[LEFT] && _keyPressed[RIGHT])
	{
		_pos -= _moveamount * _movespeed;
	}

	if (!_keyPressed[LEFT] && !_keyPressed[RIGHT])
	{
		_pos.y -= 0.5f;
	}

	if (_pos.x > _visiblesize.width + 50)
	{
		_pos.x = -50;
	}
	else if(_pos.x < -50)
	{
		_pos.x = _visiblesize.width + 50;
	}
}


