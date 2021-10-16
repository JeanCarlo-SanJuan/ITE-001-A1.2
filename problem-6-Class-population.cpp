#include <iostream>

using namespace std;

int main() {
    int boys_count, girls_count, population;
    
    cout << "Enter number of boys in the class: ";
    cin >> boys_count;

    girls_count = (boys_count * 4) + 3;

    population = girls_count + boys_count;

    cout << "There are " << girls_count << " girls in the class.\n";
    cout << "Total population is " << population << endl;

    return 0;
}