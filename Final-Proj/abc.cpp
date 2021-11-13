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
    bool login();
    void pause();
    void menuScreen();
    void loadingScreen();
    void welcomeScreen();
    void randomizeStocks();
    void getAction(string);
    void accountRegistration();
    void print_item(int, string);
    void askQuantity();
    bool hasSlices();
    void showItemInfo(int);
    void showCart();
    void resetCart();

//Globals
time_t current_time;
const int CAT = 2;
const int MAX_PRODUCT_ID = 5;
int i, j, k, action, category, item;
string user, pass, icon, usertxt, passtxt;

string username[4] = {"TIP", "Comp", "Godis", "hello"};
string password[4] = {"tip44", "science45", "good", "world"};
string G_categories[]{
    "Bread",
    "Pastries",
    "View Cart",
    "Checkout",
    "Reset Cart",
    "Exit Program"};

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
// j - product
// k - price, stock, slices, quantity in cart
float G_data[CAT][MAX_PRODUCT_ID][4] = {
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

int main() {
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
    getAction("");

    switch(action) {
        case REGISTRATION:
            accountRegistration();
            break;
        case MEMBER_LOGIN:
            login_success = login();
            if (!login_success)
            {
                cout << "\n     Invalid account! Please try again.\n\n";
                pause();
            }
            break;
        case GUESS_LOGIN:
            login_success = true;
            break;
        }

    if (login_success)
    {
        randomizeStocks();
        loadingScreen();
        menuScreen();
    }
    else
    {
        return main();
    }

    return 0;
}

void cls()
{
    system("cls||clear");
}

void pause()
{
    cout << "Press Enter to continue...";
    cin.ignore().get();
}

void wait(int ms)
{
    this_thread::sleep_for(chrono::milliseconds(ms));
}

void welcomeScreen()
{
    cout << "\n                          ------"
         << "  Welcome To  "
         << "------\n";
    cout << "\n     \xB2\xB2\xB2~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\xB2\xB2\xB2";
    cout << "\n     \xB2\xB2                                                               \xB2\xB2";
    cout << "\n     \xB2\xB2                  | Automated Bakery Cashier |                 \xB2\xB2";
    cout << "\n     \xB2\xB2                                                               \xB2\xB2";
    cout << "\n     \xB2\xB2\xB2~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\xB2\xB2\xB2\n\n\n";
}

void getAction(string msg = "")
{
    cout << msg;
    cin >> action;
}

//Account related
void accountRegistration()
{
    cls();
    welcomeScreen();

    cout << "    Type your chosen username and password to register.";
    cout << "\n\n     " << icon[2] << "  Select Username: ";
    cin >> user;
    cout << "     " << icon[2] << "  Select Password: ";
    cin >> pass;
    cout << "\n    " << icon[1] << "  You're signed up! you may now use your account to login.\n\n";
    pause();

    ofstream file;
    file.open(user + ".txt");
    file << user << "\n"
            << pass;
    file.close();
}

void print_item(int nth, string item)
{
    cout << nth + 1 << ". " << item << endl;
}

void i_error() {
    cout << "Invalid input!\n";
    pause();
}
void menuScreen()
{
    cls();
    cout << "\n             \xB2\xB2~~~~~~~~~~~~~~~~~~~  Menu  ~~~~~~~~~~~~~~~~~~~\xB2\xB2\n";

    for (i = 0; i < 6; i++)
    {
        print_item(i, G_categories[i]);
    }

    getAction("\nWhat would you like to buy / do? ");
    cls();
    if (action >= 1 && action <= 2)
    {
        cout << G_categories[category] << ":"
            << "\nProduct >> Price >> Stock available\n";

        category = action - 1;

        for (i = 0; i < MAX_PRODUCT_ID; i++)
        {
            showItemInfo(i);
        }

        getAction("\nSelect item: ");
        item = action - 1;

        if (item < MAX_PRODUCT_ID) {
            askQuantity();
        } else {
            i_error();
        }
    } else {
        switch (action)
        {
        case 3:
            //View cart
            showCart();
            break;
        case 4:
            //Checkout
            showCart();
            break;
        case 5:
            resetCart();
            //Reset cart
            break;
        case 6:
            cout << "Please come again!\n";
            return;
            //end program
            break;
        }
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

// Items related
void randomizeStocks()
{
    int i, j;
    float *stocks;
    for (category = 0; i < CAT; i++)
    {
        for (item = 0; j < MAX_PRODUCT_ID; j++)
        {
            stocks = &G_data[category][item][1];
            *stocks += current_time % 100;
            *stocks = (int(pow(*stocks, 2)) % 100) + (current_time % int(G_data[i][j][2])) + 5;
        }
    }
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
        cin >> pass;

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

void loadingScreen()
{
        // Uncomment later
    cout << "\n\n             Loading ";
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
    }
}

void showItemInfo(int i) {
    cout << i + 1 << ". " << G_names[category][i]
    << "\t>>\tPhp " << G_data[category][i][0]
    << "\t>>\t" << G_data[category][i][1] << endl;
}

void askQuantity() {
    int stock = G_data[category][item][1]; // Todo convert to pointer
    string item_name = G_names[category][item];
    
    if (stock <= 0) {
        cout << "Sorry we're out of stock of " + item_name + "\nPlease choose another item from the menu\n";
        pause();
        return;
    }

    int slices = G_data[category][item][2];
    int input_slices = 0;
    cls();

    showItemInfo(item);

    if (hasSlices())
    {
        cout << "How many slices of " + item_name + " would you like to buy ( " << slices << " slices in 1 whole): ";
    }
    else
    {
        cout << "How many " + item_name + " would you like to buy? ";
    }
    // validation
    cin >> input_slices;

    if (input_slices > 0)
    {
        if (input_slices <= stock)
        {
            G_data[category][item][3] += input_slices;
            G_data[category][item][1] -= input_slices;
            cout << "Added to cart!\n";
            pause();
            return;
        }
        cout << "Not enough stock!\n";
        pause();
    }
    else
    {
        i_error();
    }

    return askQuantity();
}

bool hasSlices()
{
    return G_data[category][item][2] != 1;
}

void resetCart() {
    for (int category_id = 0; category_id < CAT; category_id++)
    {
        for (int product_id = 0; product_id < MAX_PRODUCT_ID; product_id++) {
            G_data[category_id][product_id][3] = 0;
        }

    }
}

void showCart()
{
    /*   cout << "Receipt:" << endl;
cout << "--------------------------------------------------" << endl; */

    for (int category_id = 0; category_id < CAT; category_id++)
    {
        for (int product_id = 0; product_id < MAX_PRODUCT_ID; product_id++)
        {
            int in_cart = G_data[category_id][product_id][3];

            if (in_cart > 0)
            {
                cout << G_names[category][product_id] << " x "
                        << in_cart << endl;
            }
        }
    }

    pause();
}