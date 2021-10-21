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

void show_highest(int n) {
    cout << n << " is the highest among the input numbers...\n\n";
}

void show_tie(string rank1, string rank2) {
    cout << "The " << rank1 << " and " << rank2 << " inputs are both the highest numbers\n\n";
}

void test(double a, double b, double c) {
    cout << "Input numbers are " << a << ", " << b << ", and " << c << endl;

    if (a == b) {
        if (b == c) {
            cout << "The inputs have the same values";
        }
        else if (b > c) {
            show_tie("first", "second");
        } else {
            show_highest(c);
        }
    } 
    else if (a == c) {
        if (a > b) {
            show_tie("first", "last");
        } else {
            show_highest(b);
        }
    } 
    else if (b == c){
        if (b > a) {
            show_tie("second", "last");
        } else {
            show_highest(a);
        }
    }
    else if (a > b) {
        if (a > c) {
            show_highest(a);
        } else {
            show_highest(c);
        }
    } 
    else if (b > c) {
        show_highest(b);
    } else {
        show_highest(c);
    }}

void real_max(double a, double b, double c) {
    cout << "Expected: " << max(a, max(b,c)) << endl;
}

int main() {
    int inputs[10][3] = {
        {2,1,0},
        {1,0,2},
        {0,1,2},
        {1,1,0},
        {1,0,1},
        {0,1,1},
        {0,1,0},
        {0,0,1},
        {1,0,0},
        {1,1,1}
    };

    for (int i = 0; i < 10; i++) {
        test(inputs[i][0], inputs[i][1],inputs[i][2]);
        real_max(inputs[i][0], inputs[i][1], inputs[i][2]);
    }
    return 0;
}