#include <iostream>
#include "Tutorial.h"

using namespace std;

void Tutorial::showTutorial() {

	cout << "�`���[�g���A����\�����܂����H (y/n) > " << flush;
	cin >> flg;
	if (flg == 'y') {
		//Todo: �����Ƀ`���[�g���A����\��
	}
	cout << "����ł̓e�X�g���J�n���܂��B" << flush;
	system("pause");
	system("cls");
}
