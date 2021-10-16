#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    float R, S, I;
    float EOQ;
    // Total Yearly Production 
    cout<<"Input Total Yearly Production Requirement : ";
    cin>>R;
    
    // Set Up Cost Per Order
    cout<<"Input Set Up Cost Per Order : ";
    cin>>S;
    
    // Inventory Carrying Cost Per Unit
    cout<<"Input Inventory Carrying Cost Per Unit : ";
    cin>>I;
    
    // Equation
    EOQ=(2*R*S)/I;
    
    // result
    cout<< 2 << " * " << R << " * " << S << " / " << I << " = " << EOQ<<endl;
    setprecision(4);
    
    cout<<"Your Economic Order Quantity is : "<< EOQ;
    setprecision(4);
    return 0;
}