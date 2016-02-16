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
	static cocos2d::UserDefault* _userDefault;
	static bool HighscoreCheck(int &score);
	static cocos2d::Label* Update(int size);
	static cocos2d::Label* Init(int size);
	static cocos2d::Label* DisplayScore(int size, int score);
	static void ResetScore();
	static void ResetHighScore(); //発表デバック用
	static int getNowScore();
	static int getHighScore();
};

#endif // !__SCORE_H__
