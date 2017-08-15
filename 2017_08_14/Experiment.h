#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include<vector>
#include "InitSettings.h"

class Experiment {
private:
	std::vector< std::vector<int> > resultNums; // nバック前までの提示された数字の記録 resultNews[バック数+1][提示する数字の量]
	int answer; // nバック前の一致する数字の数（答え）
public:
	Experiment() {
		resultNums.resize(InitSettings::N_BACK_AMOUNT+1);
		for (int i = 0; i<InitSettings::N_BACK_AMOUNT+1; ++i) {
			resultNums[i].resize(InitSettings::NUM_AMOUNT);
		}
	};
	virtual ~Experiment() {};
	void experiment(); // 実験を行う
};

#endif