#ifndef SHOW_NUM_THEN_ANS_H
#define SHOW_NUM_THEN_ANS_H

class ShowNumThenAns {
private:
	int ansFromPerson; // nバック前の一致する数字の数、被験者からの回答
	int presentTrial; // 現在の試行数
	int correctAnsNum; // 正答数
public:
	ShowNumThenAns() { presentTrial = 0; correctAnsNum = 0; };
	virtual ~ShowNumThenAns() {};
	void showNum(int* array, int loopNum); // NumGeneratorで生成した数字の配列を順に表示
	void answer(); // 回答(〇〇／××)：を表示し、nバック前の一致する数字の数を回答
	void showResult(int ans); // answerで入力した回答によって”〇”または”×”を表示
	int get_correctAnsNum() { return correctAnsNum; }
};

#endif