/*Write a program that converts decimal numbers to 
binary, hexadecimal, and BCD. You are not allowed to use library functions 
for conversion.*/

using namespace std;
#include <iostream>
#include <string>


// convert to binary
string convertToBin(int decimal) {
	string num = "";
	for (int i = 7; i >= 0; i--) {
		int bit = (decimal >> i) & 1;
		num += char('0' + bit);
	}

	num.insert(4, " ");    // space every 4 bits
	return num;
}

// convert to hex
string convertToHex(int decimal) {
	if (decimal == 0) {
		return "00";
	}

	string hexChars = "0123456789ABCDEF";  // for char mapping

	string num = "";
	while (decimal > 0) {
		int remainder = decimal % 16;
		num = hexChars[remainder] + num;
		decimal /= 16;
	}
	return num;
}

// convert to BCD, format like "hhhh tttt oooo"
string convertToBCD(int decimal) {
	int ones = decimal % 10;
	int tens = (decimal / 10) % 10;
	int hunds = (decimal / 100) % 10;

	string BCD = "";
	
	for (int digit : {hunds, tens, ones}) {
		for (int i = 3; i >= 0; --i) {
			int bit = (digit >> i) & 1; // shift bit right by i places
			BCD.push_back('0' + bit);
		}
		BCD.push_back(' ');  // for space every 4 bits
	}

	BCD.pop_back(); // removes last space
	return BCD;
}

int main() {
	int decimal;
	cout << "Shahed Alabdulrahman, CIS-310-001, Pre-Test" << endl;
	cout << "Enter decimal number: ";
	cin >> decimal;

	while (decimal != -1) {
		if (decimal < 0 || decimal > 255) {
			cout << "Invalid! Number must be between 0 and 255." << endl << endl;
		}
		else {
			string binary = convertToBin(decimal);
			string hex = convertToHex(decimal);
			string BCD = convertToBCD(decimal);
			cout << "Binary           Hexidecimal          BCD" << endl;
			cout << binary << "        " << hex << "                    " << BCD << endl;
		}
		cout << "Enter decimal number (0-255) or -1 to quit: ";
		cin >> decimal;
	}
	return 0;
}
