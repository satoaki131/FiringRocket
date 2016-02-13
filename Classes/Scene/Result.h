#ifndef __RESULT_H__
#define __RESULT_H__

#include "cocos2d.h"

class Result : public cocos2d::Layer
{
private:
	cocos2d::Size visiblesize;
	cocos2d::ParticleSystemQuad* fountain;
	cocos2d::Color4B color;
	cocos2d::Label* _highscore_label;
	bool _highscoreflug;
public:
	static cocos2d::Scene* scene();
	virtual bool init();
	virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	virtual void update(float delta);
	CREATE_FUNC(Result);
};

#endif // !__RESULT_H__
