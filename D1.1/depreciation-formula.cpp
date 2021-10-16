#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float purchase_price, years_of_service, salvage_value, yearly_depreciation;

    cout << "Enter purchase price of an item: ";
    cin >> purchase_price;
    cout << "Enter its expected years of service: ";
    cin >> years_of_service;
    cout << "Enter its expected salvage value: ";
    cin >> salvage_value;

    yearly_depreciation = (purchase_price - salvage_value) / years_of_service;

    // Since the problem deals with money the maximum place value is in the hundredths digit.
    cout << "The item's yearly depreciaton is equal to " << fixed << setprecision(2) << yearly_depreciation << " units.\n";

    return 0;
}