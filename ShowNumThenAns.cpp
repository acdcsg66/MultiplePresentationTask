#include <iostream>
#include <chrono>
#include <future>
#include<conio.h>
#include "InitSettings.h"
#include "ShowNumThenAns.h"
#include "Experiment.h"

using namespace std;

void ShowNumThenAns::showNum(int* array, int loopNum) { // NumGenerator�Ő������������̔z������ɕ\��
	system("cls");
	for (int i = 0; i < loopNum; ++i) {
		cout << array[i] << "  " << flush;
	}
	cout << endl;
}
void ShowNumThenAns::answer() { // ��(�Z�Z�^�~�~)�F��\�����An�o�b�N�O�̈�v���鐔���̐�����
	//cout << "�񓚁i" << presentTrial+1 << "�^" << InitSettings::TRIAL_AMOUNT << "�j�F" << flush;
	//cin >> ansFromPerson;
	//if (ansFromPerson == 999) {
	//	exit(EXIT_SUCCESS);
	//}
	//++presentTrial;

	time_t t, t_work;
	time(&t);
	ansFromPerson = 99999;

	cout << "�񓚁i" << presentTrial+1 << "�^" << InitSettings::TRIAL_AMOUNT << "�j�F" << flush;
	while (1) {
		if (_kbhit()) { /* �L�[�����͂���Ă��邩�`�F�b�N���� */
			ansFromPerson = _getch()-'0';
			cout << ansFromPerson << "  ";
		}
		if (ansFromPerson == 999) {
			exit(EXIT_SUCCESS);
		}
		if (ansFromPerson < 0 && ansFromPerson > InitSettings::NUM_AMOUNT) { /* �͈͊O�̐��l�͖��� */
			ansFromPerson = 99999;
		}
		//else if (c == '\r' || c == '\n') { /* �G���^�[��������Ă����甲���� */
		//	break;
		//}
		time(&t_work); /* ���݂̎��Ԃ��擾���� */
		if ((t + InitSettings::PRESENT_SPEED) < t_work) { /*�^�C���A�E�g�������̃`�F�b�N */
			break; /*���[�v���甲���� */
		}
	}
	++presentTrial;
}
void ShowNumThenAns::showResult(int ans){ // answer�œ��͂����񓚂ɂ���āh�Z�h�܂��́h�~�h��\��
	cout << endl;
	if (ans == ansFromPerson) {
		cout << "�Z" << endl;
		correctAnsNum++;
	}
	else {
		cout << "�~" << endl;
	}
}