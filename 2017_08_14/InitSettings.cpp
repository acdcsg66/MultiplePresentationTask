#include "InitSettings.h"
#include <string>

extern "C" {// C����ŏ������邽�߃R�s�[
	double c_prsp = InitSettings::PRESENT_SPEED;
	int c_nuam = InitSettings::NUM_AMOUNT;
}
using namespace std;

int InitSettings::NUM_AMOUNT = 3; // ��x�ɒ񎦂��鐔���̗�
int InitSettings::MIN_NUM = 0; // �񎦂��鐔���̍ŏ��l
int InitSettings::MAX_NUM = 8; // �񎦂��鐔���̍ő�l
double InitSettings::PRESENT_SPEED = 7.0; // ������񎦂���Ԋu�i�b�j
int InitSettings::TRIAL_AMOUNT = 250; // ��萔
int InitSettings::N_BACK_AMOUNT = 2; // �un-back�ۑ�v��n
string InitSettings::PRESENT_ORDER = "random"; // �����̒񎦏� 

void InitSettings::initSet() {
	//ToDo: �ݒ��csv����ǂݍ��߂�悤��

}