#ifndef __TITLE_H__ //1ìxIncludeÇµÇΩÇÁÅAÇ‡Ç§ÇµÇ»Ç¢èàóù
#define __TITLE_H__

#include "cocos2d.h"
#include "Manager/Sound.h"
#include "Object/Player.h"
#include "Manager/Score.h"

class Title : public cocos2d::Layer
{
private:
	cocos2d::Vec2 label_pos;
	float label_angle;
	cocos2d::Vec2 background_pos;
	Sound sound;
	cocos2d::Size visibleSize;
	//cocos2d::Vec2 origin;
	Player player;
	Score score;
public:
	virtual bool init();
	static cocos2d::Scene* scene();
	virtual void update(float delta);
	virtual void onMouseDown(cocos2d::Event* event);
	virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

	CREATE_FUNC(Title);
};

#endif