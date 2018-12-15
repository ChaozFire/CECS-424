#include <iostream>
#include <regex>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
  string fileName = argv[1];
  string line;
  ifstream file(fileName);
  regex pattern ("^[$][*]*([0]|([1-9][\\d]{2}|[1-9][\\d]|[1-9])([,][\\d]{3})*)([.][\\d]{2})?$");
  while(getline(file,line)) {
    if(regex_match(line,pattern))
      cout << "Matched: " << line << endl;
    else
      cout << "Not Matched: " << line << endl;
  }

  return 0;
}
