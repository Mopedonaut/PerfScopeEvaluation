/*
 * main.cpp
 *
 *  Created on: May 28, 2015
 *      Author: mark
 */
//#include <iostream>
#include <unistd.h>

void unfrequentFunctionLevel6() {
	// no op
}

void unfrequentFunctionLevel5(int level) {
	while (level > 5) {
		unfrequentFunctionLevel6();
		--level;
	}
}

void unfrequentFunctionLevel4(int level) {
	if (level > 4) {
		unfrequentFunctionLevel5(level);
	}
}

void expensiveFuntion() {
//	cout << "Zzzzzz...." << endl;
	usleep(500);
//	cout << "Zzzzzz...." << endl;
}

void unfrequentFunctionLevel3(int level) {
	if (level > 3) {
		unfrequentFunctionLevel4(level);
	}
}

void unfrequentFunctionLevel2(int level) {
	if (level > 2) {
		unfrequentFunctionLevel3(level);
	}
}

void unfrequentFunctionLevel1(int level) {
	if (level > 1) {
		unfrequentFunctionLevel2(level);
	}
}

void unusedFunction() {
}

void frequentFunction() {
	// does nothing
}

int main() {
	unfrequentFunctionLevel1(4);

	for (int i = 0; i < 100; ++i) {
		frequentFunction();
	}
	return 0;
}

