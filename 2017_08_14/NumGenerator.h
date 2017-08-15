#include<string>
#include <time.h>
#include "InitSettings.h"

class NumGenerator {
private:
	int* numbers; // ¶¬‚µ‚½”š‚ğ”z—ñ‚ÉŠi”[
public:
	NumGenerator() { numbers = new int[InitSettings::NUM_AMOUNT]; srand((unsigned int)time(NULL));};
	virtual ~NumGenerator() { delete[] numbers; };
	int* numGenerate(int amount, int min, int max, std::string order); // min‚©‚çmax‚Ì”ÍˆÍ‚Åamount‚¾‚¯”š‚ğ¶¬Border‚Å‡”Ô‚ğw’è
	int* getNumbers() { return numbers; }
};