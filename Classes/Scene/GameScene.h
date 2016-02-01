#ifndef __GAME_SCENE_H__ //1ìxIncludeÇµÇΩÇÁÅAÇ‡Ç§ÇµÇ»Ç¢èàóù
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Object/Player.h"
#include "Scene/Pause.h"

class GameScene : public cocos2d::Layer
{
private:
	cocos2d::Size visibleSize;
	Player player;
public:
	virtual bool init();
	static cocos2d::Scene* scene();
	
	virtual void update(float delta);
	virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	CREATE_FUNC(GameScene);

};


#endif //__GAME_SCENE_H__