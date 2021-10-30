#include <iostream>
using namespace std;
int main()
{
  int inputNumber, divisor = 2;
  bool isprime= true;
  
  cout<<"Enter a Number: ";
  cin>>inputNumber;
  
  if (inputNumber<1)
    cout<<"Invalid Input";
  else if (inputNumber == 1)
    cout<<"1 is not a prime or composite number...";
  
  else{

  while (divisor <= (inputNumber/2))
    {
      if( (inputNumber%divisor) == 0)
      {
      isprime = false;
      divisor++;
      break;
      }
      else{
      	isprime = true;
      break;
      divisor++;
	  }
  }
  if(isprime)
  cout<<inputNumber<< " is a prime number...";
  else
    cout<< inputNumber <<" is a composite number...";
  
}
}
