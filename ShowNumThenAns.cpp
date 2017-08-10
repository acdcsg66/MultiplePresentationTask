#include <iostream>
#include <chrono>
#include <future>
#include<conio.h>
#include "InitSettings.h"
#include "ShowNumThenAns.h"
#include "Experiment.h"

using namespace std;

void ShowNumThenAns::showNum(int* array, int loopNum) { // NumGeneratorで生成した数字の配列を順に表示
	system("cls");
	for (int i = 0; i < loopNum; ++i) {
		cout << array[i] << "  " << flush;
	}
	cout << endl;
}
void ShowNumThenAns::answer() { // 回答(〇〇／××)：を表示し、nバック前の一致する数字の数を回答
	//cout << "回答（" << presentTrial+1 << "／" << InitSettings::TRIAL_AMOUNT << "）：" << flush;
	//cin >> ansFromPerson;
	//if (ansFromPerson == 999) {
	//	exit(EXIT_SUCCESS);
	//}
	//++presentTrial;

	time_t t, t_work;
	time(&t);
	ansFromPerson = 99999;

	cout << "回答（" << presentTrial+1 << "／" << InitSettings::TRIAL_AMOUNT << "）：" << flush;
	while (1) {
		if (_kbhit()) { /* キーが入力されているかチェックする */
			ansFromPerson = _getch()-'0';
			cout << ansFromPerson << "  ";
		}
		if (ansFromPerson == 999) {
			exit(EXIT_SUCCESS);
		}
		if (ansFromPerson < 0 && ansFromPerson > InitSettings::NUM_AMOUNT) { /* 範囲外の数値は無視 */
			ansFromPerson = 99999;
		}
		//else if (c == '\r' || c == '\n') { /* エンターが押されていたら抜ける */
		//	break;
		//}
		time(&t_work); /* 現在の時間を取得する */
		if ((t + InitSettings::PRESENT_SPEED) < t_work) { /*タイムアウトしたかのチェック */
			break; /*ループから抜ける */
		}
	}
	++presentTrial;
}
void ShowNumThenAns::showResult(int ans){ // answerで入力した回答によって”〇”または”×”を表示
	cout << endl;
	if (ans == ansFromPerson) {
		cout << "〇" << endl;
		correctAnsNum++;
	}
	else {
		cout << "×" << endl;
	}
}