#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>

using namespace std;

void cls();
void pause();
void wait();

bool login();
bool adminlogin();
void menuScreen();
void userProfile();
void loadingScreen();
void welcomeScreen();
void randomizeStocks();
void getAction(string);
void accountRegistration();
bool askQuantity();
void saveUserInfo(string, string, float);
float showCart();
void resetCart();
void checkOut();

void accountReset();
void askCredentials();
void showCategory(string);
void showItem(int, string);
void showItemInfo(int);
void showItemsInCategory();
bool hasSlices();
void selectItem();
void removeItem();
void transRecord();
float cashIn();

// Globals
time_t current_time;
const int CAT = 2;
const int MAX_ITEM_ID = 5;
int i, j, k, action, category, item;
const int W = 40;
float G_current_sales;

const int G_sampleSize = 4;
string G_usernames[G_sampleSize] = {"Jordan", "Anna", "Michael", "hello"};
string G_passwords[G_sampleSize] = {"123456", "1234", "1234567", "world"};
float G_balances[G_sampleSize] = {5600, 3000, 1300, 4000};
string G_vouchers[G_sampleSize] = {"ITE001PASSED", "HESOYAM", "COMPUTERSCIENCE", "DISCOUNTSFORALL"};

//From oop implementation
string G_name;
string G_password;
float G_balance;

const int asAdmin = -1, asUser = -2, asGuest = -3, notYet = -4;
int loggedIn = notYet;

// admin
string G_adminNames[1] = {"Admin"};
string G_adminPasswords[1] = {"admin001"};

const string ARROW = "  >  ";
const string ENDMSG = "\n\t\tThank you, Please come again!\n\n";
const string INVALID_ACCOUNT_MSG = "\n\t\tInvalid account! Please try again.\n\n";
const int MAX_CATEGORY = 7;

string G_categories[]{
    "Bread",
    "Pastries",
    "View Cart",
    "Remove item\\s from cart",
    "Checkout",
    "Reset Cart",
    "Log Out",
};

string G_names[CAT][5] = {
    {
        "Pandesal",
        "Wheat Loaf Bread",
        "Spanish Bread",
        "Ensaymada",
        "Cheese Bread",
    },
    {
        "Peanut Butter Cupcake",
        "Mocha Cake",
        "Cheese Cake",
        "Apple Cake",
        "Brownies"
    }
};

// G_data[i][j][k]
// determines...
// i - category
// j - item
// k - price, stock, slices, quantity in cart
int G_data[CAT][MAX_ITEM_ID][4] = {
    {
        // Bread
        //{price per slice, stock in slices, slices per whole (1 means 1 whole ), quantity in cart by slices}
        {5, 50, 1},  // Pandesal
        {11, 45, 10}, // Wheat Loaf
        {6, 80, 1},
        {12, 40, 1},
        {15, 30, 1}
    },
    {
        // Pastries
        {18, 33, 1}, // Peanut Butter Cupcake
        {35, 43, 6},  // Mocha cake
        {33, 29, 6},
        {30, 18, 6},
        {20, 20, 1}
    }
};

template <typename T>
T ask(string msg = "") {
    T c;
    do {
        cout << msg;
        cin >> c;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
        } else return c;
    } while (true);
}

int main() {
    const int REGISTRATION = 1;
    const int MEMBER_LOGIN = 2;
    const int GUESS_LOGIN = 3;
    const int QUIT = 4;
    const int ADMIN = 5;

    string login_words[] = {
        "Register", 
        "Login", 
        "Guest Login",
        "Quit"
    };

    while (true) {
        cls();
        welcomeScreen();
        accountReset();

        for (i = 0; i < 4; i++) {
            showItem(i, login_words[i]);
        }

        getAction("Your Action: ");

        switch (action) {
            case REGISTRATION:
                accountRegistration();
                break;
            case MEMBER_LOGIN:
                if (login()) {
                    loadingScreen();
                    userProfile();
                } else {
                    cout << INVALID_ACCOUNT_MSG;
                    pause();
                }
                break;
            case GUESS_LOGIN:
                loggedIn = asGuest;
                break;
            case QUIT:
                cout << ENDMSG;
                return 0;
                break;
            case ADMIN:
                if (adminlogin()) {
                    transRecord();
                    continue;
                }
                cout << INVALID_ACCOUNT_MSG;
                pause();
                break;
        }

        if (loggedIn != notYet) {
            randomizeStocks();
            loadingScreen();
            menuScreen();
        }
        //Repeat loop
    }

    return 0;
}

