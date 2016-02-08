#include "Object/Meteo.h"


Meteo::Meteo()
{
	_pos = cocos2d::Vec2(0, 0);
	_part = cocos2d::ParticleSystemQuad::create("Particle/Meteo.plist");
	_part->stopSystem();
}


Meteo::~Meteo()
{
}


void Meteo::Update()
{
	Move();
}

void Meteo::Move()
{

}

cocos2d::Vec2 Meteo::getPos(){ return _pos; }


