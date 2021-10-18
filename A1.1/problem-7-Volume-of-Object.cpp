#include <iostream>
#include <iomanip>
using namespace std;

// Contributed by Sons Justin Paraiso Garcia
int main() {
    float mass, density, volume;

    cout << "Enter mass: ";
    cin >> mass;
    cout << "Enter density: ";
    cin >> density;

    volume = mass / density;

    cout << "Volume: " << fixed << setprecision(2) << volume;
}