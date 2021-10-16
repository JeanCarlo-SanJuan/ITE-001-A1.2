#include <iostream>
#include <cmath>

using namespace std;

// Contributed by Sons Justin Paraiso Garcia
int main() {
  double volume;

  cout << "Enter the volume of a perfect cube: ";
  cin >> volume;

  float side = cbrt(volume);
  if (floorf(side) == side) {
    cout << "The side of a perfect cube with a volume of " << volume << " is: " << side << endl;
  } else {
    cout << volume << " is not a perfect cube" << endl;
  }

  return 0;
}