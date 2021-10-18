#include <iostream>
#include <iomanip>

using namespace std;

// Contributed by Buggati Aaron Fernandez
int main()
{
    double inputnetbalance, payment, d1, d2, IRpermonth, avgdailybal, interest;

    cout << "Enter your Net Balance: ";
    cin >> inputnetbalance;

    cout << "How much did you pay? ";
    cin >> payment;

    cout << "How many days are in the billing cycle? ";
    cin >> d1;

    cout << "How many days are left in the billing cycle before the payment is made? ";
    cin >> d2;

    cout << "Interest Rate per Month: ";
    cin >> IRpermonth;

    avgdailybal = (inputnetbalance * d1 - payment * d2) / d1;
    interest = avgdailybal * IRpermonth;

    cout << "\nYour Interest is: " << fixed << setprecision(2) << interest;
    return 0;
}