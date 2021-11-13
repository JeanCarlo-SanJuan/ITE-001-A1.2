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
#include <iomanip>
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
    void printItem(int, string);
    bool askQuantity();
    bool hasSlices();
    void showItemInfo(int);
    void showCart();
    void resetCart();
    void removeItem();
    void showCategory(string);
    void showItemsInCategory();
    void selectItem();

//Globals
time_t current_time;
const int CAT = 2;
const int MAX_ITEM_ID = 5;
const int MAX_CATEGORY = 7;
int i, j, k, action, category, item;
string user, pass, usertxt, passtxt;
const int W = 40;

string username[4] = {"TIP", "Comp", "Godis", "hello"};
string password[4] = {"tip44", "science45", "good", "world"};
char icon[2] = {
    3, 16
};

char ARROW[5] = "  ";

string G_categories[]{
    "Bread",
    "Pastries",
    "View Cart",
    "Remove item\\s from cart",
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

int main() {
    ARROW[2] = 16;
    ARROW[3] = ' ';
    ARROW[4] = ' ';
    const int REGISTRATION = 1;
    const int MEMBER_LOGIN = 2;
    const int GUESS_LOGIN = 3;
    bool login_success = false;

    string login_words[] = {
        "Register","Login","Guest Login"
    };

    cls();
    welcomeScreen();

    for (i = 0; i < 3; i++) {
        printItem(i, login_words[i]);
    }

    getAction("Your Action: ");

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
    else return main();

    return 0;
}

void cls()
{
    system("cls||clear");
}

void pause()
{
    cout << "\n\t\tPress Enter to continue...";
    cin.ignore().get();
}

void showCategory(string cat) {
    cout.width(W);
    cout << "\n\t\xB2\xB2~~~~~~~~~~~~~~~~~~~  " << cat << " ~~~~~~~~~~~~~~~~~~~\xB2\xB2\n\n";
}

void wait(int ms)
{
    this_thread::sleep_for(chrono::milliseconds(ms));
}


void welcomeScreen()
{
    cout.width(W);
    cout << "\n\t\t------"
         << " Welcome To "
         << "------\n";
         
    cout << "\n\t\xB2\xB2\xB2" << setw(55) << setfill('~') << "\xB2\xB2\xB2";
    cout << setfill(' ');
    cout << "\n\t \xB2\xB2" << setw(54) << "\xB2\xB2";
    cout << "\n\t \xB2\xB2                     | ABC |                        \xB2\xB2";
    cout << "\n\t \xB2\xB2" << setw(54) << "\xB2\xB2";
    cout << "\n\t\xB2\xB2\xB2" << setw(55) << setfill('~') << "\xB2\xB2\xB2";
    cout << endl;
}

void getAction(string msg = "")
{
    cout << "\n\t\t" + msg;
    cin >> action;
}

//Account related
void accountRegistration()
{
    cls();
    welcomeScreen();

    cout << "\t\tType your chosen username and password to register.";
    cout << "\n\n\t" << icon[1] << "  Select Username: ";
    cin >> user;
    cout << "\t" << icon[1] << "  Select Password: ";
    cin >> pass;
    cout << "\n\t" << icon[0] << "  You're signed up! you may now use your account to login.\n\n";
    pause();

    ofstream file;
    file.open(user + ".txt");
    file << user << "\n"
            << pass;
    file.close();
}

void printItem(int index, string item)
{
    cout << "\t\t[" << index + 1 << "]" << ARROW << item << endl;
}

void inputError() {
    cout << "\t\tInvalid input!\n";
    pause();
}
void menuScreen()
{
    cls();
    showCategory("Menu");

    for (i = 0; i < MAX_CATEGORY; i++)
    {
        printItem(i, G_categories[i]);
    }

    getAction("What would you like to buy / do? ");
    cls();

    switch (action)
    {
    case 1: case 2:
        selectItem();
        break;
    case 3:
        //View cart
        showCart();
        break;
    case 4:
        removeItem();
        break;
    case 5:
        showCart();
        break;
    case 6:
        resetCart();
        break;
    case 7:
        cout << "Please come again!\n";
        return;
    }


    menuScreen();
 }

// Items related
void randomizeStocks()
{
    int i, j;
    float *stocks;
    for (category = 0; i < CAT; i++)
    {
        for (item = 0; j < MAX_ITEM_ID; j++)
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

    cout << "\tEnter your username and password.";
    cout << "\n\n\t" << icon[1] << "  Username: ";
    cin >> user;
    cout << "\t" << icon[1] << "  Password: ";
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
    /* cout << "\n\n\t\t\tLoading ";
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

void showItemsInCategory() {
    showCategory(G_categories[category]);

    category = action - 1;

    for (i = 0; i < MAX_ITEM_ID; i++)
    {
        showItemInfo(i);
    }
    cout << "\t\t[0]" << ARROW << "Return to Menu\n";
}

void showItemInfo(int i) {
    printItem(i, G_names[category][i]);
    cout << "\t\t\t" << ARROW << "Php " << G_data[category][i][0]
    << "\n\t\t\t" <<ARROW << "Stock: " << G_data[category][i][1] << endl;
}

void selectItem() {
    bool repeat = true;
    do {
        cls();
        showItemsInCategory();
        int prev_action = action;
        getAction("Select item: ");

        //Go back
        if (action == 0) {
            return;
        } 

        item = action - 1;

        if (item > -1 && item < MAX_ITEM_ID) {
            repeat = askQuantity();
        }

        action = prev_action;
    }
    while (repeat);
}

bool askQuantity() {
    int stock = G_data[category][item][1]; // Todo convert to pointer
    string item_name = G_names[category][item];
    
    if (stock <= 0) {
        cout << "\t\tSorry we're out of stock of " + item_name + "\n\t\tPlease choose another item from the menu\n";
        pause();
        return true;
    }

    int slices = G_data[category][item][2];
    int input_slices = 0;

    cout << "\n\t\t";
    if (hasSlices())
    {
        cout << "How many slices of " + item_name + " would you like to buy? ( " << slices << " slices in 1 whole): ";
    }
    else
    {
        cout << "How many " + item_name + " would you like to buy? ";
    }
    // validation
    cin >> input_slices;

    if (input_slices == 0) {
        return true;
    }
    if (input_slices > 0)
    {
        if (input_slices <= stock)
        {
            G_data[category][item][3] += input_slices;
            G_data[category][item][1] -= input_slices;
            cout << "\t\tAdded to cart!\n";
            pause();
            return false;
        }
        cout << "\t\tNot enough stock!\n";
        pause();
    }
    else
    {
        inputError();
    }

    return true;
}

bool hasSlices()
{
    return G_data[category][item][2] != 1;
}

void resetCart() {
    for (category = 0; category < CAT; category++)
    {
        for (item = 0; item < MAX_ITEM_ID; item++) {
            G_data[category][item][3] = 0;
        }
    }

    cout << "Cart has been resetted!\n";
    pause();
}

void removeItem() {
    char removeYN;
    //Show cart first
    showCart();
    getAction("Which item would you like to remove? ");
    //after identifying what item to remove, ask how many of that item to remove?

    i = 0; // as a counter
    for (category = 0; category < CAT; category++)
    {
        for (item = 0;item < MAX_ITEM_ID;item++)
        {
            if (i == (action - 1)) {
                G_data[category][item][3] = 0;
            }

            i++;
        }
    }
    //ask if user wants to remove some more
    cout<<"Would you like to remove other items?: (Y/N) ";
    cin>>removeYN;
    if (removeYN == 'Y' || removeYN == 'y')
    {
        removeItem();
    }
    else if (removeYN == 'N' || removeYN == 'n'){
        //Show the current cart after removing items
        showCart();
    }
    else{
        inputError();
    }
}
        /*   cout << "Receipt:" << endl;
    cout << "--------------------------------------------------" << endl; */
void showCart()
{      
    i = 0; // Counter for all the items regardless of the category
    int in_cart;
    bool isEmpty = true;

    showCategory("Cart");
    for (category = 0; category < CAT; category++)
    {
        for (item = 0;item < MAX_ITEM_ID;item++)
        {
            in_cart = G_data[category][item][3];

            if (in_cart > 0)
            {
                isEmpty = false;
                printItem(i, G_names[category][item] + " x " + to_string(in_cart));
            }
        }
    }

    if (isEmpty) {
        cout << "\t\tThe cart is empty!\n";
    }

    pause();
}