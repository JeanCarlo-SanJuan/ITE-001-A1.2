#include <iostream>
#include <cmath>
using namespace std;


// Contributed by Cyrill
int main()
{
    float side1, side2, side3, area, s;
	cout << "\nFind the area of any triangle using Heron's Formula.\n\n";	
    cout<<" Input the length of 1st side of the triangle: ";
    cin>>side1;
    cout<<" Input the length of 2nd side of the triangle: ";
    cin>>side2;
    cout<<" Input the length of 3rd side of the triangle: ";
    cin>>side3;

    // Area Formula
	s = (side1 + side2 + side3) / 2;
	area = sqrt (s * (s - side1) * (s - side2) * (s - side3));
    cout<<" \nThe area of the triangle is : "<< area << endl;
    cout << endl;
    return 0;
}