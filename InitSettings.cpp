#include "InitSettings.h"
#include <string>

using namespace std;

int InitSettings::NUM_AMOUNT = 2; // 一度に提示する数字の量
int InitSettings::MIN_NUM = 1; // 提示する数字の最小値
int InitSettings::MAX_NUM = 4; // 提示する数字の最大値
double InitSettings::PRESENT_SPEED = 7.0; // 数字を提示する間隔（秒）
int InitSettings::TRIAL_AMOUNT = 250; // 問題数
int InitSettings::N_BACK_AMOUNT = 4; // 「n-back課題」のn
string InitSettings::PRESENT_ORDER = "random"; // 数字の提示順 

void InitSettings::initSet() {
	//ToDo: 設定をcsvから読み込めるように

}