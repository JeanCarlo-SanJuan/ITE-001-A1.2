#include <iostream>
#include <math.h>
using namespace std;
const int size = 6;

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

//Method 2
// Congruence Modulo by Recursion
int byCongruenceModulo(int num, int place) {
    int real_place = pow(10, place);
    int res = num % real_place;
    int final_res;
    if (place != 1) {
        final_res = res - byCongruenceModulo(res, --place);
    } else {
        final_res = res;
    }

    return final_res;
}

//Method 3
// By int to str type conversion
// Gets the place value as the value of an array at position index. 
int get_place(int num, int index) {
    string _num = to_string(num);
    int len = _num.length() - 1;

    if (index > len || index < 0) {
        return 0;
    }

    return int(_num[len - index] - '0');
}

int main() {
    int ints[size] = {51, 1282, 2236, 229, 120, 17};
    int _ones[size];
    int _tens[size];
    int _hundreds[size];
    int current;

    for (int i = 0; i < size; i++) {
        //ints[i] = ask_int("Enter integer #" + to_string(i + 1) + ": ");

        _ones[i] = get_place(ints[i], 1);
        _tens[i] = get_place(ints[i], 2);
        _hundreds[i] = get_place(ints[i], 3);
    } 
    cout << sigma(_ones, size) << endl;
    cout << sigma(_tens, size) << endl;
    cout << sigma(_hundreds, size) << endl;
}