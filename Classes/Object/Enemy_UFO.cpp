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
	_lazer = cocos2d::ParticleSystemQuad::create("Particle/Lazer.plist");
	_lazer_pos = cocos2d::Vec2(1000, 1000);
	_p_pos = cocos2d::Vec2(0, 0);
	_lazer_move = _p_pos - _lazer_pos;
	_lazer_speed = 0.02f;
	sound.EffectInit("Sound/beamgun.mp3");
}


Enemy_UFO::~Enemy_UFO()
{

}

void Enemy_UFO::Init()
{
	_lazer->stopSystem();
}


void Enemy_UFO::Update(cocos2d::Vec2 Player_pos)
{
	Move(Player_pos);
}

void Enemy_UFO::Move(cocos2d::Vec2 Player_pos)
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
			Action(Player_pos);
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

		//ƒŒ[ƒU[‚ÌˆÚ“®ˆ—
		if (_lazer->isActive())
		{
			_lazer_pos += _lazer_move * _lazer_speed;
			_lazer->setPosition(_lazer_pos);
		}

	}
}

void Enemy_UFO::Action(cocos2d::Vec2 Player_pos)
{
	_repeat_time--;

	if (_repeat_time == 60 * 1)
	{
		_lazer_pos = _pos;
		_lazer->setPosition(_lazer_pos);
		_lazer->resetSystem();
		sound.EffectPlay(false);
		_p_pos = Player_pos;
		_lazer_move = _p_pos - _lazer_pos;
	}

	if (_repeat_time == 0)
	{	
		_mode = END;
	}
}

cocos2d::Sprite* Enemy_UFO::getUFOTexture(){ return _texture; }

bool Enemy_UFO::ActiveCheck(){ return _active; }

cocos2d::Vec2 Enemy_UFO::getEnemyPos(){ return _pos; }

cocos2d::Vec2 Enemy_UFO::getLazerPos(){ return _lazer_pos; }

