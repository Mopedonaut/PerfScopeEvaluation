/*
 * main.cpp
 *
 *  Created on: May 28, 2015
 *      Author: mark
 */
//#include <iostream>
#include <unistd.h>

namespace mdd {

	int loopCount = 0;
	int unused = 0;

	void unfrequentFunctionLevel6() {
		loopCount = 10;
		int bla = 40;
		unused = 10;
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
//		cout << "Zzzzzz...." << endl;
		usleep(500);
//		cout << "Zzzzzz...." << endl;
	}

	void unfrequentFunctionLevel3(int level) {
		expensiveFuntion();
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
		expensiveFuntion();
	}

	void frequentFunctionRenamed() {
		// does nothing
	}

	void unusedFunction() {
		int doesNothing = 4;
		for (int j = 0; j < 2000; ++j)
		{
			doesNothing = doesNothing++ % 1337;
		}
	}

	int someCalculationWithCache()
	{
		static int result = 0;

		// some "complicated" calculations...
		for (int i = 0; i < 1337; ++i)
		{
			result = result * 42;
			result %= 1337 * 23;
		}

		return result;
	}

	/**
	 * This is the main function and this comment is pretty useless
	 */
	int main() {
		unfrequentFunctionLevel1(4);

		someCalculationWithCache(); // cache miss
		someCalculationWithCache(); // cache hit
		someCalculationWithCache(); // cache hit
		someCalculationWithCache(); // cache hit

		for (int i = 0; i < loopCount; ++i) {
			frequentFunctionRenamed();
		}
		return 0;
	}

}
