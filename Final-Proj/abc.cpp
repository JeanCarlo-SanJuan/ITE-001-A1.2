#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <cmath>
#include <chrono>
#include <thread>
using namespace std;
    void cls();
    void wait(int);
    void pause();
    bool login();
    void print_item(int, string);
    void menuScreen();
    void welcomeScreen();
    void loadingScreen();
    void paymentScreen();
    void show_stock(int, int);
    void randomize_stocks();
    void account_registration();
    void ask_quantity(int, int);
    bool has_slices(int, int);
    void show_price(int, int );

//Global vars
string user, pass, icon, usertxt, passtxt;
// predefined valid username and password
string username[4] = {"TIP", "Comp", "Godis", "hello"};
string password[4] = {"tip44", "science45", "good", "world"};
string G_categories[] {
    "Bread",
    "Pastries",
    "Checkout",
    "Reset Cart",
    "Exit Program"
};

time_t current_time;
const int CAT = 2;

string G_product_names[CAT][3] = {
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
    }
};

// G_G_product_data[i][j][k]
// determines...
// i - category
// j - product
// k - price, stock, slices, quantity in cart
float G_product_data[CAT][2][4] = {
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

int i, j;

int main()
{
    int option;
    const int REGISTRATION = 1;
    const int MEMBER_LOGIN = 2;
    const int GUESS_LOGIN = 3;
    icon[1] = 3;
    icon[2] = 16;
    bool login_success = false;
    cls();
    welcomeScreen();

    cout << "     [1]  " << icon[2] << "  Register"
    << "\n     [2]  " << icon[2] << "  Login"
    << "\n     [3]  " << icon[2] << "  Guest Login"
    << "\n\n     Your Option: ";
    cin >> option;

    switch (option) {
        case REGISTRATION:
            account_registration();
            break;
        case MEMBER_LOGIN:
            login_success = login();
            if (!login_success) {
                cout << "\n\n     Invalid account! Please try again.\n\n";
            }
            break;
        case GUESS_LOGIN:
            login_success = true;
            break;
    }

    if (login_success) {
        loadingScreen();
        //randomize_stocks();
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

int get_action(string msg) {
    int action;
    cout << msg;
    cin >> action;
    return action;
}

// put the menu content here
void menuScreen()
{   
    cls();
    cout << "\n             \xB2\xB2~~~~~~~~~~~~~~~~~~~  Menu  ~~~~~~~~~~~~~~~~~~~\xB2\xB2\n";

    for (i = 0; i < 5; i++) {
        print_item(i + 1, G_categories[i]);
    }

    int action = get_action("\nWhat would you like to buy / do? ");

    if (action >= 1 && action <= 2) {
        // Go to sub-menu
        int category = action - 1;
        cout << G_product_names[category][0] << ":" << endl;
        for (i = 1; i < 3; i++) {
            print_item(i, G_product_names[category][i]);
            show_stock(category, i - 1);
            show_price(category, i - 1);
        }
        int item = get_action("Select item: ") - 1;

        ask_quantity(category, item);
    }
    switch (action) {
        case 3:
            paymentScreen();
            return;
            break;
        case 4:
            break;
            //Reset cart;
        case 5:
            break;
            //end program
    }

    menuScreen();
    /*
    
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
 */}

void show_price(int cat, int item) {
    cout << "Price per " << ((has_slices(cat, item)) ? "slice":"item")
    << " is Php " << G_product_data[cat][item][0] << endl;
}

void print_item(int nth, string item) {
    cout << nth << ". " << item << endl;
}

void show_stock(int cat, int item) {
    cout << "In stock: " << G_product_data[cat][item][1] << endl;
}

/* void show_item_info(int nth, int cat, int item_id) {
    float price = G_product_data[cat][item][1];
    int stock = G_product_data[cat][item][2];
    string name = G_product_names[cat][item_id + 1];

    cout << nth << ". " << name << 
    "\t Stock =" << stock
    "\t Price =" << price;
} */

void account_registration() {
    cls();
    welcomeScreen();

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

bool has_slices(int cat, int item) {
    return G_product_data[cat][item][2] != 1;
}
void loadingScreen()
{
    /* cout << "\n\n               Loading ";
    char x = 219;

    for (int i = 0; i < 35; i++)
    {
        cout << x;
        if (i < 10)
            wait(130);
        if (i >= 10 && i < 20)
            wait(90);
        if (i >= 10)
            wait(25);
    } */
}

void paymentScreen() {
  cout << "Receipt:" << endl;
  cout << "--------------------------------------------------" << endl;
  for (int category = 0; category < CAT; category++) {
    for (int product = 0; product < 2; product++) {
        cout << G_product_names[category][product + 1] << " x "
        << G_product_data[category][product][3] << endl;
    }
  }

  pause();
}

bool login()
{
    string pass = "";

    cls();
    welcomeScreen();

    cout << "     Enter your username and password.";
    cout << "\n\n     " << icon[2] << "  Username: ";
    cin >> user;
    cout << "     " << icon[2] << "  Password: ";

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
    cin.ignore().get();
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
            stocks = &G_product_data[i][j][1];
            *stocks += current_time % 100;
            *stocks = (int(pow(*stocks, 2)) % 100) + (current_time % int(G_product_data[i][j][2])) + 5;

            cout << G_product_data[i][j][1] << endl;
        }
    }
}

void wait(int ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

void ask_quantity(int category, int item) {
    int slices = G_product_data[category][item][2];
    int stock = G_product_data[category][item][1]; // Todo convert to pointer
    string item_name = G_product_names[category][item + 1];
    int input_slices = 0;
    cls();
    show_stock(category, item);

    if (has_slices(category, item)) {
        cout << "How many slices of " + item_name + " would you like to buy ( " << slices << " slices in 1 whole): ";
    } else {
        cout << "How many " + item_name + " would you like to buy? ";
    }
    // validation
    cin >> input_slices;

    if (input_slices > 0) {
        if (input_slices <= stock) {
            G_product_data[category][item][3] += input_slices;
            G_product_data[category][item][1] -= input_slices;
            cout << "Added to cart!\n";
            pause();
            return;
        } else {
            cout << "Not enough stock!\n";
        }

    } else {
        cout << "Invalid input!\n";
    }

    pause();
    return ask_quantity(category, item);
}