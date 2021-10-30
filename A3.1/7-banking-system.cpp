#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

map<int, float> data = {
    {445236, 10000},
    {000001, 100},
    {000002, 200}
};

int pid = -1, operation;
int attempts = 0;
const int MAX_ATTEMPTS = 3;
float amount;

void show_menu();

int authenticate(int _pid) {
    for (auto pair: data) {
        if (pair.first == _pid) {
            return _pid;
        }
    }

    cout << "acount not found!\n\n";
    return -1;
}

void halt() {
    cout << "\nPress any key to continue...\n";
    cin.get();
    cin.ignore(1);
}

error(int cause) {
    switch (cause) {
        case 'A':
            cout << "Please enter valid amount.\n";
            break;
        case 'B':
            cout << "You have insufficient balance to do the transaction!\n";
            break;
    }

    halt();
}

void show_bal(bool pause = 0) {
    cout << "\nCurrent Balance of PID " << pid << ":\nPhp "
     << fixed << setprecision(2) << data[pid] << endl;
    if (pause) {
        halt();
    }
}

void get_amount(string msg, string cancel, bool check_bal = false) {
    cout << "Enter amount to be " + msg + ": ";
    cin >> amount;

    if (amount == 0) {
        cout << "Cancelling " + cancel + "...\n";
    } else 
    if (amount < 0) {
        error('A');
        amount = 0;
    } else
    if (check_bal && amount > data[pid]) {
        error('B');
        amount = 0;
    }
}

void change_bal(int _pid, float _amount) {
    system("cls");

    data[_pid] += _amount;
    cout << "Transacation success!\n";

    if (_pid == pid) {
        show_bal(1);
    }
}

int main() {

    while(attempts < MAX_ATTEMPTS) {
        show_menu();

        if (operation == 5) {
            break;
        }

        cout << "User Authentication is required...\nLogin attempts remaining: " << MAX_ATTEMPTS - attempts <<  "\nEnter PID: ";
        cin >> pid;
        pid = authenticate(pid);

        if (pid == -1) {
            attempts++;

            if (attempts == MAX_ATTEMPTS) {
                cout << "You have reached the maximum login attempts!\nEnding program...";
            }
        } else {
            attempts = 0;

            show_bal((operation == 1));

            switch(operation) {
                case 2:
                    get_amount("deposited", "deposit");
                    
                    if (amount != 0) {
                        change_bal(pid, amount);
                    }
                    
                    break;                    
                case 3:
                    if (data[pid] == 0) {
                        error('B');
                    } else {
                        get_amount("withdrawn", "withdrawal", true);

                        if (amount != 0) {
                            change_bal(pid, amount * -1);
                        }
                    }
                    break;
                case 4:
                    if (data[pid] == 0) {
                        error('B');
                    } else {
                        int target;
                        cout << "Enter target account: ";
                        cin >> target;

                        target = authenticate(target);

                        if (target != -1) {
                            get_amount(
                                "transferred to PID " + to_string(target),
                                "fund transfer",
                                true
                            );

                            if (amount != 0) {
                                change_bal(target, amount);
                                change_bal(pid, amount * -1);
                            }
                        }
                    }

                    break;
            }
        }
    }

    return 0;
}

void show_menu() {
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
        operation = action;
    } else {
        show_menu();
    }

}