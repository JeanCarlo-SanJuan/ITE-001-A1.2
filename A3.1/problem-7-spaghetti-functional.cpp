/* 
7.	Create a program that is able to do basic banking transactions. Presuppose that an existing account is available 
with an initial balance of 10,000 pesos. 
To perform any transaction, 
ask the user to enter a valid PIN (Personal Identification Number- 445236). 
You may include added features to make the program better. 
 */

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

vector<int> accounts = {
    445236,
    02,
    01
};

// Balances are converted to integers with equivalent centavo values
vector<float> balances = {
    10000,
    989,
    1000
};

void show_bal(int index, bool pause = 0) {
    system("cls");
    cout << "Current Balance of PID " << accounts[index] << ":\nPhp "
     << fixed << setprecision(2) << balances[index] << endl;
    if (pause) {
        system("pause");
        system("cls");
    }
}

int find_pid(int _pid) {
    int i = 0;
    for (int pid: accounts)
    {
        if (pid == _pid) {
            return i; 
        }

        i++;
    }

    cout << "acount not found!\n";
    system("pause");
    return -1;
}

int show_menu() {
    int action = 0;
    cout << " ITE-001 Banking System: Main menu\n";
    cout << " 1. Check Balance\n";
    cout << " 2. Deposit\n";
    cout << " 3. Withdraw\n";
    cout << " 4. Fund transfer\n";
    cout << " 5. Exit\n";
    cout << " Enter action: ";
    cin >> action;
    system("cls");

    if (action >= 1 && action <= 5) {
        return action;
    }

    show_menu();
}

void change_bal(int index, float amount) {
    cout << index << " " << amount;
    balances[index] += amount;
}

void amount_error() {
    cout << "Please enter valid amount.\n";
    system("pause");
}

void balance_error() {
    cout << "You have insufficient balance to do the transaction!\n";
    system("pause");
}

int authenticate() {
    int _pid;
    cout << "User Authentication is required...\nEnter PID: ";
    cin >> _pid;

    return find_pid(_pid);
}

float get_amount(string msg, string cancel) {
    float amount;
    cout << "Enter amount to be " + msg + ": ";
    cin >> amount;

    if (amount < 0) {
        amount_error();
    }
    else if (amount == 0) {
        system("cls");
        cout << "Cancelling " + cancel + "...\n";
    } else return amount;

    return -1;
}

int main() {
    int operation;
    int index;

    while(true) {
        system("cls");
        operation = show_menu();

        if (operation == 5) {
            return 0;
        }

        index = authenticate();

        if (index == -1) {
            system("cls");
            cout << "Verification failed\n";
            cout << "Please enter a valid PID.\n";
            continue; //Skip to the next iteration

        } else cout << "Verification successful!\n";
        
        float amount = 0;

        switch(operation) {
            case 1:
                show_bal(index, 1);
                break;
            case 2:
                show_bal(index);
                amount = get_amount("deposited", "deposit");

                if (amount != -1) {
                    change_bal(index, amount);
                    cout << "Transacation success!";
                    show_bal(index, 1);
                }

                break;
            case 3:
                if (balances[index] == 0) {
                    balance_error();
                    show_bal(index);
                    amount = get_amount("withdrawn", "withdrawal");

                    if (amount == -1) continue;

                    if(amount > balances[index]) {
                        balance_error();
                    } else {
                        change_bal(index, amount * -1);
                        cout << "Transacation success!";
                        show_bal(index, 1);
                    }
                }

                break;
            case 4:
                if (balances[index] == 0) {
                    balance_error();
                } else {
                    int target, target_index;
                    cout << "Enter target account: ";
                    cin >> target;

                    target_index = find_pid(target);
                    
                    if (target_index > -1 && target_index != index) {
                        show_bal(index);
                        amount = get_amount(
                            "transffered to PID " + to_string(accounts[target_index]), 
                            "fund transfer"
                        );

                        if (amount == -1) continue;

                        if (amount > balances[index]) balance_error();
                        
                        else {
                            change_bal(index, amount * -1);
                            change_bal(target_index, amount);
                            show_bal(index);
                            cout << "Transfer success!\n";
                            system("pause");
                        }

                    }
                }              
                break;
        }

    }

    return 0;
}