#include <iostream>
#include <iomanip>
#include <string>
#include <cfloat>
#include <fstream>
#include <bitset>
using namespace std;

int main() {
	float number = 3.14159265358979;
  string return_value;

	unsigned int number_i = *(unsigned int*) &number;
	unsigned int sign = (number_i & 0x80000000) >> 31;
	unsigned int exponent = (number_i & 0x7f8000000) >> 23;
	unsigned int matissa = (number_i & 0x007fffff);

	return_value = "(" + to_string(sign) + ", " + to_string(exponent) + ", " + to_string(matissa) + ")";
  cout << return_value;
  return 0;
}
