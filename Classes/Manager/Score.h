#ifndef __SCORE_H__
#define __SCORE_H__

#include "cocos2d.h"

class Score
{
private:
	static int _score;
	static int _highscore;
	static std::string _text;
public:
	Score();
	~Score();

	void HighscoreUpdate(int &score);
	static cocos2d::Label* Update();
	static cocos2d::Label* Init();
	

};

#endif // !__SCORE_H__
