#ifndef __METEO_H__
#define __METEO_H__

#include "cocos2d.h"

class Meteo
{
private:
	cocos2d::Vec2 _pos;
public:
	cocos2d::ParticleSystemQuad* _part;

	Meteo();
	~Meteo();

	void Update();
	void Move();
	cocos2d::Vec2 getPos();
};

#endif // !__METEO_H__
