#include <iostream>

using namespace std;

int main() {
  int number;
  cout << "Enter a number: ";
  cin >> number;
  cout << "Factors of " << number << " are: ";
  for (int i = 1; i <= number; i++) {
    if (12 % i == 0) {
      cout << i << " ";
    }
  }
  cout << endl;
  return 0;
}