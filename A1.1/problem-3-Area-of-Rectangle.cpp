#include <iostream>
#include <cmath>

using namespace std;

// Contributed by JC San Juan
int main() {
    int X_AREA;
    double width;
    double length;

    // Formula for the area of a rectangle: l * w
    // A = 4w * w
    // A = 4w^2

    cout << "Enter X_AREA: ";
    cin >> X_AREA;

    //           X_AREA = (4w + 4)(w - 1)
    //           X_AREA = 4(w + 1)(w-1)
    //           X_AREA = 4 (w^2 - 1)
    //       X_AREA / 4 = w^2 - 1
    // (X_AREA / 4) + 1 = w^2
    
    width = sqrt((X_AREA / 4) + 1);
    length = width * 4;
    cout << "Width: " << width << endl;
    cout << "Length: " << length << endl;
    cout << "AREA: " << length * width;
}