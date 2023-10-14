#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  string file;

  cout << "Enter a filename: ";
  getline(cin, file);

  ifstream inputFile;
  inputFile.open(file);

  string calories;
  int num = 0,
      maxCalories = 0;
  while (getline(inputFile, calories)) {
    if (calories == "") {
      if (num > maxCalories) {
        maxCalories = num;
      }

      num = 0;
    } else {
      num += stoi(calories);
    }
  }

  cout << maxCalories << endl;

  return 0;
}
