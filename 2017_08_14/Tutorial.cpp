#include <iostream>
#include "Tutorial.h"
#include"InitSettings.h"

using namespace std;

void Tutorial::showTutorial() {

	cout << "チュートリアルを表示しますか？ (y/n) > " << flush;
	cin >> flg;
	if (flg == 'y') {
		cout << "このテストではn回前と一致するマスの数を答えていきます。" << endl;
		cout << "たとえば、2回前と一致するマスの数を答えるテストを例に挙げます。" << endl << endl;
		cout << "1: □□■  2: □■■  3: ■□□  4: ■□■" << endl;
		cout << "   ■□■     □■■     □■■     □■■" << endl;
		cout << "   ■□□     □□□     □□■     □□□" << endl <<endl;
		cout << "と、順番に表示された場合、「3」の時点で2回前、「1」の■と一致するマスの数を入力します。" << endl;
		cout << "今回の場合は1（半角英数字で入力）です。" << endl << endl;;
		cout << "一定時間が経過すると、正誤に応じて〇か×が表示され、次の画像「4」が表示されます。" << endl;
		cout << "「4」の時点で2回前は「2」なので、「4」と「2」で一致する■のマスの数を入力します。" << endl;
		cout << "この場合は3が正解になります。" << endl << endl;
		cout << "なお、はじめの「1」と「2」の時点では2回前に該当するマスがありませんので、回答の入力はしません。" << endl << endl;
	}

	cout << "今回のテストではn=" << InitSettings::N_BACK_AMOUNT << "（" << InitSettings::N_BACK_AMOUNT << "回前を答える）です。" << endl;
	cout << "それではテストを開始します。" << flush;
	system("pause");
	system("cls");
}
