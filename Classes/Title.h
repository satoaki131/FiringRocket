#ifndef __TITLE_H__ //1度Includeしたら、もうしない処理
#define __TITLE_H__

#include "cocos2d.h"

class Title : public cocos2d::Layer
{
	int run;
public:
	virtual bool init();
	static cocos2d::Scene* scene();

	void Update(float delta);

	CREATE_FUNC(Title);
};

#endif