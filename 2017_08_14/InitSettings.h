#ifndef INIT_SETTING_H
#define INIT_SETTING_H

#include <string>

class InitSettings {
public:
	static int NUM_AMOUNT; // 一度に提示する数字の量
	static int MIN_NUM; // 提示する数字の最小値
	static int MAX_NUM; // 提示する数字の最大値
	static double PRESENT_SPEED; // 数字を提示する間隔（秒）
	static int TRIAL_AMOUNT; // 問題数
	static int N_BACK_AMOUNT; // 「n-back課題」のn
	static std::string PRESENT_ORDER; // 数字の提示順 
public:
	InitSettings() {};
	virtual ~InitSettings() {};
	void initSet(); // 上記の変数を初期化
};

#endif