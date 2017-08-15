#include<string>
#include<stdio.h>
#include "NumGenerator.h"
#include "InitSettings.h"

using namespace std;

int* NumGenerator::numGenerate(int amount, int min, int max, string order){
	int* candidate = new int[max - min + 1];
	for (int i = 0, j=min; i < (max-min+1); ++i) {
		candidate[i] = j;
		++j;
	}
	for (int i = 0; i < amount; ++i) {
		int j = (int)( rand() % (max - min + 1 - i) );
		numbers[i] = candidate[j];
		for (int k = j; k < (max - min - i); ++k) {
			candidate[k] = candidate[k + 1];
		}
	}
	// Todo: order‚É‚æ‚Á‚Ä”z—ñ‚ÌŠi”[‚Ì‡”Ô‚ð•Ï‚¦‚é
	delete[] candidate;
	return numbers;
}
