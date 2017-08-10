#include <iostream>
#include "Tutorial.h"

using namespace std;

void Tutorial::showTutorial() {

	cout << "チュートリアルを表示しますか？ (y/n) > " << flush;
	cin >> flg;
	if (flg == 'y') {
		//Todo: ここにチュートリアルを表示
	}
	cout << "それではテストを開始します。" << flush;
	system("pause");
	system("cls");
}
