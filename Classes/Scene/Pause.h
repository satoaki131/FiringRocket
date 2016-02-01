#ifndef __PAUSE_H__
#define __PAUSE_H__

#include "cocos2d.h"

class Pause : public cocos2d::Layer
{
private:
	cocos2d::Size visibleSize;
public:
	static cocos2d::Scene* scene();
	virtual bool init();
	virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

	CREATE_FUNC(Pause);
};

#endif // !__PAUSE_H__
