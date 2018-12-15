#include <iostream>
#include <iomanip>
#include <string>
#include <cfloat>
#include <fstream>
using namespace std;

string convertFloat(float number);
/**
return the sign, exponent, and matissa of the number in '(sign,exponent,mantissa)' format.
**/

float nextFloat(float number);
/**
return the next greater number of the 'number' in the series of 32-bit floating point numbers
**/

unsigned int countBetween(float lower, float upper);
/**
return the number of 32-bit floating point numbers between lower and upper
**/

int main(int argc, char* argv[]) {
	cout << "i. Floating point number converter.\n";
	float pi = 3.14159265358979;
	cout << pi << " -> " << convertFloat(pi) << endl;

	cout << "\nii. Floating point number enumeration.\n";
	float fp = 0.0;
	unsigned int i = 0;
	while (fp < 1.4E-44) {
		cout << ++i << "th number: " << (fp = nextFloat(fp)) << endl;
	}

	cout << "\niii. Floating point number counting\n";
	unsigned int posFPs = countBetween(0.0, FLT_MAX);
	unsigned int zeroOneFPs = countBetween(0.0, 1.0);
	cout << "Number of positive floating point numbers: " << posFPs << endl;
	cout << "Number of floating point numbers between 0 and 1: " << zeroOneFPs << endl;
	cout << "Proportion (# of 0~1) / (# of positive): " << (double) zeroOneFPs / (double) posFPs * 100.0 << "%\n";

	if (argc != 2) {
		cerr << "\niv. Pass the data file name\n";
		return 0;
	}
	cout << "\niv. Floating point number distribution\n";
	ofstream datafile;
	datafile.open(argv[1]);
	float lower = 0.0, upper, interval = 100.0;
	for (int i = 0; i < 100; i++) {
		upper = lower + interval;
		datafile << countBetween(lower, upper) << endl;
		lower = upper;
	}
	datafile.close();
	cout << "The output file is ready. Execute \"Python3 Assn9.py " << argv[1] << "\"\n";
}

string convertFloat(float number) {
	string return_value;

	unsigned int number_i = *(unsigned int*) &number;
	cout << number << endl;
	cout << number_i << endl;
	unsigned int sign = (number_i & 0x80000000) >> 31;
	unsigned int exponent = (number_i & 0x7f8000000) >> 23;
	unsigned int matissa = (number_i & 0x007fffff);

	return_value = "(" + to_string(sign) + ", " + to_string(exponent) + ", " + to_string(matissa) + ")";
	return return_value;
}

float nextFloat(float number) {
	unsigned int number_i = *(unsigned int*) &number;
	number_i++;
	float num = *((float*) &(number_i));
	return num;
}

unsigned int countBetween(float lower, float upper) {
	unsigned int number_lower = *(unsigned int*) &lower;
	unsigned int number_upper = *(unsigned int*) &upper;

	return number_upper - number_lower;
}
