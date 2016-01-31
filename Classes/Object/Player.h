#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"

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
	cocos2d::Vec2 _moveamount; //ˆÚ“®—Ê
	float _movespeed;

public:
	cocos2d::EventListenerKeyboard* keylistener;
	Player();
	~Player();

	void Update();
	void Init(cocos2d::EventDispatcher* dispatcher, cocos2d::Node* node, cocos2d::Size window_size);
	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	void onKeyRereased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	void setPos();
	void setRot();
	cocos2d::Sprite* getPlayerTexture();
	void MoveAction();
	cocos2d::ParticleSystemQuad* _fire;

};

#endif