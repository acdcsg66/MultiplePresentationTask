#include<iostream>
#include <Windows.h>
#include "Experiment.h"
#include "InitSettings.h"
#include "NumGenerator.h"
#include "ShowNumThenAns.h"

using namespace std;

void Experiment::experiment() {
	NumGenerator ng;
	ShowNumThenAns snta;
	int ansNum;
	int* ng_numbers = ng.get_numbers(); // NumGeneratorから生成された数の配列を指すポインタ
	// ToDo: RecordResultの追加

	//n-backのn回だけ初めに数字群を表示
	for (int i = 0; i < InitSettings::N_BACK_AMOUNT; ++i) {
		system("cls");
		ng.numGenerate(InitSettings::NUM_AMOUNT, InitSettings::MIN_NUM, InitSettings::MAX_NUM, InitSettings::PRESENT_ORDER);
		snta.showNum(ng_numbers, InitSettings::NUM_AMOUNT);
		for (int j = 0; j < InitSettings::NUM_AMOUNT; ++j){
			resultNums[i][j] = ng_numbers[j];
		//	cout << "resultNums[" << i << "][" << j << "]=" << resultNums[i][j] << endl; // debug
		}
		Sleep(InitSettings::PRESENT_SPEED * 1000);
	}
	for (int i = 0; i < InitSettings::TRIAL_AMOUNT; ++i) {
		ng.numGenerate(InitSettings::NUM_AMOUNT, InitSettings::MIN_NUM, InitSettings::MAX_NUM, InitSettings::PRESENT_ORDER);
		snta.showNum(ng_numbers, InitSettings::NUM_AMOUNT);
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
		snta.showResult(ansNum);
		Sleep(500);

		//for (int j = 0; j < InitSettings::N_BACK_AMOUNT + 1; ++j) {
		//	for (int k = 0; k < InitSettings::NUM_AMOUNT; ++k) {
		//		cout << "resultNums[" << j << "][" << k << "]=" << resultNums[j][k] << endl; // debug
		//	}
		//}
		//提示された数字の記録をずらす
		for (int j = 0; j < InitSettings::N_BACK_AMOUNT; ++j) {
			for (int k = 0; k < InitSettings::NUM_AMOUNT; ++k) {
				resultNums[j][k] = resultNums[j+1][k];
			}
		}
	}

	cout << "正答数：" << snta.get_correctAnsNum() << endl;
	Sleep(10000);
}
