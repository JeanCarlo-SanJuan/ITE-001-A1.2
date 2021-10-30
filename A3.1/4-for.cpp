#include <iostream>
using namespace std;
int main()
{
	int inputNumber, divisor;
	bool isprime= true;
	
	cout<<"Enter a Number: ";
	cin>>inputNumber;
	
	if (inputNumber<1)
		cout<<"Invalid input";
	else if (inputNumber==1)
		cout<<"1 is not a prime or composite number...";
	
	else{

	for (divisor = 2; divisor <= (inputNumber/2); divisor++ ){
		if( (inputNumber%divisor) == 0){
			isprime = false;
			break;
		}
	}
	if(isprime)
	cout<<inputNumber<< " is a prime number...";
	else
	cout<< inputNumber <<" is a composite number...";
}
}	
