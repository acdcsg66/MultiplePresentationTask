#include <iostream>
#include "Tutorial.h"
#include"InitSettings.h"

using namespace std;

void Tutorial::showTutorial() {

	cout << "�`���[�g���A����\�����܂����H (y/n) > " << flush;
	cin >> flg;
	if (flg == 'y') {
		cout << "���̃e�X�g�ł�n��O�ƈ�v����}�X�̐��𓚂��Ă����܂��B" << endl;
		cout << "���Ƃ��΁A2��O�ƈ�v����}�X�̐��𓚂���e�X�g���ɋ����܂��B" << endl << endl;
		cout << "1: ������  2: ������  3: ������  4: ������" << endl;
		cout << "   ������     ������     ������     ������" << endl;
		cout << "   ������     ������     ������     ������" << endl <<endl;
		cout << "�ƁA���Ԃɕ\�����ꂽ�ꍇ�A�u3�v�̎��_��2��O�A�u1�v�́��ƈ�v����}�X�̐�����͂��܂��B" << endl;
		cout << "����̏ꍇ��1�i���p�p�����œ��́j�ł��B" << endl << endl;;
		cout << "��莞�Ԃ��o�߂���ƁA����ɉ����āZ���~���\������A���̉摜�u4�v���\������܂��B" << endl;
		cout << "�u4�v�̎��_��2��O�́u2�v�Ȃ̂ŁA�u4�v�Ɓu2�v�ň�v���遡�̃}�X�̐�����͂��܂��B" << endl;
		cout << "���̏ꍇ��3�������ɂȂ�܂��B" << endl << endl;
		cout << "�Ȃ��A�͂��߂́u1�v�Ɓu2�v�̎��_�ł�2��O�ɊY������}�X������܂���̂ŁA�񓚂̓��͂͂��܂���B" << endl << endl;
	}

	cout << "����̃e�X�g�ł�n=" << InitSettings::N_BACK_AMOUNT << "�i" << InitSettings::N_BACK_AMOUNT << "��O�𓚂���j�ł��B" << endl;
	cout << "����ł̓e�X�g���J�n���܂��B" << flush;
	system("pause");
	system("cls");
}
