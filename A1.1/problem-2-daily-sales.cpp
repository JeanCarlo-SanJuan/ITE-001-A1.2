#include <iostream>
#include <iomanip>
using namespace std;

int const ROWS = 4;
float total_sales = 0;
int tickets_sold = 0;

float sales[ROWS][2] = {
    // Prices | Quantity
    {250.75, 5750},
    {100.50, 28000},
    {50.25, 35750},
    {25.00, 18750}
};

//Problem:
// get sum of price x quantity for each item.
// Contributed by JC San Juan
int main() {
    for(int i = 0; i < ROWS; i++) {
        total_sales += sales[i][0] * sales[i][1];
        tickets_sold += sales[i][1];
    } 

    cout << "Total sales: Php " << fixed << setprecision(2) << total_sales << endl;
    cout << "Total tickets sold: " << tickets_sold << " tickets" << endl;
}
