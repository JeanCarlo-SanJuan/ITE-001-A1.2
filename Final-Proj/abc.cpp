#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <windows.h>
using namespace std;
    void cls();
    void pause();
    bool login();
    void menuScreen();
    void welcomeScreen();
    void loadingScreen();
    void randomize_stocks();
    void account_registration();

//Global vars
string user, pass, icon, usertxt, passtxt;
// predefined valid username and password
string username[4] = {"TIP", "Comp", "Godis", "hello"};
string password[4] = {"tip44", "science45", "good", "world"};

time_t current_time;
const int CAT = 2;

string product_names[CAT][3] = {
    {
        "Bread", // First element in column contains category
        // Items
        "Pandesal",
        "Wheat Loaf Bread",
    },
    {
        "Pastries",
        "Chocolate Cookies"
        "Mocha Cake",
    }};

// product_data[i][j][k]
// determines...
// i - category
// j - product
// k - price, stock, slices, quantity in cart
float product_data[CAT][2][4] = {
    {
        // Bread
        //{price per slice, stock in slices, slices per whole (1 means 1 whole ), quantity in cart by slices}
        {5, 50, 1, 0},  // Pandesal
        {11, 45, 10, 0} // Wheat Loaf
    },
    {
        // Pastries
        {18, 33, 1, 0}, // Choco cookies
        {30, 60, 6, 0}  // Mocha cake
    }};

int i, option;

int main()
{
    icon[1] = 3;
    icon[2] = 16;
    bool login_success = false;
    cls();
    welcomeScreen();

    cout << "     [1]  " << icon[2] << "  Register";
    cout << "\n     [2]  " << icon[2] << "  Login";
    cout << "\n     [3]  " << icon[2] << "  Guest Login";
    cout << "\n\n     Your Option: ";
    cin >> option;

    switch (option) {
        case 1:
            cls();
            welcomeScreen();
            account_registration();
            break;
        case 2:
            login_success = login();
            if (!login_success) {
                cout << "\n\n     Invalid! Try again.\n\n";
            }
            break;
        case 3:
            login_success = true;
            break;
        default:
            welcomeScreen();
            cout << "     Please choose your option.\n\n";
    }

    if (login_success) {
        loadingScreen();
        menuScreen();
    } else {
        return main();
    }

    return 0;
}

void welcomeScreen ()
{
    cout << "\n                          ------" << "  Welcome To  " << "------\n";
    cout << "\n     \xB2\xB2\xB2~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\xB2\xB2\xB2";
    cout << "\n     \xB2\xB2                                                               \xB2\xB2";
    cout << "\n     \xB2\xB2                  | Automated Bakery Cashier |                 \xB2\xB2";
    cout << "\n     \xB2\xB2                                                               \xB2\xB2";
    cout << "\n     \xB2\xB2\xB2~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\xB2\xB2\xB2\n\n\n";
}

// put the menu content here
void menuScreen()
{
    randomize_stocks();
    cls();
    cout << "\n             \xB2\xB2~~~~~~~~~~~~~~~~~~~  Menu  ~~~~~~~~~~~~~~~~~~~\xB2\xB2";
    cout << "\n             \xB2\xB2                                              \xB2\xB2";
    cout << "\n             \xB2\xB2   1. Bread                                   \xB2\xB2";
    cout << "\n             \xB2\xB2      - Pandesal                 5            \xB2\xB2";
    cout << "\n             \xB2\xB2      - Wheat Loaf Bread                      \xB2\xB2";
    cout << "\n             \xB2\xB2                                              \xB2\xB2";
    cout << "\n             \xB2\xB2   2. Pastries                                \xB2\xB2";
    cout << "\n             \xB2\xB2      - Chocolate Cookies        5            \xB2\xB2";
    cout << "\n             \xB2\xB2      - Mocha Cake                            \xB2\xB2";
    cout << "\n             \xB2\xB2                                              \xB2\xB2";
    cout << "\n             \xB2\xB2~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\xB2\xB2\n\n";
}

void account_registration() {
    cout << "    Type your chosen username and password to register.";
    cout << "\n\n     " << icon[2] << "  Select Username: ";
    cin >> user;
    cout << "     " << icon[2] << "  Select Password: ";
    cin >> pass;
    cout << "\n     " << icon[1] << "  You're signed up! you may now use your account to login.\n\n";
    pause();

    ofstream file;
    file.open(user + ".txt");
    file << user << "\n"
        << pass;
    file.close();
}

void loadingScreen()
{
    cout << "\n\n               Loading ";
    char x = 219;

    for (int i = 0; i < 35; i++)
    {
        cout << x;
        if (i < 10)
            Sleep(130);
        if (i >= 10 && i < 20)
            Sleep(90);
        if (i >= 10)
            Sleep(25);
    }
}

bool login()
{
    string pass = "";
    char c;

    cls();
    welcomeScreen();

    cout << "     Enter your username and password.";
    cout << "\n\n     " << icon[2] << "  Username: ";
    cin >> user;
    cout << "     " << icon[2] << "  Password: ";
    c = _getwch();

    // display * as password
    while (c != 13)
    {
        pass.push_back(c);
        cout << '*';
        c = _getwch();
    }
    cout << "\n";

    ifstream read(user + ".txt");
    getline(read, usertxt);
    getline(read, passtxt);

    for (i = 0; i < 4; i++)
    {
        if ((user == username[i] && pass == password[i]) || (usertxt == user && passtxt == pass))
        {
            return true;
        }
    }
    return false;
}

void pause()
{
    cout << "Press Enter to continue...";
    cin.get();
}

void cls()
{
    system("cls||clear");
}

void randomize_stocks()
{
    int i, j;
    float *stocks;
    for (i = 0; i < CAT; i++)
    {
        for (j = 0; j < 2; j++)
        {
            stocks = &product_data[i][j][1];
            *stocks += current_time % 100;
            *stocks = (int(pow(*stocks, 2)) % 100) + (current_time % int(product_data[i][j][2])) + 5;

            cout << product_data[i][j][1] << endl;
        }
    }
}
