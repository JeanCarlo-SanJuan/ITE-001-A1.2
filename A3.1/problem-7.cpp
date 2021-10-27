/* 
7.	Create a program that is able to do basic banking transactions. Presuppose that an existing account is available 
with an initial balance of 10,000 pesos. To perform any transaction, ask the user to enter a valid PIN (Personal Identification Number- 445236). 
You may include added features to make the program better. 
 */


#include <iostream>
#include <iomanip>

using namespace std;

int pid = 445236;
int balance = 1000000;

void show_bal(bool pause = 0) {
    system("cls");
    cout << "Current Balance: Php " << fixed << setprecision(2) << balance * 0.01 << endl;
    if (pause) {
        system("pause");
        system("cls");
    }
}

int main() {
    system("cls");

    int _pid;
    bool loggedIn = false;

    bool exitCode = false;
    int action;

    while(!exitCode) {
        action = 0;
        cout << " ITE-001 Banking System: Main menu\n";
        cout << " 1. Check Balance\n";
        cout << " 2. Deposit\n";
        cout << " 3. Withdraw\n";
        cout << " 4. Exit\n";
        cout << " Enter action: ";
        cin >> action;
        system("cls");

        if (action >= 1 && action <= 3) {
            cout << "User Authentication is required...\n";
            cout << "Enter PID: ";
            cin >> _pid;

            if (_pid != pid) {
                system("cls");
                cout << "Verification failed\n";
                cout << "Please enter a valid PID.\n";
                continue;
            }

            cout << "Verification success!\n";
        }

        float amount = 0;

        switch (action) {
            case 1:
                /* Check Bal */
                show_bal(1);
                break;
            case 2: /* Deposit */
                while(true) {
                    show_bal();
                    cout << "Enter amount to be deposited: ";
                    cin >> amount;

                    if (amount >= 0) {

                        if (amount == 0) {
                            system("cls");
                            cout << "Cancelling deposit...\nReturning to main menu...\n";
                        } else {
                            balance += amount * 100;
                            show_bal(1);
                        }
                        break;
                    } else {
                        cout << "Please enter a valid amount!\n";
                    }
                }
                break;
            case 3: /* Withdrawal  */
                while(true) {
                    show_bal();
                    cout << "Enter amount to be withdrawn: ";
                    cin >> amount;

                    if (amount >= 0 && amount <= balance) {
                        if (amount == 0) {
                            system("cls");
                            cout << "Withdrawal cancelled...\nReturning to main menu...\n";
                        } else {
                            balance -= amount * 100;
                            show_bal(1);
                        }
                        break;
                    } else {
                        cout << "Please enter a valid amount!\n";
                    }
                }
                break;
            case 4: /* Exit */
                exitCode = true;
                break;
            default:
                cout << "Invalid action!\n";
        }

    } 

    return 0;
}