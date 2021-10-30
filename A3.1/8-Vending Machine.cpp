#include <iostream>
#include <cstdlib>
using namespace std;

void money(string name,int cost)
{
    int userbal = 0,inputbal;
    while (true)
    {	
		// userinput for inserting money	
        cout<< "\nBalance = "<<userbal<<endl;
        cout<< "Insert Money Here: ";
        cin>>inputbal;
        userbal += inputbal;
        //since it can only accept 1, 5, and 10 peso coin, anything else you input other than those three is invalid
        if (inputbal != 1 && inputbal !=5 && inputbal != 10 )
		{
        	cout<<"\nERROR: Invalid Input\n";
        	exit(0);
		}
        if (userbal>=cost)
		{
            break;
        }
    }
		//once userbal is >= to amount, this shall pop up.
		//if userbal>amount then subtract the userbal to the specified cost of the chosen drink 
    	int change = (userbal-cost);
    	cout<<"\nPlease wait...\n\n";
    	cout<<"\nDispensing your drink...  ";
    	//If you don't have any change then
    	if (change == 0){
    		cout<<"\nPlease get your drink.";
		}
		//If you have change then
    	else{
    		cout<<"\nPlease get your drink and change.";
    		cout<<"\nYour change is "<< change <<" pesos.";
		}
    	
}

int main() {
	int answer = 0;
	//A do-while loop to loop the program if the user types 1 later in the prompt
	do
	{
		int drinkchoice;
		
    	cout<<"Virtual Vending Machine\n";
    	cout<<"\n";
    	cout<<"What would you like to drink?\n";
    	cout<<"\n(1) Coke--Php 34";
    	cout<<"\n(2) Iced Tea--Php 27";
   		cout<<"\n(3) Coffee--Php 45";
    	cout<<"\n(4) Water--Php 13";
    	cout<<"\n(5) Exit Virtual Vending Machine";
    	cout<<"\nEnter your choice here: ";
    	cin>>drinkchoice;
    	
    	if (drinkchoice !=1 && drinkchoice !=2 && drinkchoice !=3 && drinkchoice !=4 && drinkchoice !=5){
		cout<<"\nERROR: Invalid Input\n";
		exit(0);
	}
		else{
			//switch for each of the choices
    		switch (drinkchoice)
			{
        		case 1: 
            		money("Coke",34);
            		break;
            	
        		case 2: 
            		money("Iced Tea",27);
            		break;
            	
        		case 3: 
            		money("Coffee",45);
            		break;
            	
        		case 4:
            		money("Water",13);
            		break;
            
       			case 5:
        			cout<<"\nSee you next time!";
            		exit(0);
            		break;
			}
			
			//A prompt if the user wants to buy again or not
			cout<<"\n";
			cout<<"\nWould you like to buy again? (1)Yes | (0)No: ";
			cin>>answer;
			if (answer != 1 && answer !=0){
			cout<<"Invalid Input";
			exit (0);
			}
			cout<<"-------------------------------------------------------------------------------------------";
			cout<<"\n";
			}
	}while (answer != 0);
	cout<<"\nThank You! Come again.";
}
