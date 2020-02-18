
#include <iostream>

#include "first.h"

int main() {
	int num1 = 12;
	int num2 = 13;
	int response = -1;

	while (response != 9) {
		cout << "This adds two numbers together without addition or arithmetic" << endl;
		addTwo(num1, num2);

		cout << "Exit? (type 9)" << endl;
		std::cin >> response;
	}
	return 0;
}