#include<string>
#include <time.h>
#include "InitSettings.h"

class NumGenerator {
private:
	int* numbers; // 生成した数字を配列に格納
public:
	NumGenerator() { numbers = new int[InitSettings::NUM_AMOUNT]; srand((unsigned int)time(NULL));};
	virtual ~NumGenerator() { delete[] numbers; };
	int* numGenerate(int amount, int min, int max, std::string order); // minからmaxの範囲でamountだけ数字を生成。orderで順番を指定
	int* get_numbers() { return numbers; }
};