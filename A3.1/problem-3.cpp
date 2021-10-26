/* 3.	Create a program that will display the following series: (Prepare 3 versions of source codes using for loop, while loop, do while loop)  */

#include <iostream>

using namespace std;

void opposite_series(int method, int start_val);

int const SIZE = 4;

int main() {
    for (int i = 0; i < 3; i++) {
        opposite_series(i, 85);
    }
    return 0;
}

void opposite_series(int method, int start_val) {
    int i = 0;
    int inputs[SIZE];

    switch (method) {
        case 0: // For loop
            for (i = 0; i < SIZE; i++) {
                inputs[i] = start_val + i * 5;
            }

            for (i = SIZE - 1; i > -1; i--) {
                cout << inputs[i] * -1 << "\t";
            }

            for (i = 0; i < SIZE; i++) {
                cout << inputs[i] << "\t";
            }
            break;

        case 1: // while loop;      
            while (i < SIZE)
            {
                inputs[i] = start_val + i * 5;
                i++;
            }
            
            i = SIZE - 1;

            while (i > -1)
            {
                cout << inputs[i--] * -1 << "\t";
            }    

            i = 0;

            while (i < SIZE)
            {
                cout << inputs[i++] << "\t";
            }
            
            break;

        case 2: // do while loop
            do {
                inputs[i] = start_val + i * 5;
                i++;
            } while (i < SIZE);

            i = SIZE - 1;

            do {
                cout << inputs[i--] * -1 << "\t";
            }
            while (i > -1);

            i = 0;

            do {
                cout << inputs[i++] << "\t";
            }
            while (i < SIZE);

            break;
    }

    cout << endl;
}