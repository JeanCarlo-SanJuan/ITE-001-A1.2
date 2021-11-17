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

float showCart();
void resetCart();
void checkOut();

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
string user, pass, usertxt, passtxt;
const int W = 40;
float total;

string username[4] = {"Jordan", "Anna", "Michael", "hello"};
string password[4] = {"123456", "1234", "1234567", "world"};
float userbalance[4] = {5600, 3000, 1300, 4000};
int G_usernum;
bool G_guest = false;
// admin
string adminuser[1] = {"Admin"};
string adminpass[1] = {"admin001"};

const string ARROW = "  >  ";
const string ENDMSG = "\n\t\tThank you, Please come again!\n\n";

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
float G_data[CAT][MAX_ITEM_ID][4] = {
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
    const int ADMIN = 4;
    const int QUIT = 5;
    bool login_success;

    string login_words[] = {
        "Register", 
        "Login", 
        "Guest Login", 
        "Administrator", 
        "Quit"
    };

    while (true) {
        login_success = false;

        cls();
        welcomeScreen();

        for (i = 0; i < 5; i++) {
            showItem(i, login_words[i]);
        }

        getAction("Your Action: ");

        switch (action) {
            case REGISTRATION:
                accountRegistration();
                break;
            case MEMBER_LOGIN:
                login_success = login();
                if (!login_success) {
                    cout << "\n\t\tInvalid account! Please try again.\n\n";
                    pause();
                }
                else {
                    loadingScreen();
                    userProfile();
                    break;
                }
                break;
            case GUESS_LOGIN:
                G_guest = true;
                login_success = true;
                break;
            case QUIT:
                cout << ENDMSG;
                return 0;
            case ADMIN:
                login_success = adminlogin();
                if (login_success) transRecord();
                else {
                    cout<<"\n\t\tInvalid account! Please try again.\n\n";
                    pause();
                }
        }

        if (login_success) {
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

    cout << "\t\ttransaction ";
    if (cash == 0) {
        cout << "cancelled...";
    } else cout << "success!";

    cout << "\t\t================================================"; 

    return cash;
}

void userProfile() {
    int options_size = 2;

    string profile_options[] = {
        "Cash in",
        "Proceed to menu"
    };

    float *balance = &userbalance[G_usernum];
    while (true) {
        cls();
        cout << "\n\t\t=================================================\n";
        cout << "\t\t\t      Welcome to ABC " << username[G_usernum] << "!\n";
        cout << "\t\t=================================================\n\n";

        cout << "\t\tAccount Balance: PHP " << *balance << endl << endl;
        for (i = 0; i < options_size; i++) {
            showItem(i, profile_options[i]);
        }
        getAction("Your action: ");

        if (action == 1) {
            *balance += cashIn();
        } else break;
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

// Account related
void accountRegistration() {
    cls();
    welcomeScreen();

    cout << "\t\tType a username and password to register.\n";
    cout << "\n\t\t" << ARROW << "Select Username: ";
    cin >> user;
    cout << "\t\t" << ARROW << "Select Password: ";
    cin >> pass;
    cout << "\n\t" << ARROW
         << "You're now signed up! you may now use your account to login.\n\n";
    pause();

    ofstream file;
    file.open(user + ".txt");
    file << user << "\n" << pass;
    file.close();
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
            resetCart();

            // If the customer is a guest return to login system
            if (G_guest) {
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
    float *stocks;
    for (category = 0; category < CAT; category++) {
        for (item = 0; item < MAX_ITEM_ID; item++) {
            stocks = &G_data[category][item][1];
            *stocks += current_time % 100;
            *stocks += (int(pow(*stocks, 2)) % 100) +
                       (current_time % int(G_data[category][item][2])) + 5;
        }
    }
}

bool login() {
    string pass = "";
    cls();
    welcomeScreen();

    cout << "\t\tEnter your username and password.";
    cout << "\n\n\t\t" << ARROW << "Username: ";
    cin >> user;
    cout << "\t\t" << ARROW << "Password: ";
    cin >> pass;

    ifstream read(user + ".txt");
    getline(read, usertxt);
    getline(read, passtxt);
    read.close();
    
    for (i = 0; i < 4; i++) {
        if ((user == username[i] && pass == password[i]) ||
            (usertxt == user && passtxt == pass)) {
            G_usernum = i;
            return true;
        }
    }
    return false;
}

bool adminlogin() {
    string apass;
    string auser;
    cls();
    welcomeScreen();

    cout << "\t\tEnter your username and password.";
    cout << "\n\n\t\t" << ARROW << "Username: ";
    cin >> auser;
    cout << "\t\t" << ARROW << "Password: ";
    cin >> apass;

    for (i = 0; i < 1; i++) {
        if ((auser == adminuser[i] && apass == adminpass[i])) {
            return true;
        }
    }
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
    int stock = G_data[category][item][1]; // Todo convert to pointer
    string item_name = G_names[category][item];

    if (stock <= 0) {
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
    if (input_slices > 0) {
        if (input_slices <= stock) {
            G_data[category][item][3] += input_slices;
            G_data[category][item][1] -= input_slices;
            cout << "\t\tAdded to cart!\n";
            pause();
            return false;
        }
        cout << "\t\tNot enough stock!\n";
        pause();
    } else {
        inputError();
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
    } else {
        char removeYN;
        getAction("Which item would you like to remove? ");
        int target = action - 1;
        bool done = false;
        float *in_cart;
        i = 0; // as a counter
        for (category = 0; category < CAT; category++) {

            if (done) break;
            
            for (item = 0; item < MAX_ITEM_ID; item++) {
                    in_cart = &G_data[category][item][3];
                if (*in_cart > 0) {
                    if (i == (target)) {
                        G_data[category][item][1] += *in_cart;
                        *in_cart = 0;
                        done = true;
                        break;
                    } else {
                        i++;    
                    }
                }
            }
        }

        if (showCart() > 0) {
            // ask if user wants to remove some more
            cout << "\tWould you like to remove other items?: (Y/N) ";
            cin >> removeYN;
            if (removeYN == 'Y' || removeYN == 'y') {
                cls();
                removeItem();
            } else if (removeYN == 'N' || removeYN == 'n') {
                showCart();
            } else
                inputError();
        } else pause();
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
    int payment_method;
    float subtotal = showCart();
    if (subtotal > 0) {
        while (true) {
            cout << endl << endl;
            showCategory("Checkout");

            cout << "\t\tPlease enter mode of payment:" << endl
                 << "\t\t[1] Cash" << endl
                 << endl
                 << "\t\t> ";
            cin >> payment_method;
            cout << endl;

            if (payment_method == 1) {
                break;
            } else {
                cls();
                showCart();
            }
        }
    }

    switch (payment_method) {
    case 1:
        while (true) {
            cout << "\t\tPlease pay Php: " << fixed << setprecision(2)
                 << subtotal << " in cash." << endl;
            cout << "\t\t> ";
            float payment = ask<float>("");
            total += subtotal;
            if (payment > subtotal) {
                cout << "\n\t\tThank you!\n"
                     << "\t\tYour change is Php: " << fixed << setprecision(2)
                     << (payment - subtotal) << endl;
                break;
            } else if (payment == subtotal) {
                cout << "\t\tThank you!" << endl;
                break;
            } else {
                cout << endl;
                cout << "\t\tInvalid Payment!" << endl;
            }
        }
        break;
    }
    pause();
}

void transRecord(){
    
    cout<<"\t\tCurrent Total: "<<total;
    pause();
}