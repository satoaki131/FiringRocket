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
	//あらかじめ読み込んでおいたほうが良い(やらなくてもいけるが、サイズによっては処理が遅くなるため、やっておいたほうが良い)
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

void Sound::BGMStop()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
}

void Sound::BGMPause()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

void Sound::BGMResumPlay()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}


void Sound::EffectInit(char* path)
{
	file_path = path;
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect(file_path);
}


void Sound::EffectPlay(bool loop, float pitch, float pan, float gain)
{
	if (file_path == nullptr)return;
	if (loop)
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(file_path, true, pitch, pan, gain);
	}
	else
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(file_path, false, pitch, pan, gain);
	}
}


void Sound::EffectStop()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopEffect(true);
}



