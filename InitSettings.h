#ifndef INIT_SETTING_H
#define INIT_SETTING_H

#include <string>

class InitSettings {
public:
	static int NUM_AMOUNT; // ��x�ɒ񎦂��鐔���̗�
	static int MIN_NUM; // �񎦂��鐔���̍ŏ��l
	static int MAX_NUM; // �񎦂��鐔���̍ő�l
	static double PRESENT_SPEED; // ������񎦂���Ԋu�i�b�j
	static int TRIAL_AMOUNT; // ��萔
	static int N_BACK_AMOUNT; // �un-back�ۑ�v��n
	static std::string PRESENT_ORDER; // �����̒񎦏� 
public:
	InitSettings() {};
	virtual ~InitSettings() {};
	void initSet(); // ��L�̕ϐ���������
};

#endif