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
	void BGMPause();
	void BGMResumPlay();
	
	void EffectInit(char* path);
	void EffectPlay(bool loop, float pitch = 1.0f, float pan = 1.0f, float gain = 1.0f);
	void EffectStop();
	
};

#endif