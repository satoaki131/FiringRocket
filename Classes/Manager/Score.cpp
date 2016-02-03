#include "Score.h"

int Score::_score;
int Score::_highscore;
std::string Score::_text;
Score::Score()
{
	_text = "Score : ";
	
}


Score::~Score()
{
}

void Score::HighscoreUpdate(int &score)
{
	if (score > _highscore)
	{
		_highscore = score;
	}
}


cocos2d::Label* Score::Update()
{
	_score++;
	auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	auto label = cocos2d::Label::createWithTTF(cocos2d::StringUtils::toString(_score), "fonts/JKG-M_3.ttf", 30);
	label->setPosition(visibleSize.width - 60, visibleSize.height - 20);

	return label;
}

cocos2d::Label* Score::Init()
{
	auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	auto label = cocos2d::Label::createWithTTF(_text, "fonts/JKG-M_3.ttf", 30);
	label->setPosition(visibleSize.width - 170, visibleSize.height - 20);

	return label;
}

