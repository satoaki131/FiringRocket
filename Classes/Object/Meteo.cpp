#include "Object/Meteo.h"


Meteo::Meteo()
{
	_pos = cocos2d::Vec2(0, 0);
	//_part = cocos2d::ParticleSystemQuad::create("Particle/Meteo.plist");
	//_part->stopSystem();
	_texture = cocos2d::Sprite::create("Texture/Meteo.png");
	_texture->setScale(0.4f);
	_texture->setPosition(_pos);
	angle = 0.0f;
}


Meteo::~Meteo()
{
}


void Meteo::Update()
{
	setRot();
	Move();
}

void Meteo::Move()
{
	//if(_part->isActive())_part->setPosition(_pos);

}

void Meteo::setRot()
{
	angle++;
	_texture->setRotation(angle);
}

cocos2d::Vec2 Meteo::getPos(){ return _pos; }


cocos2d::Sprite* Meteo::getTexture(){ return _texture; }

