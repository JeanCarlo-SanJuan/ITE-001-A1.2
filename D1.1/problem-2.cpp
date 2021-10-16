#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    float celsius, fahrenheit;

   	cout<<"Enter Celsius : ";
    cin>>celsius;

    fahrenheit = (celsius * 9 / 5) + 32;

   	cout<< celsius << " * " << 9 << " / " << 5 << " + " << 32 << " = " << fahrenheit<<endl;
   	cout<<"The equivalent temperature in Fahrenheit is : "<<fahrenheit<<" degrees Fahrenheit ";
   	setprecision(3);
    return 0;
}