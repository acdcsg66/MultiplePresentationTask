#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include<vector>
#include "InitSettings.h"

class Experiment {
private:
	std::vector< std::vector<int> > resultNums; // n�o�b�N�O�܂ł̒񎦂��ꂽ�����̋L�^ resultNews[�o�b�N��+1][�񎦂��鐔���̗�]
	int answer; // n�o�b�N�O�̈�v���鐔���̐��i�����j
public:
	Experiment() {
		resultNums.resize(InitSettings::N_BACK_AMOUNT+1);
		for (int i = 0; i<InitSettings::N_BACK_AMOUNT+1; ++i) {
			resultNums[i].resize(InitSettings::NUM_AMOUNT);
		}
	};
	virtual ~Experiment() {};
	void experiment(); // �������s��
};

#endif