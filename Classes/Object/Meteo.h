#ifndef __METEO_H__
#define __METEO_H__

#include "cocos2d.h"

class Meteo
{
private:
	cocos2d::Vec2 _pos;
	cocos2d::Sprite* _texture;
	float angle;
public:
	cocos2d::ParticleSystemQuad* _part;

	Meteo();
	~Meteo();

	void Update();
	void Move();
	void setRot();
	cocos2d::Vec2 getPos();
	cocos2d::Sprite* getTexture();
};

#endif // !__METEO_H__
