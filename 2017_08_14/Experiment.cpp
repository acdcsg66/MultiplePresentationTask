#include<iostream>
#include <thread>
#include <windows.h>
#include "Experiment.h"
#include "InitSettings.h"
#include "NumGenerator.h"
#include "ShowNumThenAns.h"

extern "C" {
#include "Window.h"

extern int* c_numbers; // C�t�@�C���Ŏg��NumGenerator::numbers
extern int c_flag; // �񓚂Ɖ摜�\���𓯊�
}

using namespace std;

void Experiment::experiment() {
	NumGenerator ng;
	ShowNumThenAns snta;
	int ansNum;
	int* ng_numbers = ng.getNumbers(); // NumGenerator���琶�����ꂽ���̔z����w���|�C���^
	c_numbers = ng.getNumbers(); // C����ŕ`�揈�����邽�߂ɂ�����ɂ��R�s�[
	thread th;
	// ToDo: RecordResult�̒ǉ�

	th = thread([] { openWindow(GetModuleHandle(NULL), NULL, NULL, SW_SHOWDEFAULT); }); // �摜��\��
	//n-back��n�񂾂����߂ɐ����Q��\��
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
	//�񓚊J�n
	for (int i = 0; i < InitSettings::TRIAL_AMOUNT; ++i) {
		system("cls");
		ng.numGenerate(InitSettings::NUM_AMOUNT, InitSettings::MIN_NUM, InitSettings::MAX_NUM, InitSettings::PRESENT_ORDER);
		c_flag = 1;
		//snta.showNum(ng_numbers, InitSettings::NUM_AMOUNT);

		for (int j = 0; j < InitSettings::NUM_AMOUNT; ++j) {
			resultNums[InitSettings::N_BACK_AMOUNT][j] = ng_numbers[j];
		}
		//Experiment::answer�̍X�V
		ansNum = 0;
		for (int j = 0; j < InitSettings::NUM_AMOUNT; ++j) {
			for (int k = 0; k < InitSettings::NUM_AMOUNT; ++k) {
				if (resultNums[0][j] == ng_numbers[k]) ansNum++;
			}
		}
		snta.answer();
		snta.showResult(ansNum); // ���ʂ�\��
		Sleep(500);

		//�񎦂��ꂽ�����̋L�^�����炷
		for (int j = 0; j < InitSettings::N_BACK_AMOUNT; ++j) {
			for (int k = 0; k < InitSettings::NUM_AMOUNT; ++k) {
				resultNums[j][k] = resultNums[j+1][k];
			}
		}
	}

	cout << "�������F" << snta.get_correctAnsNum() << endl;
	Sleep(10000);
	th.join();
}