float cashIn()
{
    float cash;

    do {
        cout << endl;
        cash = ask<float>("\t\tCash in amount: ");

        if(cash < 0) {
            cout << "\t\tInvalid Amount!\n";
            pause();
        } else break;

    } while (true);

    return cash;
}

void userProfile() {
    int options_size = 2;

    string profile_options[] = {
        "Cash in",
        "Proceed to menu"
    };

    while (true) {
        cls();
        cout << "\n\t\t=================================================\n";
        cout << "\t\t\t      Welcome to ABC " << G_name << "!\n";
        cout << "\t\t=================================================\n\n";

        cout << "\t\tAccount Balance: PHP " << G_balance << endl << endl;
        for (i = 0; i < options_size; i++) {
            showItem(i, profile_options[i]);
        }
        getAction("Your action: ");

        if (action == 1) {
            G_balance += cashIn();

            if (loggedIn > asAdmin) {
                G_balances[loggedIn] = G_balance; 
            }

            if (loggedIn == asUser) {
                saveUserInfo(G_name, G_password, G_balance);
            } 
            cout << "\n\t\t Top up success!";
            pause();
        } else if (action == 2){
            break;
        } else userProfile();
    }
}

void cls() { system("cls||clear"); }

void wait(int ms) { this_thread::sleep_for(chrono::milliseconds(ms)); }

void pause() {
    cout << "\n\t\tPress Enter to continue...";
    cin.ignore().get();
}

void showCategory(string cat) {
    cout.width(W);
    cout << "\n\t\xB2\xB2~~~~~~~~~~~~~~~~~~~~ " << cat
         << " ~~~~~~~~~~~~~~~~~~~\xB2\xB2\n\n";
}

void welcomeScreen() {
    cout.width(W);
    cout << "\n\t\t\t------"
         << " Welcome To "
         << "------\n";

    cout << "\n\t\xB2\xB2\xB2" << setw(55) << setfill('~') << "\xB2\xB2\xB2";
    cout << setfill(' ');
    cout << "\n\t \xB2\xB2" << setw(54) << "\xB2\xB2";
    cout << "\n\t \xB2\xB2                     | ABC |                        "
            "\xB2\xB2";
    cout << "\n\t \xB2\xB2" << setw(54) << "\xB2\xB2";
    cout << "\n\t\xB2\xB2\xB2" << setw(55) << setfill('~') << "\xB2\xB2\xB2";
    cout << setfill(' ');
    cout << endl << endl;
}

void getAction(string msg = "") {
    action = ask<int>("\n\t\t" + msg);
}

void saveUserInfo(string _user, string _pass, float amount) {
    ofstream file;
    file.open(_user + ".txt");
    file << _user << endl 
         << _pass << endl 
         << fixed << setprecision(2) << amount;
    file.close();
}

// Account related
void accountRegistration() {
    cls();
    welcomeScreen();
    cout << "\t\tType a username and password to register.";
    askCredentials();

    const int min_top_up = 100;
    int amount;
    do {
        cout << "\n\t\tPlease top up at least Php " << min_top_up << endl;
        amount = ask<int>("\t\t" + ARROW + "Enter amount: ");
        
        if (amount == 0) {
            cout << "\t\tRegistration cancelled...";
            pause();
            break;
        }

        if (amount >= min_top_up) {
            cout << "\n\t\t" << ARROW
                 << "You're now signed up! you may now use your account to login.\n\n";
            saveUserInfo(G_name, G_password, amount);
            pause();
            break;
        }

        cout << "\t\tPlease enter a valid amount!\n";
    } while (amount < min_top_up);
}

