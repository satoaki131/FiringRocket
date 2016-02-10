#ifndef __METEO_H__
#define __METEO_H__

#include "cocos2d.h"

class Meteo
{
private:
	cocos2d::Vec2 _pos;
	cocos2d::Sprite* _texture;
	float _angle;
	bool _active;
	cocos2d::Size visibleSize;
	int _randomPoint;
	int _repeat_time;
	cocos2d::Vec2 _p_pos;
	cocos2d::Vec2 _move_pos;
	float _move_speed;
public:
	cocos2d::ParticleSystemQuad* _part;

	Meteo();
	~Meteo();

	void Update(cocos2d::Vec2 player_pos);
	void Move(cocos2d::Vec2 player_pos);
	void setRot();
	cocos2d::Vec2 getPos();
	cocos2d::Sprite* getTexture();
};

#endif // !__METEO_H__
