#include "Object/Enemy_UFO.h"


Enemy_UFO::Enemy_UFO()
{
	_texture = cocos2d::Sprite::create("Texture/Enemy1.png");
	_texture->setScale(0.4f);
	_pos = cocos2d::Vec2(0, 0);
	_active = false;
	_repeat_time = 20 * 60;
	_drawTexture = false;
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
	auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	if (!_active)
	{
		_randomPoint = cocos2d::random(0, 1);
		_randomPoint == 0 ?
			_pos = cocos2d::Vec2(0, visibleSize.height) :
			_pos = cocos2d::Vec2(visibleSize);
		_repeat_time--;

		if (_repeat_time == 0)
		{
			_active = true;
		}
	}
	else
	{
		switch (_mode)
		{
		case START:
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
			_pos.y -= 0.5f;
			_randomPoint == 0 ?
				_pos.x += 1.0f :
				_pos.x -= 1.0f;
			if (_pos.y == 0)
			{
				_mode = START;
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

}

cocos2d::Sprite* Enemy_UFO::getUFOTexture(){ return _texture; }

bool Enemy_UFO::ActiveCheck(){ return _active; }

int Enemy_UFO::TimeCheck(){ return _repeat_time; }

//bool Enemy_UFO::setdrawTexture(bool& active)
//{
//	_drawTexture = active;
//}