void showItem(int index, string item) {
    cout << "\t\t[" << index + 1 << "]" << ARROW << item << endl;
}

void inputError() {
    cout << "\t\tInvalid input!\n";
    pause();
}

void menuScreen() {
    cls();
    showCategory("Menu");

    for (i = 0; i < MAX_CATEGORY; i++) {
        showItem(i, G_categories[i]);
    }

    getAction("What would you like to buy / do? ");
    cls();

    switch (action) {
        case 1:
        case 2:
            cout << fixed << setprecision(0);
            selectItem();
            break;
        case 3:
            showCart();
            pause();
            break;
        case 4:
            removeItem();
            break;
        case 5:
            checkOut();
            pause();
            resetCart();

            // If the customer is a guest return to login system
            if (loggedIn == asGuest) {
                return;
            }
            break;
        case 6:
            resetCart();
            pause();
            break;
        case 7:
            resetCart();
            return;
            break;
    }

    menuScreen();
}

// Items related
void randomizeStocks() {
    time(&current_time);

    for (category = 0; category < CAT; category++) {
        for (item = 0; item < MAX_ITEM_ID; item++) {
            G_data[category][item][1] += current_time % 100;
        }
    }
}

bool login() {    
    cls();
    welcomeScreen();
    cout << "\t\tEnter username and password to login...";
    askCredentials();

    string _name, _pass, _balance;
    ifstream read(G_name + ".txt");
    getline(read, _name);
    getline(read, _pass);
    getline(read, _balance);
    read.close();

    if ( (G_name.compare(_name) == 0) && (G_password.compare(_pass) == 0) ) {
        G_name = _name;
        loggedIn = asUser;
        G_password = _pass;
        G_balance = stof(_balance);
        return true;
    }

    //Check predefined accounts
    for (i = 0; i < G_sampleSize; i++) {
        if ( (G_name.compare(G_usernames[i]) == 0) && (G_password.compare(G_passwords[i]) == 0) ) {
            loggedIn = i;
            G_name = G_usernames[i];
            G_password = G_passwords[i];
            //Todo
            G_balance = G_balances[i];
            return true;
        }
    }

    accountReset();
    return false;
}

void accountReset() {
    G_name = "";
    G_password = "";
    G_balance = 0;
    loggedIn = notYet;
}

void askCredentials()  {
    cout << "\n\n\t\t" << ARROW << "Username: ";
    cin >> G_name;
    cout << "\t\t" << ARROW << "Password: ";
    cin >> G_password;
}

bool adminlogin() {
    cls();
    welcomeScreen();
    cout << "\t\tEnter administrator username and password.";
    askCredentials();
    for (i = 0; i < 1; i++) {
        if (
            (G_name.compare(G_adminNames[i]) == 0) && 
            (G_password.compare(G_adminPasswords[i]) == 0)) {
            return true;
        }
    }

    accountReset();
    return false;
}

void loadingScreen() {
    cout << "\n\n\t\tLoading ";
    char x = 219;

    for (int i = 0; i < 35; i++) {
        cout << x;
        cout.flush();
        if (i < 10)
            wait(130);
        if (i >= 10 && i < 20)
            wait(90);
        if (i >= 10)
            wait(25);
    }
}

void showItemsInCategory() {
    category = action - 1;
    showCategory(G_categories[category]);

    for (i = 0; i < MAX_ITEM_ID; i++) {
        showItemInfo(i);
    }
    cout << "\t\t[0]" << ARROW << "Return to Menu\n";
}

void showItemInfo(int i) {
    showItem(i, G_names[category][i]);
    cout << "\t\t\t" << ARROW << "Php " << G_data[category][i][0] << "\n\t\t\t"
         << ARROW << "Stock: " << G_data[category][i][1] << endl;
}

