#ifndef __ENEMY_UFO_H__
#define __ENEMY_UFO_H__

#include "cocos2d.h"

enum
{
	START,
	ACTION,
	END
};

class Enemy_UFO
{
private:
	cocos2d::Sprite* _texture;
	cocos2d::Vec2 _pos;
	bool _active; //ê∂Ç´ÇƒÇÈÇ©éÄÇÒÇ≈ÇÈÇ©
	int _repeat_time;
	int _randomPoint;
	int _mode;
	bool _drawTexture;
public:

	void Update();
	Enemy_UFO();
	~Enemy_UFO();
	void Move();
	void Action();
	cocos2d::Sprite* getUFOTexture();
	bool ActiveCheck();
	int TimeCheck();
	//bool setdrawTexture(bool &active);
};

#endif // !__ENEMY_UFO_H__
