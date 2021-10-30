// Problem 6: Create a program that will accept input values while the input is not equal to zero.
// Also, display the sum and average of these input values. Do not include Zero (0) in the average computation.

#include <iostream>
using namespace std;

int main ()
{
    int n, i = 1;
    float sum = 0, average = 0, num = 1;

    cout << "\nEnter the numbers of data: ";
    cin >> n;

    while (num != 0 && i <= n)
    {
        cout << i << ". Input value: ";
        cin >> num;
        sum += num;
        i++;
    }

    // sum and average computation
    cout << "The sum is " << sum;
    average = sum / n;
    cout << "\nThe average of all input values is " << average << "\n\n";
}