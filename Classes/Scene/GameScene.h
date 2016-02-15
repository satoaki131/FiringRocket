#ifndef __GAME_SCENE_H__ //1ìxIncludeÇµÇΩÇÁÅAÇ‡Ç§ÇµÇ»Ç¢èàóù
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Object/Player.h"
#include "Scene/Pause.h"
#include "Manager/Score.h"
#include "Object/Enemy_UFO.h"
#include "Object/Meteo.h"
#include "Manager/Sound.h"

class GameScene : public cocos2d::Layer
{
private:
	cocos2d::Size visibleSize;
	cocos2d::Label* _score;
	Player player;
	Enemy_UFO enemy_ufo;
	std::vector<Meteo> meteo;
	std::vector<cocos2d::DrawNode*> _background;
	std::vector<cocos2d::Vec2> _backgroundpos;
	Sound sound;
public:
	virtual bool init();
	static cocos2d::Scene* scene();

	virtual void update(float delta);
	virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	void Collision();
	void BackGroundMove();
	void MeteoCreater();
	CREATE_FUNC(GameScene);

};


#endif //__GAME_SCENE_H__