void selectItem() {
    bool repeat = true;
    do {
        cls();
        showItemsInCategory();
        int prev_action = action;
        getAction("Select item: ");

        // Go back
        if (action == 0) {
            return;
        }

        item = action - 1;

        if (item > -1 && item < MAX_ITEM_ID) {
            repeat = askQuantity();
        }

        action = prev_action;
    } while (repeat);
}

bool askQuantity() {
    int *stock = &G_data[category][item][1];
    string item_name = G_names[category][item];

    if (*stock <= 0) {
        cout << "\t\tSorry we're out of stock of " + item_name +
                    "\n\t\tPlease choose another item from the menu\n";
        pause();
        return true;
    }

    int slices = G_data[category][item][2];
    int input_slices = 0;

    cout << "\n\t\t";
    if (hasSlices()) {
        cout << "How many slices of " + item_name + " would you like to buy? ( "
             << slices << " slices in 1 whole): ";
    } else {
        cout << "How many " + item_name + " would you like to buy? ";
    }
    // validation
    cin >> input_slices;

    if (input_slices == 0) {
        return true;
    }

    if (input_slices < 0) {
        inputError();
    } else {
        if (input_slices <= *stock) {
            G_data[category][item][3] += input_slices;
            *stock -= input_slices;
            cout << "\t\tAdded to cart!\n";
            pause();
            return false;
        }
        cout << "\t\tNot enough stock!\n";
        pause();
    }

    return true;
}

bool hasSlices() { return G_data[category][item][2] != 1; }

void resetCart() {
    for (category = 0; category < CAT; category++) {
        for (item = 0; item < MAX_ITEM_ID; item++) {
            G_data[category][item][3] = 0;
        }
    }

    cout << "\t\tCart has been resetted!\n";
}

void removeItem() {
    if (showCart() == 0) {
        pause();
        return;
    }
    getAction("\n\tWhich item would you like to remove? ");
    int target = action - 1;
    bool done = false;
    int *in_cart;
    i = 0; // as a counter
    for (category = 0; category < CAT; category++) {
        if (done) break;
        
        for (item = 0; item < MAX_ITEM_ID; item++) {
            in_cart = &G_data[category][item][3];

            if (*in_cart > 0) {
                if (i != target) {
                    i++;
                } else {
                    G_data[category][item][1] += *in_cart;
                    *in_cart = 0;
                    done = true;
                    break;
                }
            }
        }
    }

    if (showCart() <= 0) {
        pause();
        return;
    }

    char response;
    while (true) {
        // ask if user wants to remove some more
        cout << "\n\n\tWould you like to remove other items?: (Y/N) ";
        cin >> response;
        
        switch(response) {
            case 'Y': case 'y':
                cls();
                return removeItem();
                break;
            case 'N': case 'n':
                return;
                break;
            default:
                inputError();
        }
    }
}

float showCart() {
    i = 0; // Counter for all the items regardless of the category
    int in_cart;
    float subtotal = 0;
    string item_name, item_price;
    bool isEmpty = true;

    showCategory("Cart");
    for (category = 0; category < CAT; category++) {
        for (item = 0; item < MAX_ITEM_ID; item++) {
            // ostringstream is similar to cout, but it doesn't print anything
            // to the screen.
            ostringstream item_price_tmp;

            in_cart = G_data[category][item][3];
            item_name = G_names[category][item];
            subtotal += G_data[category][item][0] * in_cart;

            // "Print" the price of the item.
            item_price_tmp << "Php " << fixed << setprecision(2)
                           << G_data[category][item][0] * in_cart;

            // Then convert that into a proper string.
            item_price = item_price_tmp.str();

            // sjp: C++ has very weak type inference and having this
            // iterator type is required :/
            //
            // What this snippet does is remove spaces from a string.
            // Reference:
            // https://stackoverflow.com/questions/83439/remove-spaces-from-stdstring-in-c
            string::iterator end_pos =
                remove(item_name.begin(), item_name.end(), ' ');
            item_name.erase(end_pos, item_name.end());

            if (in_cart > 0) {
                string lhs = to_string(in_cart) + " x " + item_name;
                cout << "        " << lhs << setw(45 - lhs.length()) << right
                     << item_price << endl;
                isEmpty = false;
            }
        }
    }

    if (isEmpty) {
        cout << "\t\tThe cart is empty!\n";
    } else {
        cout << "        "
             << "---------------------------------------------" << endl;

        ostringstream subtotal_tmp;

        subtotal_tmp << "Php " << fixed << setprecision(2) << subtotal;

        string subtotal_str = subtotal_tmp.str();

        cout << "\tSubtotal" << setw(37) << right << subtotal_str;
    }

    return subtotal;
}

