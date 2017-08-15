#include<iostream>
#include <thread>
#include <windows.h>
#include "Experiment.h"
#include "InitSettings.h"
#include "NumGenerator.h"
#include "ShowNumThenAns.h"

extern "C" {
#include "Window.h"

extern int* c_numbers; // Cファイルで使うNumGenerator::numbers
extern int c_flag; // 回答と画像表示を同期
}

using namespace std;

void Experiment::experiment() {
	NumGenerator ng;
	ShowNumThenAns snta;
	int ansNum;
	int* ng_numbers = ng.getNumbers(); // NumGeneratorから生成された数の配列を指すポインタ
	c_numbers = ng.getNumbers(); // C言語で描画処理するためにこちらにもコピー
	thread th;
	// ToDo: RecordResultの追加

	th = thread([] { openWindow(GetModuleHandle(NULL), NULL, NULL, SW_SHOWDEFAULT); }); // 画像を表示
	//n-backのn回だけ初めに数字群を表示
	for (int i = 0; i < InitSettings::N_BACK_AMOUNT; ++i) {
		system("cls");
		ng.numGenerate(InitSettings::NUM_AMOUNT, InitSettings::MIN_NUM, InitSettings::MAX_NUM, InitSettings::PRESENT_ORDER);
		c_flag = 1;
		//snta.showNum(ng_numbers, InitSettings::NUM_AMOUNT);

		for (int j = 0; j < InitSettings::NUM_AMOUNT; ++j){
			resultNums[i][j] = ng_numbers[j];
		}
		Sleep(InitSettings::PRESENT_SPEED * 1000);
	}
	//回答開始
	for (int i = 0; i < InitSettings::TRIAL_AMOUNT; ++i) {
		system("cls");
		ng.numGenerate(InitSettings::NUM_AMOUNT, InitSettings::MIN_NUM, InitSettings::MAX_NUM, InitSettings::PRESENT_ORDER);
		c_flag = 1;
		//snta.showNum(ng_numbers, InitSettings::NUM_AMOUNT);

		for (int j = 0; j < InitSettings::NUM_AMOUNT; ++j) {
			resultNums[InitSettings::N_BACK_AMOUNT][j] = ng_numbers[j];
		}
		//Experiment::answerの更新
		ansNum = 0;
		for (int j = 0; j < InitSettings::NUM_AMOUNT; ++j) {
			for (int k = 0; k < InitSettings::NUM_AMOUNT; ++k) {
				if (resultNums[0][j] == ng_numbers[k]) ansNum++;
			}
		}
		snta.answer();
		snta.showResult(ansNum); // 結果を表示
		Sleep(500);

		//提示された数字の記録をずらす
		for (int j = 0; j < InitSettings::N_BACK_AMOUNT; ++j) {
			for (int k = 0; k < InitSettings::NUM_AMOUNT; ++k) {
				resultNums[j][k] = resultNums[j+1][k];
			}
		}
	}

	cout << "正答数：" << snta.get_correctAnsNum() << endl;
	Sleep(10000);
	th.join();
}
