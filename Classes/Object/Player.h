#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"

class Player
{
	cocos2d::Vec2 _pos;
public:
	cocos2d::Sprite* texture;
	cocos2d::EventListenerKeyboard* keylistener;
	Player();
	~Player();

	void Update();
	void KeyInit(cocos2d::EventDispatcher* dispatcher, cocos2d::Node* node);
	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	void setPos(cocos2d::Vec2 window_size, cocos2d::Vec2 origin);

};

#endif