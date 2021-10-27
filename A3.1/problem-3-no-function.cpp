#include <iostream>
using namespace std;

int main() {
    /* 3.	Create a program that will display the following series: 
       (Prepare 3 versions of source codes using for loop, while loop, do while loop)  */
    int i;

    int const STEP = 5;
    int const ITERATIONS = 4;
    int const A = -100;
    int const B = 85;

    /* Algorithm:
    (1) Print half of the integers in a column using an arithmetic series.
        Note:
        (a) The number of elements are based on the ITERATIONS constant.
        (b) The common difference is based on the constant STEP.
        (c) The start value is given by the constant A.
        (d) The final value of the element is given by adding A and the product of the current iteration i and common difference STEP.
    (2) Repeat (1) to print the other half of the column but set the start value using constant B.
    (3) Print a new line
    (4) Repeat (1) to (3) for each of the three iterative control structures.
    */

    for (i = 0; i < ITERATIONS; i++)
    {
        cout << A + i * STEP << "\t";
    }

    for (i = 0; i < ITERATIONS; i++)
    {
        cout << B + i * STEP << "\t";
    }

    cout << endl;

    i = 0;
    while (i < ITERATIONS)
    {
        cout << A + i * STEP << "\t";
        i++;
    }

    i = 0;
    while (i < ITERATIONS)
    {
        cout << B + i * STEP << "\t";
        i++;
    }

    cout << endl;
    i = 0;

    do {
        cout << A + i * STEP << "\t";
        i++;
    } while (i < ITERATIONS);            
    
    i = 0;

    do {
        cout << B + i * STEP << "\t";
        i++;
    } while (i < ITERATIONS);

    return 0;
}