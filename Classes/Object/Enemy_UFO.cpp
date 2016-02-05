#include "Object/Enemy_UFO.h"


Enemy_UFO::Enemy_UFO()
{
	visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	_texture = cocos2d::Sprite::create("Texture/Enemy.png");
	_texture->setScale(0.4f);
	_randomPoint = cocos2d::random(0, 1);
	_pos = cocos2d::Vec2(1000, 1000);
	_texture->setPosition(_pos);
	_active = false;
	_repeat_time = 20 * 60;
	_mode = START;
}


Enemy_UFO::~Enemy_UFO()
{

}


void Enemy_UFO::Update()
{
	Move();
}

void Enemy_UFO::Move()
{
	if (!_active)
	{
		_repeat_time--;
		if (_repeat_time == 0)
		{
			_active = true;
			_repeat_time = 2 * 60;
			_randomPoint = cocos2d::random(0, 1);
			_randomPoint == 0 ?
				_pos = cocos2d::Vec2(0, visibleSize.height) :
				_pos = cocos2d::Vec2(visibleSize);
		}
	}
	else
	{
		switch (_mode)
		{
		case START:
			_texture->setPosition(_pos);
			_pos.y -= 0.5f;
			_randomPoint == 0 ?
				_pos.x += 1.0f :
				_pos.x -= 1.0f;
			if (_pos.y == visibleSize.height / 2 + 100)_mode = ACTION;
			break;
		case ACTION:
			Action();
			break;
		case END:
			_texture->setPosition(_pos);
			_pos.y -= 0.5f;
			_randomPoint == 0 ?
				_pos.x += 1.0f :
				_pos.x -= 1.0f;
			if (_pos.y == 0)
			{
				_mode = START;
				_pos = cocos2d::Vec2(1000, 1000);
				_active = false;
				_repeat_time = 20 * 60;
			}
			break;
		default:
			break;
		}
	}
}

void Enemy_UFO::Action()
{
	_repeat_time--;
	if (_repeat_time == 0)
	{
		//ÉrÅ[ÉÄê∂ê¨èàóù

		_mode = END;
	}
}

cocos2d::Sprite* Enemy_UFO::getUFOTexture(){ return _texture; }

bool Enemy_UFO::ActiveCheck(){ return _active; }

int Enemy_UFO::TimeCheck(){ return _repeat_time; }

