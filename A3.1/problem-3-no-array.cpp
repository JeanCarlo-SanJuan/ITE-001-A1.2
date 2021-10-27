#include <iostream>
using namespace std;

void opposite_series(int method, int start_val, int upper_limit, int step) {
    int i = 0;

    switch (method) {
        case 0: // For loop
            for (i = 0; i < upper_limit; i++)
            {
                cout << start_val + i * step << "\t";
            }
            break;
        case 1: // while loop;      
            while (i < upper_limit)
            {
                cout << start_val + i * step << "\t";
                i++;
            }
            break;
        case 2: // do while loop
            do {
                cout << start_val + i * step << "\t";
                i++;
            } while (i < upper_limit);
            break;
    }
}

int main() {
    /* 3.	Create a program that will display the following series: 
       (Prepare 3 versions of source codes using for loop, while loop, do while loop)  */
    int const STEP = 5;
    int const UPPER_LIMIT = 4;

    for (int i = 0; i < 3; i++) {
        opposite_series(i, -100, UPPER_LIMIT, STEP);
        opposite_series(i, 85, UPPER_LIMIT, STEP);
        cout << endl;
    }
    return 0;
}