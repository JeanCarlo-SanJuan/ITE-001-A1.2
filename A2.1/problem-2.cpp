#include <iostream>
using namespace std;

int main()
{
    int num;

    // input number to check if it's divisible by 3 and 4
    cout << "\nEnter the Number: ";
    cin >> num;

    // logic to check divisibility of a number
    // % as modulus operator
    if ((num % 3 == 0) && (num % 4 == 0))
    {
        cout << "\n" << num <<" is divisible by 3 and 4.\n\n";
    }
    else
    {
        cout << "\n" << num << " is not divisible by 3 and 4.\n\n";
    }

    return 0;
}