#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

/* 
    Features added which were made possible by using a map data structure:
    1. Account creation
    2. Fund transfer
 */

map<int, float> balances = {
    {000001, 100},
    {000002, 200},
    {445236, 10000},
};

int pin = -1, operation;
int attempts = 0;
const int MAX_ATTEMPTS = 3;
float amount;
bool exitCode = false;

int authenticate(int _pin) {
    for (auto pair: balances) {
        if (pair.first == _pin) {
            return _pin;
        }
    }

    return -1;
}

void error(int cause) {
    switch (cause) {
        case 'A':
            cout << "Please enter valid amount.\n\n";
            break;
        case 'B':
            cout << "You have insufficient balance to do the transaction!\n\n";
            break;
    }
}

void show_bal() {
    cout << "\nCurrent Balance of pin " << pin << ":\nPhp "
     << fixed << setprecision(2) << balances[pin] << endl;
}

void get_amount(string msg, string cancel, bool check_bal = false) {
    /* 
        Algorithm:
        1. get user input 
        2. Set that as the value of the amount variable.
        3. Validate the amount variable.


     */

    cout << "Enter amount to be " + msg + ": ";
    cin >> amount;

    // b. When the user enters zero consider this as cancelling the transaction then return to the main menu.
    if (amount == 0) {
        cout << "Cancelling " + cancel + "...\n";
    }
    // a. Show error msg when the input is negative.
    else if (amount < 0) {
        error('A');
        amount = 0;
    } else
    // c. When the balance is required to be checked, make sure the amount is greater than the account's balance.
    if (check_bal && amount > balances[pin]) {
        error('B');
        amount = 0;
    }
}

void change_bal(int _pin, float _amount) {
    balances[_pin] += _amount;

    if (_pin == pin) {
        cout << "Transacation success!\n";
        show_bal();
    }
}

void show_menu() {
    int action = 0;
    cout << " ITE-001 Banking System: Main menu\n";
    cout << " 1. Check Balance\n";
    cout << " 2. Deposit\n";
    cout << " 3. Withdraw\n";
    cout << " 4. Fund transfer\n";
    cout << " 5. Open an account\n";
    cout << " 6. Exit\n";
    cout << " Enter action: ";
    cin >> action;

    if (action < 1 || action > 6) {
        cout << "Invalid operation!\n";
    } else {
        operation = action;
    }
}

bool login() {
    cout << "User Authentication is required...\nLogin attempts remaining: " << MAX_ATTEMPTS - attempts <<  "\nEnter PIN: ";
    cin >> pin;
    pin = authenticate(pin);

    if (pin != -1) {
        attempts = 0;
        return true;
    } else {
        attempts++;
        cout << "acount not found!\n\n";

        if (attempts >= MAX_ATTEMPTS) {
            cout << "You have reached the maximum login attempts!\nEnding program...";
            exitCode = true;
        }

        return false;
    }
}

int main() {
    system("cls");
    while(!exitCode && attempts < MAX_ATTEMPTS) {
        show_menu();

        if (operation == 6) break; //End program

        if (operation >= 1 && operation <= 4) {
            if (login()) {
                show_bal(); // balance query is automatically done here
            } else {
                continue;
            }
        }

        switch(operation) {
            case 2:
                /* Deposit algorithm
                1. Ask user for an amount to be deposited using get_amount function - validation will be handled it.
                2. Add the amount to the user's account;
                    */
                get_amount("deposited", "deposit");

                if (amount != 0) change_bal(pin, amount);
                
                break;                    
            case 3:
                /* Withdrawal algorithm:
                1. Make sure the account's balance is greater than zero
                2. Ask the user for an amount to be withdrawn using get_amount function - some validations will be handled there.
                2. Subtract the amount from the user's account;

                */
                if (balances[pin] == 0) {
                    error('B');
                } else {
                    get_amount("withdrawn", "withdrawal", true);

                    if (amount != 0) change_bal(pin, amount * -1);
                }
                break;
            case 4:
            /* Fund transfer algorithm :
            1. Make sure the account's balance is greater than zero
            2. Prompt user to enter another pin to whom the funds are to be sent.
            3. What happens next is a combindation of the withdrawal (from the user's account) and deposit (to the target account) cases respectively.
                */
                if (balances[pin] == 0) {
                    error('B');
                } else {
                    int target;
                    cout << "Enter target account: ";
                    cin >> target;

                    target = authenticate(target);

                    if (target == -1) {
                        cout << "acount not found!\n\n";
                    } else {
                        get_amount(
                            "transferred to PIN " + to_string(target),
                            "fund transfer",
                            true
                        );

                        if (amount != 0) {
                            change_bal(target, amount);
                            change_bal(pin, amount * -1);
                        }
                    }
                }

                break;

            case 5:
                /* Algorithm for determining the new pin: 
                Starting with zero, check if the account exists then increment by 1 until a non-existent account is found.
                */
                pin = -1;
                int _pin = 0;
                while (pin == -1) {
                    pin = authenticate(_pin);
                    
                    if (pin != -1) {
                        pin = -1;
                    } else {
                        pin = _pin;
                        balances[pin] = 0;
                    }
                    _pin++;
                }
                cout << "Your new account has been created.\nPlease use the following PIN: " << pin;
                show_bal();
                break;
        }

        //Promp user
        char action;
        cout << "Do you want to continue?\n[Y or y] Yes\n [N or n] No\nEnter Here: ";
        cin >> action;
        switch(action) {
            case 'Y': case 'y':
                system("cls");
                break;
            default:
                //End the program when user enters any other letter than Y.
                exitCode = true;
        }
    }

    cout << "\n--- End of Program ---\n";
    return 0;
}