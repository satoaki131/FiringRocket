#ifndef __RESULT_H__
#define __RESULT_H__

#include "cocos2d.h"

class Result : public cocos2d::Layer
{
private:
public:
	cocos2d::Scene* scene();
	virtual bool init();

	CREATE_FUNC(Result);
};

#endif // !__RESULT_H__
