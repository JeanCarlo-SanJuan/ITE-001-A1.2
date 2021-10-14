#include <iostream>
#include <cmath>
using namespace std;

int sigma(int array[], int len) {
    int sum = 0;

    for (int i = 0; i < len; i++) {
        sum += array[i];
    }

    return sum;
}

int ask_int(string question) {
    int num;
    while (1) {
        cout << question << endl;
        cin >> num;
        if (cin.fail()) {
            cin.clear();
            cin.sync();
            cin.ignore('\n');
            continue;
        }
        return int(num);
    }
}

//Method 1
// Congruence Modulo (hard coded);
int ones(int num) {
    return num % 10;
}

int tens(int num) {
    return num % 100 - ones(num);
}

int hundreds(int num) {
    return num % 1000 - tens(num) - ones(num);
}

// Method 2 using division, modulus, and float to int typecasting
int get_place_method_2(int num, int pos) {
    int result;
    int real_place = pow(10, pos + 1);

    if (real_place / 10 > num) {
        return 0;
    }

    result = int(num % real_place);

    while (result > 9) {
        result = int(result / 10);
    }
    
    return result;
}

// Description
// (1) consider an integer as a string.
// (2) Consider a string as a 1D array of characters.
// We can get the place value digit by using its equivalent index position.
// To determine the index position, count the number of zeros in the desired place value
// Ones = 1 has zero 0s hence index = 0
// Tens = 10 has one 0s hence index = 1
// Hundreds = 100 has two 0s hence index = 2
// Example:
// Say you wanna know the hundreds digit of 1234,
// to do so call "get_place(1234, 2)" which returns 2
int get_place_method_3(int num, int index) {
    string _num = to_string(num);
    int len = _num.length() - 1;

    if (index > len || index < 0) {
        return 0;
    }

    return int(_num[len - index] - '0');
}

const int size = 6;
int main() {
    cout << get_place_method_3(1234, 2);
    int ints[size] = {51, 1282, 2236, 229, 120, 17};
    int outputs[3][size];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < size; j++) {
            //Uncomment the next line to use a different set of numbers
            //ints[j] = ask_int("Enter integer #" + to_string(j + 1) + ": ");
            outputs[i][j] = get_place_method_3(ints[j], i);
        }

        cout << "summation of digits at position " << i + 1 << ": " << sigma(outputs[i], size) << endl;
    }
}