#include <iostream>

using namespace std;

int require_int(string msg) {
    int num;
    while (1) {
        cout << msg;
        cin >> num;
        if (cin.fail()) {
            cin.clear();
            cin.sync();
            cin.ignore('\n');
            continue;
        }
        return num;
    }
}

int main() {
  int n;

  n = require_int("Enter a number: ");

  bool by3 = n % 3 == 0;
  bool by4 = n % 4 == 0;

  if (by3 && by4) {
    cout << n << " is divisible by 3 and 4." << endl;
  } else if (by3) {
    cout << n << " is divisible by 3 but not 4." << endl;
  } else if (by4) {
    cout << n << " is divisible by 4 but not 3." << endl;
  } else {
    cout << n << " is not divisible by both 3 and 4." << endl;
  }

  return 0;
}