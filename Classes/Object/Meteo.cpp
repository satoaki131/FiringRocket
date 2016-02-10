#include "Object/Meteo.h"


Meteo::Meteo()
{
	_pos = cocos2d::Vec2(1000, 1000);
	_texture = cocos2d::Sprite::create("Texture/Meteo.png");
	_texture->setScale(cocos2d::random(0.3f, 0.5f));
	_texture->setPosition(_pos);
	_angle = 0.0f;
	_active = false;
	visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	_randomPoint = cocos2d::random(0, 1);
	_repeat_time = 5 * 60;
	_p_pos = cocos2d::Vec2(1000, 1000);
	_move_pos = cocos2d::Vec2(0, 0);
	_move_speed = cocos2d::random(0.005f, 0.01f);
	_part = cocos2d::ParticleSystemQuad::create("Particle/Meteo.plist");
	_part->stopSystem();
}


Meteo::~Meteo()
{
}


void Meteo::Update(cocos2d::Vec2 player_pos)
{
	setRot();
	Move(player_pos);
}

void Meteo::Move(cocos2d::Vec2 player_pos)
{
	if (!_active)
	{
		_repeat_time--;
		if (_repeat_time == 0)
		{
			_repeat_time = 5 * 60;
			_active = true;
			_randomPoint = cocos2d::random(0, 1);
			_randomPoint == 0 ?
				_pos = cocos2d::Vec2(0, cocos2d::random(0.0f, visibleSize.height)) :
				_pos = cocos2d::Vec2(visibleSize.width, cocos2d::random(0.0f, visibleSize.height));
			_p_pos = player_pos;
			_move_pos = _p_pos - _pos;
			_part->resetSystem();
		}
	}
	else
	{
		_pos += _move_pos * _move_speed;
		_texture->setPosition(_pos);
		_part->setPosition(_pos);
		if (_pos.x < 0 || _pos.x > visibleSize.width || _pos.y < 0 || _pos.y > visibleSize.height)
		{
			_active = false;
			_pos = cocos2d::Vec2(1000, 1000);
			_texture->setPosition(_pos);
			_part->setPosition(_pos);
			_part->stopSystem();
		}
	}
}

void Meteo::setRot()
{
	_move_pos.x > 0 ?
		_angle++ : _angle--;
	_texture->setRotation(_angle);
}

cocos2d::Vec2 Meteo::getPos(){ return _pos; }


cocos2d::Sprite* Meteo::getTexture(){ return _texture; }

