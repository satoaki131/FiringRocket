#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"

class Player
{
	cocos2d::Vec2 _pos;
	float _angle;
	cocos2d::Sprite* _texture;

public:
	cocos2d::EventListenerKeyboard* keylistener;
	Player();
	~Player();

	void Update(cocos2d::Vec2 window_size, cocos2d::Vec2 origin);
	void KeyInit(cocos2d::EventDispatcher* dispatcher, cocos2d::Node* node);
	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	void setPos(cocos2d::Vec2 window_size, cocos2d::Vec2 origin);
	void setRot();
	cocos2d::Sprite* getPlayerTexture();


};

#endif