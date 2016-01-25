#include "Sound.h"
#include "SimpleAudioEngine.h"

Sound::Sound()
{
	file_path = nullptr;
}

Sound::Sound(char* path)
{
	file_path = path;
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(file_path);
}


Sound::~Sound()
{
}


void Sound::BGMInit(char* path)
{
	file_path = path;
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(file_path);
}

void Sound::BGMPlay(bool loop)
{
	if (file_path == nullptr)return;
	if (loop)
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(file_path, true);
	}
	else
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(file_path, false);
	}

}


void Sound::EffectInit(char* path)
{
	file_path = path;
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect(file_path);
}




