#ifndef TUTORIAL_H
#define TUTORIAL_H

class Tutorial {
private:
	char flg; // チュートリアルを表示するかどうかのフラグ
public:
	Tutorial() {};
	virtual ~Tutorial() {};
	void showTutorial(); // チュートリアルを表示
};

#endif