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

// Input validation
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
        return num;
    }
}

// Method 1 using division, modulus, and float to int typecasting
int get_place(int num, int pos) {
    int result;
    int real_place = pow(10, pos + 1);

    // The place value is automatically zero when:
    // 1: The integer doesn't have the required place value
    if (real_place / 10 > num || pos < 0) {
        return 0;
    }

    // To get the last n digits of number, do a modulus operation by 10^n (This is called congruence magic);
    result = num % real_place;

    // The place value digit that we want is in the leftmost digit.
    // To get that digit we divide by 10 and keep the integer result.
    while (result > 9) {
        result = int(result / 10);
    }
    
    return result;
}

// Description
// (1) consider an integer as a string.
// (2) Consider a string as a 1D array of characters.
// We can get the place value digit by finding the corresponding index position of the digit from the array.
// To determine the index position, count the number of zeros in the desired place value
// Ones = 1 has zero 0s hence index = 0
// Tens = 10 has one 0s hence index = 1
// Hundreds = 100 has two 0s hence index = 2
// Example:
// Say you wanna know the hundreds digit of 1234,
// to do so call "get_place_method_3(1234, 2)" which returns 2
int get_place_method_2(int num, int index) {
    string _num = to_string(num);
    int len = _num.length() - 1;

    if (index > len || index < 0) {
        return 0;
    }

    // The operation below relates to the ASCII encoding standard.
    //Subtracting the char '0' and the value of _num at len - index gives us the correct int value.
    return int(_num[len - index] - '0');
}

const int size = 6;   // Change this constant to alter the number of integers to be used
int outputs[3][size];

// Optional: Change the array elements
int ints[size] = {51, 1282, 2236, 229, 120, 17};
string place_val[3] = {"ones", "tens", "hundreds"};

void do_algorithm(int method) {
    cout << "\nUsing algorithm " << method << endl << "Summation of digits in the...\n";

    for (int i = 0; i < 3; i++) {
        cout << place_val[i] << " place: ";

        for (int j = 0; j < size; j++) {
            //Uncomment the next line to use a different set of integers
            //ints[j] = ask_int("Enter integer #" + to_string(j + 1) + ": ");
            outputs[i][j] = (method == 1) ? get_place(ints[j], i) : get_place_method_2(ints[j], i);

            cout << outputs[i][j] << ((j < size -1) ? " + ": " = ");
        }

        cout << sigma(outputs[i], size) << endl;
    }
}

int main() {
    // The algorithms calculate the summation of place value digits from an array of integers.
    do_algorithm(1);
    do_algorithm(2);
}