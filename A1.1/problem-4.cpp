#include <iostream>
using namespace std;

int ask_float(string question) {
    float res;
    while (1) {
        cout << "Enter " << question << ": ";
        cin >> res;
        if (cin.fail()) {
            cin.clear();
            cin.sync();
            cin.ignore('\n');
            continue;
        }
        cout << endl;
        return res;
    }
}

int main() {
    // Write a program that accepts as input:
    // netBal, payment, d1,d2, and interest rate per month. 
    // The program outputs the interest. Format your output to two decimal places.
    float netBal, payment, d1, d2, interest_rate;
    //float interest = 0.00;

    netBal = ask_float("Net Balance");
    payment = ask_float("Payment");
    d1 = ask_float("d1"),
    d2 = ask_float("d2");
    interest_rate = ask_float("interest rate");

    cout << interest_rate;

    return 0;
}