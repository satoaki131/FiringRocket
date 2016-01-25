#ifndef __TITLE_H__ //1度Includeしたら、もうしない処理
#define __TITLE_H__

#include "cocos2d.h"

class Title : public cocos2d::Layer
{
private:
	cocos2d::Vec2 label_pos;
	float label_angle;
	cocos2d::Vec2 background_pos;
public:
	virtual bool init();
	static cocos2d::Scene* scene();

	virtual void update(float delta);
	virtual void onMouseDown(cocos2d::Event* event);
	virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

	CREATE_FUNC(Title);
};

#endif