#include <iostream>

using namespace std;

int main() {
  char letter = 'A';
  while (letter <= 'Z') {
    if (letter != 'A' && letter != 'E' && letter != 'I' && letter != 'O' && letter != 'U') {
      cout << char(letter) << " ";
    }
    letter++;
  }
  cout << endl;
  return 0;
}