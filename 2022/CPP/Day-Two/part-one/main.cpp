#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void getOutcome(string roundChoices, int &score) {
  if (roundChoices[0] == 'A') {
    if (roundChoices[2] == 'X') {
      score += 3;
    } else if (roundChoices[2] == 'Y') {
      score += 6;
    }
  } else if (roundChoices[0] == 'B') {
    if (roundChoices[2] == 'Y') {
      score += 3;
    } else if (roundChoices[2] == 'Z') {
      score += 6;
    }
  } else if (roundChoices[0] == 'C') {
    if (roundChoices[2] == 'X') {
      score += 6;
    } else if (roundChoices[2] == 'Z') {
      score += 3;
    }
  }
}

int main() {
  string file;
  int score = 0;

  cout << "Enter a file: ";
  getline(cin, file);

  ifstream inputFile;
  inputFile.open(file);

  string roundChoices;
  while (getline(inputFile, roundChoices)) {
    if (roundChoices[2] == 'X') {
      score += 1;
    } else if (roundChoices[2] == 'Y') {
      score += 2;
    } else if (roundChoices[2] == 'Z') {
      score += 3;
    }

    getOutcome(roundChoices, score);
  }

  cout << "Your score was: " << score << endl;

  return 0;
}
