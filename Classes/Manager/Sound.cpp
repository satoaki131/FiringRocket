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
	//���炩���ߓǂݍ���ł������ق����ǂ�(���Ȃ��Ă������邪�A�T�C�Y�ɂ���Ă͏������x���Ȃ邽�߁A����Ă������ق����ǂ�)
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


void Sound::EffectInit(char* path)
{
	file_path = path;
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect(file_path);
}


void Sound::EffectPlay(bool loop)
{
	if (file_path == nullptr)return;
	if (loop)
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(file_path, true);
	}
	else
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(file_path, false);
	}
}


void Sound::EffectStop()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopEffect(true);
}



