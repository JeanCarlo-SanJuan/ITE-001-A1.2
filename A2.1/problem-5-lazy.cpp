#include <iostream>
using namespace std;

double max(double a, double b) {
    // My implementation of the built-in max function found in the <algorithm> library to get the higher value from two numbers.
    return (a > b) ? a:b;
}

int main() {
    double a, b, c;

    cout << "Enter the first number: ";
    cin >> a;

    cout << "Enter the second number: ";
    cin >> b;

    cout << "Enter the last number: ";
    cin >> c;
    
    cout << "Input numbers are " << a << ", " << b << ", and " << c << ".\n";
    cout << max(a, max(b,c)) << " is the highest among the input numbers...\n\n";
}