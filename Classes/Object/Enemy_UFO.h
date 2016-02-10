#ifndef __ENEMY_UFO_H__
#define __ENEMY_UFO_H__

#include "cocos2d.h"


class Enemy_UFO
{
private:
	enum
	{
		START,
		ACTION,
		END
	};
	cocos2d::Sprite* _texture;
	cocos2d::Vec2 _pos;
	bool _active; //ê∂Ç´ÇƒÇÈÇ©éÄÇÒÇ≈ÇÈÇ©
	int _repeat_time;
	int _randomPoint;
	int _mode;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 _lazer_pos;
	cocos2d::Vec2 _p_pos;
	cocos2d::Vec2 _lazer_move;
	float _lazer_speed;
public:
	cocos2d::ParticleSystemQuad* _lazer;

	void Init();
	void Update(cocos2d::Vec2 Player_pos);
	Enemy_UFO();
	~Enemy_UFO();
	void Move(cocos2d::Vec2 Player_pos);
	void Action(cocos2d::Vec2 Player_pos);
	cocos2d::Sprite* getUFOTexture();
	bool ActiveCheck();
	cocos2d::Vec2 getEnemyPos();
	cocos2d::Vec2 getLazerPos();
};

#endif // !__ENEMY_UFO_H__
