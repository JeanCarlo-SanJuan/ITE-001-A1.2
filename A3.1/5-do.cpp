#include <iostream>

using namespace std;

int main() {
  int number;
  cout << "Enter a number: ";
  cin >> number;
  cout << "Factors of " << number << " are: ";
  int i = 1;
  do {
    if (12 % i == 0) {
      cout << i << " ";
    }
    i++;
  } while (i <= number);
  cout << endl;
  return 0;
}