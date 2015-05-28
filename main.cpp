/*
 * main.cpp
 *
 *  Created on: May 28, 2015
 *      Author: mark
 */

void unfrequentFunction() {
	// does nothing
}

void frequentFunction() {
	// does nothing
}

int main()
{
	unfrequentFunction();

	for (int i = 0; i < 100; ++i) {
		frequentFunction();
	}
	return 0;
}