void checkOut() {
    int payment_method, discount_mode;
    float subtotal = showCart();

    if (subtotal <= 0) return;
    while (true) {
        cout << endl;
        showCategory("Checkout");

        cout << "\t\tPlease enter mode of payment:" << endl
                << "\t\t[1] Cash" << endl;

        if (loggedIn == asUser || loggedIn > asAdmin) {
            cout << "\t\t[2] Charge to Account" << endl;
        }

        cout << "\n\t\t> ";
        cin >> payment_method;
        cout << endl;

        if ((payment_method == 1) || 
            ((payment_method == 2) && (loggedIn == asUser || loggedIn > asAdmin))) {

            cout << endl
                << "\t\tVouchers/Discounts:" << endl
                    << "\t\t[1] Senior Citizen/Person with Disability" << endl
                    << "\t\t[2] Promo Voucher" << endl
                    << "\t\t[3] None" << endl
                    << "\n\t\t> ";
            cin >> discount_mode;
            cout << endl;

            if (discount_mode == 1 || discount_mode == 2 || discount_mode == 3) {
                break;
            }

        } 

        cls();
        showCart();
    }

    switch (discount_mode) {
    case 1:
      cout << "\t\tYou have a 20% discount applied." << endl;;
      subtotal = subtotal * 0.8;
      break;
    case 2:
      int with_voucher;
      do {
        with_voucher = notYet;
        string voucher_code;
        cout << "\t\tPlease enter your voucher code or type QUIT to exit:" << endl
             << "\t\t> ";

        cin >> voucher_code;
        if (voucher_code.compare("QUIT") == 0) {
          with_voucher = 0;
          break;
        }
        for (int idx = 0; idx < 4; idx++) {
          if (voucher_code.compare(G_vouchers[idx]) == 0) {
            with_voucher = 1;
            break;
          }
        }
      } while (with_voucher == notYet);

      if (with_voucher) {
        double discount;
        discount = 10 + rand() % 30;
        cout << endl;
        cout << "\t\tA "
             << discount
             << "% discount was applied."
             << endl;
        subtotal = subtotal * ((100 - discount) / 100);
      }
      break;
    }

    switch (payment_method) {
    case 1:
        while (true) {
            cout << "\t\tPlease pay Php: " << fixed << setprecision(2)
                 << subtotal << " in cash." << endl;
            cout << "\t\t> ";
            float payment = ask<float>("");
            G_current_sales += subtotal;
            if (payment > subtotal) {
                cout << "\n\t\tThank you!\n"
                     << "\t\tYour change is Php: " << fixed << setprecision(2)
                     << (payment - subtotal) << endl;
                break;
            } else if (payment == subtotal) {
                cout << "\t\tThank you!" << endl;
                break;
            }
            
            cout << endl;
            cout << "\t\tInvalid Payment!" << endl;
        }
        break;
    case 2:
        if (G_balance < subtotal) {
            cout << "\t\tYour account has insufficient balance,\n\t\tplease top up or try another payment method";
            pause();
            return checkOut();
        }
        G_balance -= subtotal;

        //Since G_balance doesn't point to the original element
        if (loggedIn > -1) {
            G_balances[loggedIn] = G_balance;
        }

        G_current_sales += subtotal;
        cout << "\t\t Successfuly charged to account!";
        saveUserInfo(G_name, G_password, G_balance);
        break;
    }
}

void transRecord(){
    cout<<"\t\tCurrent Total: Php "<< G_current_sales;
    pause();
}