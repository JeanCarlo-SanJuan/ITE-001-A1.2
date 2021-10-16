#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	float kilog, pounds;
	
	cout<<"Input your weight in kilograms : ";
	cin>>kilog;
	
	pounds = kilog*2.20462;
	
	cout<<"Your weight in pounds is : "<< kilog << " * " << 2.205 << " = " << pounds;
	setprecision(2);
	return 0;
}