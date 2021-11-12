#include <chrono>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
using namespace std;
    void cls();
    void pause();
    bool login();
    void menuScreen();
    void welcomeScreen();
    void loadingScreen();
    void paymentScreen();
    void randomize_stocks();
    void account_registration();

//Global vars
string G_USER, G_PASS, G_ICON, G_USERTEXT, G_PASSTEXT;
// predefined valid username and password
const string VALID_USERNAMES[4] = {"TIP", "Comp", "Godis", "hello"};
const string VALID_PASSWORDS[4] = {"tip44", "science45", "good", "world"};

time_t current_time;
const int CATEGORY_COUNT = 2;
const int PRODUCT_COUNT = 2;
const int PRODUCT_DATA = 4;

string G_PRODUCT_NAMES[CATEGORY_COUNT][PRODUCT_COUNT + 1] = {
    {
        "Bread", // First element in column contains category
        // Items
        "Pandesal",
        "Wheat Loaf Bread",
    },
    {
        "Pastries",
        "Chocolate Cookies",
        "Mocha Cake",
    }};

// product_data[i][j][k]
// determines...
// i - category
// j - product
// k - price, stock, slices, quantity in cart
float G_PRODUCT_DATA[CATEGORY_COUNT][PRODUCT_COUNT][PRODUCT_DATA] = {
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
    const int REGISTRATION = 1;
    const int MEMBER_LOGIN = 2;
    const int GUESS_LOGIN = 3;

    G_ICON[1] = 3;
    G_ICON[2] = 16;
    bool login_success = false;
    cls();
    welcomeScreen();

    cout << "     [1]  " << G_ICON[2] << "  Register" << endl;
    cout << "     [2]  " << G_ICON[2] << "  Login" << endl;
    cout << "     [3]  " << G_ICON[2] << "  Guest Login" << endl;;
    cout << endl;
    cout << "     Your Option: ";
    cin >> option;

    switch (option) {
        case REGISTRATION:
            account_registration();
            break;
        case MEMBER_LOGIN:
            login_success = login();
            if (!login_success) {
                cout << endl << endl;
                cout << "     Invalid account! Please try again.";
                cout << endl << endl;
            }
            break;
        case GUESS_LOGIN:
            login_success = true;
            break;
    }

    if (login_success) {
        loadingScreen();
        menuScreen();
        paymentScreen();
    } else {
        return main();
    }

    return 0;
}

void welcomeScreen ()
{
    cout << endl;
    cout << "                          ------" << "  Welcome To  " << "------";
    cout << endl << endl;
    cout << "     \xB2\xB2\xB2~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\xB2\xB2\xB2" << endl;
    cout << "     \xB2\xB2                                                               \xB2\xB2" << endl;
    cout << "     \xB2\xB2                  | Automated Bakery Cashier |                 \xB2\xB2" << endl;
    cout << "     \xB2\xB2                                                               \xB2\xB2" << endl;
    cout << "     \xB2\xB2\xB2~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\xB2\xB2\xB2" << endl;
    cout << endl << endl;
}

// put the menu content here
void menuScreen()
{
    randomize_stocks();
    cls();
    cout << endl;
    cout << "             \xB2\xB2~~~~~~~~~~~~~~~~~~~  Menu  ~~~~~~~~~~~~~~~~~~~\xB2\xB2" << endl;
    cout << "             \xB2\xB2                                              \xB2\xB2" << endl;
    cout << "             \xB2\xB2   1. Bread                                   \xB2\xB2" << endl;
    cout << "             \xB2\xB2      - Pandesal                 5            \xB2\xB2" << endl;
    cout << "             \xB2\xB2      - Wheat Loaf Bread                      \xB2\xB2" << endl;
    cout << "             \xB2\xB2                                              \xB2\xB2" << endl;
    cout << "             \xB2\xB2   2. Pastries                                \xB2\xB2" << endl;
    cout << "             \xB2\xB2      - Chocolate Cookies        5            \xB2\xB2" << endl;
    cout << "             \xB2\xB2      - Mocha Cake                            \xB2\xB2" << endl;
    cout << "             \xB2\xB2                                              \xB2\xB2" << endl;
    cout << "             \xB2\xB2~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\xB2\xB2" << endl;
    cout << endl;
}

void account_registration() {
    cls();
    welcomeScreen();

    cout << "    Type your chosen username and password to register." << endl;
    cout << endl;
    cout << "     " << G_ICON[2] << "  Select Username: ";
    cin >> G_USER;
    cout << "     " << G_ICON[2] << "  Select Password: ";
    cin >> G_PASS;
    cout << endl;
    cout << "     " << G_ICON[1] << "  You're signed up! you may now use your account to login." << endl;
    cout << endl;
    pause();

    ofstream file;
    file.open(G_USER + ".txt");
    file << G_USER << "\n"
        << G_PASS;
    file.close();
}

void loadingScreen()
{
    cout << endl << endl;
    cout << "               Loading ";
    char x = 219;

    for (int i = 0; i < 35; i++)
    {
        cout << x;
        if (i < 10)
            this_thread::sleep_for (chrono::milliseconds(150));
        if (i >= 10 && i < 20)
            this_thread::sleep_for (chrono::milliseconds(20));
        if (i >= 10)
            this_thread::sleep_for (chrono::milliseconds(25));
    }
}

void paymentScreen() {
  cout << "Receipt:" << endl;
  cout << "--------------------------------------------------" << endl;
  for (int category = 0; category < CATEGORY_COUNT; category++) {
    for (int product = 0; product < PRODUCT_COUNT; product++) {
      cout << G_PRODUCT_NAMES[category][product + 1] << " x ";
      cout << G_PRODUCT_DATA[category][product][3] << endl;
    }
  }
}

bool login()
{
    // TODO: I'm not entirely sure what the flow here is?

    string password_input = "";
    char c;

    cls();
    welcomeScreen();

    cout << "     Enter your username and password." << endl;
    cout << endl;
    cout << "     " << G_ICON[2] << "  Username: ";
    cin >> G_USER;
    cout << "     " << G_ICON[2] << "  Password: ";
    // c = _getwch();

    // // display * as password
    // while (c != 13)
    // {
    //     pass.push_back(c);
    //     cout << '*';
    //     c = _getwch();
    // }
    // cout << "\n";

    password_input = "hello";

    ifstream read(G_USER + ".txt");
    getline(read, G_USERTEXT);
    getline(read, G_USERTEXT);

    for (i = 0; i < 4; i++)
    {
        if ( (G_USER == VALID_USERNAMES[i] && G_PASS == VALID_PASSWORDS[i])
          || (G_USERTEXT == G_USER && G_PASSTEXT == G_PASS)
           )
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
    // TODO: We can probably use macros or something here...
    system("cls||clear");
}

void randomize_stocks()
{
    // TODO: I think we can rename these variables
    int i, j;
    float *stocks;
    for (i = 0; i < CATEGORY_COUNT; i++)
    {
        for (j = 0; j < 2; j++)
        {
            stocks = &G_PRODUCT_DATA[i][j][1];
            *stocks += current_time % 100;
            *stocks = (int(pow(*stocks, 2)) % 100) + (current_time % int(G_PRODUCT_DATA[i][j][2])) + 5;

            cout << G_PRODUCT_DATA[i][j][1] << endl;
        }
    }
}
