#include <iostream>

using namespace std;

int main() {
  char letter = 'A';
  do {
    if (letter != 'A' && letter != 'E' && letter != 'I' && letter != 'O' && letter != 'U') {
      cout << char(letter) << " ";
    }
    letter++;
  } while (letter <= 'Z');
  cout << endl;
  return 0;
}