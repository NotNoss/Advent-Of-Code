#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string file;

  vector<int> calories;

  cout << "Enter a filename: ";
  getline(cin, file);

  ifstream inputFile;
  inputFile.open(file);

  string calorie;
  int num = 0,
      maxCalories = 0;
  while (getline(inputFile, calorie)) {
    if (calorie == "") {
      calories.push_back(num);

      num = 0;
    } else {
      num += stoi(calorie);
    }
  }

  for (int i = 0; i < (calories.size() - 1); i++) {
    int min_pos = i;

    for (int j = i; j < calories.size(); j++) {
      if (calories[j] > calories[min_pos]) {
        min_pos = j;
      }
    }

    if (min_pos != i) {
      int temp = calories[i];
      calories[i] = calories[min_pos];
      calories[min_pos] = temp;
    }
  }

  int total = 0;
  for (int i = 0; i < 3; i++) {
    total += calories[i];

    cout << calories[i] << endl;
  }

  cout << "Total: " << total << endl;
  
  return 0;
}
