#ifndef SHOW_NUM_THEN_ANS_H
#define SHOW_NUM_THEN_ANS_H

class ShowNumThenAns {
private:
	int ansFromPerson; // n�o�b�N�O�̈�v���鐔���̐��A�팱�҂���̉�
	int presentTrial; // ���݂̎��s��
	int correctAnsNum; // ������
public:
	ShowNumThenAns() { presentTrial = 0; correctAnsNum = 0; };
	virtual ~ShowNumThenAns() {};
	void showNum(int* array, int loopNum); // NumGenerator�Ő������������̔z������ɕ\��
	void answer(); // ��(�Z�Z�^�~�~)�F��\�����An�o�b�N�O�̈�v���鐔���̐�����
	void showResult(int ans); // answer�œ��͂����񓚂ɂ���āh�Z�h�܂��́h�~�h��\��
	int get_correctAnsNum() { return correctAnsNum; }
};

#endif