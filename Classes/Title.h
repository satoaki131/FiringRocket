#ifndef __TITLE_H__ //1�xInclude������A�������Ȃ�����
#define __TITLE_H__

#include "cocos2d.h"

class Title : public cocos2d::Layer
{
	int run;
public:
	virtual bool init();
	static cocos2d::Scene* scene();

	void Update(float delta);
	virtual void onMouseDown(cocos2d::Event* event);

	CREATE_FUNC(Title);
};

#endif