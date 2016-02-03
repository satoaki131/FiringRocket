#ifndef __RESULT_H__
#define __RESULT_H__

#include "cocos2d.h"

class Result : public cocos2d::Layer
{
private:
public:
	static cocos2d::Scene* scene();
	virtual bool init();
	virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	CREATE_FUNC(Result);
};

#endif // !__RESULT_H__
