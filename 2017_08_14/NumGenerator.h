#include<string>
#include <time.h>
#include "InitSettings.h"

class NumGenerator {
private:
	int* numbers; // ��������������z��Ɋi�[
public:
	NumGenerator() { numbers = new int[InitSettings::NUM_AMOUNT]; srand((unsigned int)time(NULL));};
	virtual ~NumGenerator() { delete[] numbers; };
	int* numGenerate(int amount, int min, int max, std::string order); // min����max�͈̔͂�amount���������𐶐��Border�ŏ��Ԃ��w��
	int* getNumbers() { return numbers; }
};