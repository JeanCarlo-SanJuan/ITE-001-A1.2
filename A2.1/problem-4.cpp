#include <iostream>
#include <string>
using namespace std;

int main()
{
	string user, pass;
	
	//User Input
	cout<<"USERNAME: ";
	cin>>user;
	cout<<"PASSWORD: ";
	cin>>pass;
	
	//Valid Usernames
	string username1 = "Mr.Watermelon";
	string username2 = "TIPStudent";
	string username3 = "Lily's Peanut Butter";
	string username4 = "CS11S3";
	string username5 = "genericemail@gmail.com";
	
	//Valid Passwords
	string password1 = "watermelon100!";
	string password2 = "student123";
	string password3 = "secondbest";
	string password4 = "coolpeople";
	string password5 = "genericPassword123";
	
	//space before the ifs
	cout<<"\n";
	
	//If Username and Password is valid then Message
	if(user == username1 && pass == password1 || user == username2 && pass == password2 || user == username3 && pass == password3 || user == username4 && pass == password4 || user == username5 && pass == password5)
	{
		cout<<"You entered a valid username and password combination."<<endl;
        cout<<"Access Granted."<<endl;
	}
	
	//If Username and Password is not valid then Message
	else{
		cout<<"Please check your input."<<endl;
    	cout<<"Username and/or the password is invalid."<<endl;
    	cout<<"Access Denied."<<endl;
	}
	
	return 0;
}