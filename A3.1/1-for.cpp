#include <iostream>

using namespace std;

int main() {
  for (char letter = 'A'; letter <= 'Z'; letter++) {
    if (letter != 'A' && letter != 'E' && letter != 'I' && letter != 'O' && letter != 'U') {
      cout << char(letter) << " ";
    }
  }
  cout << endl;
  return 0;
}