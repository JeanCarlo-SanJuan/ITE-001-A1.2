#include <iostream>
#include <iomanip>
using namespace std;

// Contributed by Cyrill
int main()
{
    float radius, circumference;
    cout << "Enter the radius of circle: ";
    cin >> radius;
    circumference = 2 * 3.1416 * radius;
    cout << "The circumference of the circle is: " << fixed << setprecision(4) << circumference;
    return 0;
}