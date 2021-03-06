#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"
#include "Manager/Sound.h"

enum{
	LEFT,
	RIGHT
};

class Player
{
	static const int Key = 2;
	float _rad;
	float _angle;
	cocos2d::Sprite* _texture;
	bool _keyPressed[Key];
	cocos2d::Vec2 _pos;
	cocos2d::Vec2 _movepos;
	cocos2d::Vec2 _moveamount; //�ړ���
	float _movespeed;
	cocos2d::Vec2 _fire_pos[2];
	float _fire_angle[2];
	float _fire_rad[2];
	cocos2d::Vec2 _fire_move[2];
	cocos2d::Size _visiblesize;
public:
	Sound _sound;
	cocos2d::EventListenerKeyboard* keylistener;
	Player();
	~Player();

	void Update();
	void Init(cocos2d::EventDispatcher* dispatcher, cocos2d::Node* node, cocos2d::Size window_size);
	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	void onKeyRereased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	void setPos();
	void setRot();
	cocos2d::Vec2 getPos();
	cocos2d::Sprite* getPlayerTexture();
	void MoveAction();
	cocos2d::ParticleSystemQuad* _fire[2];
	void setPos(cocos2d::Vec2 set_pos);
	void TitleMove();

};

#endif