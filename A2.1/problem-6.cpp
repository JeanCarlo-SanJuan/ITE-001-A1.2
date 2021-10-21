#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 5;

string operations[SIZE] = {
    "Add",
    "Subtract",
    "Multiply",
    "Divide",
    "do Modulus"
};

// Input validation
double require_double(string msg) {
    double num;
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
    int operation;
    double x, y, ans;

    for (int i = 0; i < SIZE; i++) {
        cout << "Press " << i + 1 << " to " << operations[i] << endl;
    }

    operation = int(require_double("Enter option here: "));

    if (operation < 1 || operation > SIZE) {
      cout << "Invalid Operation" << endl;
      return 0;  // Early return
    }

    x = require_double("Enter first number: ");
    y = require_double("Enter second number: ");
    
    switch (operation)
    {
        case 1: // Addition
            ans = x + y;
            break;
        case 2: // Subtraction
            ans = x - y;
            break;
        case 3: // Multiplication
            ans = x * y;
            break;
        case 4: // Division
            if (y == 0) {
                cout << "Division by zero is not possible." << endl;
                return 0;
            } else {
                ans = x / y;
            }
            break;
        case 5: // Modulo
            ans = int(x) % int(y);
            break;
        default:
            cout << "Invalid Operation";
    }

    cout << "Output: ";
    
    // When the answer is an integer just print it.
    if (ans == int(ans)) {
        cout << ans;
    } else {
        cout << fixed << setprecision(3) << ans;
    }

    return 0;
}