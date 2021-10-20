#include <iostream>
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
const int SIZE = 4;
string operations[SIZE] = {
    "Add",
    "Subtract",
    "Multiply",
    "Divide"
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
    int operation;

    for (int i = 0; i < SIZE; i++) {
        cout << "Press " << i + 1 << " to " << operations[i] << endl;
    }

    operation = require_int("Enter option here: ");

    switch (operation)
    {
        case 1: // Addition
            /* code */
            break;
        case 2: // Subtraction

            break;
        case 3: // Multiplication

            break;
        case 4: // Division

            break;
        default:
            cout << "Invalid Operation";
    }

    return 0;
}