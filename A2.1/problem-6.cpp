#include <iostream>
#include <iomanip>
using namespace std;

/* 
Press 1 to ADD 
Press 2 to Subtract 
Press 3 to Multiply 
Press 4 to Divide 
Enter Option Here: ___ 
Displaying the above is done ^

Enter First Number: ___ 
Enter Second Number: ___ 
Output: ___ 
 
Note: 
A.	Dividing with zero is not possible. 
DONE - B.	Pressing other character, display “Invalid Operation”, then end the program. 
C.	First Number, second number and the output can be a floating value. 
D.	Round-off the output in 3 decimal places. 
E.	You may add other possibilities to make the program better. 
 */

const int SIZE = 5;
string operations[SIZE] = {
    "Add",
    "Subtract",
    "Multiply",
    "Divide",
    "do Modulus"
};

// Input validation
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
    double x, y, ans;
    int operation;

    for (int i = 0; i < SIZE; i++) {
        cout << "Press " << i + 1 << " to " << operations[i] << endl;
    }

    operation = require_int("Enter option here: "); 

    x = require_double("Enter first number: ");
    y = require_double("Enter second number: ");
    
    switch (operation)
    {
        case 1: // Addition
            /* code */
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
            return 0;
    }

    cout << "Output: ";
    
    if (ans == int(ans)) {
        cout << ans;
    } else {
        cout << fixed << setprecision(3) << ans;
    }

    return 0;
}