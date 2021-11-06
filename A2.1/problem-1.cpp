#include <iostream>

using namespace std;

int main() {
    char ascii_char;

    //default case
    string res = "sepcial symbol";

    cout << "Enter a character: ";
    cin >> ascii_char;

    if (ascii_char >= '0' && ascii_char <= '9')  
    {
        res = "digit";
    } 
    else 
    if ((ascii_char >= 'a' && ascii_char <= 'z') || 
        (ascii_char >= 'A' && ascii_char <= 'Z')) 
    {
        res = "letter";
    }

        cout << ascii_char << " is a " << res;
    return 0;
}