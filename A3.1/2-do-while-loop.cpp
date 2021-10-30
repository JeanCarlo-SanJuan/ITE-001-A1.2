// Problem 2: Create a program that will compute for the factorial value of a number. The number is a user input.
// Using do-while loop

#include <iostream>
using namespace std;

int main()
{
    int num, i = 1;
    long double factorial = 1;

    // input a number to check it's factorial
    cout << "\nEnter a Number: ";
    cin >> num;

    // negative number that is less than 0 don't have a factorial
    if (num < 0)
    {
        cout << "Error! Factorial of a negative number is undefined.\n\n";
    }
    else
    {
        // Example: 5! is 5 * 4 * 3 * 2 * 1 = 120
        do
        {
            factorial *= i;
            i++;
        }
        while (i <= num);
        cout << num << "! is " << factorial << "\n\n";
    }
    return 0;
}