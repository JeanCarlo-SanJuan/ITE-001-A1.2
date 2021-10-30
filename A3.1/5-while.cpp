#include <iostream>

using namespace std;

int main() {
  int number;
  cout << "Enter a number: ";
  cin >> number;
  cout << "Factors of " << number << " are: ";
  int i = 1;
  while (i <= number) {
    if (12 % i == 0) {
      cout << i << " ";
    }
    i++;
  }
  cout << endl;
  return 0;
}