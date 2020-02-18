

#include "first.h"


// thought process: we need to XOR the bits of the same position. if both true we carry, 
//
//
void addTwo(int num1, int num2) {
	string sum;
	// get binary versions as strings
	string bin1 = std::bitset<8>(num1).to_string();
	string bin2 = std::bitset<8>(num2).to_string();

	int pos = bin1.size() - 1;
	char carry = '0';

	cout << "Binary version of " << num1 << " is:" << bin1 << endl;
	cout << "Binary version of " << num2 << " is:" << bin2 << endl;

	// this is basically just an XOR with carry involved
	while (pos > -1) { // this will get the reverse of the string we need
		if (bin1[pos] == '1' && bin2[pos] == '1' && carry == '1') { // carry needed and carry 1
			sum.push_back('1'); // do not reset carry
		}
		else if (bin1[pos] == '1' && bin2[pos] == '1' && carry == '0') { // carry needed and no current carry
			sum.push_back('0');
			carry = '1';
		}
		else if ((bin1[pos] == '1' && bin2[pos] == '0') || (bin1[pos] == '0' && bin2[pos] == '1') && carry == '1') { // carry needed b/c current carry
			sum.push_back('0'); // do not reset carry
		}
		else if ((bin1[pos] == '1' && bin2[pos] == '0') || (bin1[pos] == '0' && bin2[pos] == '1') && carry == '0') { // no current carry or carry needed
			sum.push_back('1');
		}
		else if (carry == '1') { // all 0 except carry
			sum.push_back('1');
			carry = '0';
		}
		else
			sum.push_back('0'); // all three are 0

		pos--;
	}
	cout << "Binary version of " << num1+num2 << " is:"; // ok so this TECHNICALLY might not be allowed but it makes things prettier
	for (int i = bin1.size() - 1; i > -1; i--) { // prints the string in reverse order
		cout << sum[i];
	}
	cout << endl;
}