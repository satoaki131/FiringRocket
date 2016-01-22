#ifndef __GAME_SCENE_H__ //1ìxIncludeÇµÇΩÇÁÅAÇ‡Ç§ÇµÇ»Ç¢èàóù
#define __GAME_SCENE_H__

#include "cocos2d.h"

class GameScene : public cocos2d::Layer
{
public:
	virtual bool init();
	static cocos2d::Scene* CreateScene();
	
	void Update(float delta);

	CREATE_FUNC(GameScene);

};


#endif //__GAME_SCENE_H__