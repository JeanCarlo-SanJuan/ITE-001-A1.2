#include <iostream>
using namespace std;

double max(double a, double b) {
    // My implementation of the built-in max function found in the <algorithm> library to get the higher value from two numbers.
    return (a > b) ? a:b;
}

// Input validation
double require_double(string text) {
    double num;
    for(;;) {
        cout << text;
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
    const int size = 3;

    double n[size];
    string ranks[size] = {
        "first",
        "second",
        "last"
    };

    for (int i = 0; i < size; i++) {
        n[i] = require_double("Enter the " + ranks[i] + " number: "); 
    }

    cout << "Input numbers are " << n[0] << ", " << n[1] << ", and " << n[2] << endl;
    double highest_val = max(n[0], max(n[1], n[2]));
    cout << highest_val << " is the highest among the input numbers...\n\n";
    
    return 0;
}