#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter n: ";    
    cin >> n;

    if (n < 0) {
        cout << "Negative";
    } else if (n > 0) {
        cout << "Positive";
    }
    return 0;
}