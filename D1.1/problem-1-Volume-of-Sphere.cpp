#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Contributed by Sons Justin Paraiso Garcia
int main () {
  double pi = 3.1416;
  double r;

  cout << "Enter the value of r: ";
  cin >> r;

  double volume = (4.0 / 3.0) * pi * pow(r, 3);

  cout << "The volume of a sphere with a radius of " << r << " is:" << endl;
  cout << "(4 / 3) * pi * r^3 = " << fixed << setprecision(2) << volume << endl;

  return 0;
}