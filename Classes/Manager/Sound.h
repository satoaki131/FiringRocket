#ifndef __SOUND_MANAGER_H__
#define __SOUND_MANAGER_H__

#include "cocos2d.h"

class Sound
{
private:
	char* file_path;
public:
	Sound();
	Sound(char* path);
	~Sound();

	void BGMInit(char* path);
	void BGMPlay(bool loop);
	void BGMStop();
	
	void EffectInit(char* path);
	
};

#endif