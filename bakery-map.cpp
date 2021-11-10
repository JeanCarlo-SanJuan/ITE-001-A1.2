#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
using namespace std;

int denominations[] = {
    1,5,10, 20,50,100,200,500,1000
};
string invalid_msg = "Invalid denomination!\n Valid denominations are: \n 1, 5, 10, 20, 50, 100, 200, 500, and 1000\n\n";

string categories[] = {
    "Bread",
    "Pastries",
    "Drinks",
    "Exit"
};

map<string, vector<int>> cart = {
// {"Product Name", int cost, int quantity}
};

map<string, int> bread_list = {
    {"Loaf Bread", 20},
    {"French Bread", 44},
    {"Croissant", 70},
    {"Swiss Roll", 80},
    {"Buns", 90},
    {"Bagel", 50},
    {"Swiss Roll", 33}
};

map<string, int> pastries = {
    {"Donuts", 10},
    {"Cake", 15},
    {"Macarons", 28},
    {"Eclairs", 75},
    {"Pretzel", 100},
    {"Pie", 121},
    {"Danishes", 59},
};

map<string, int> drinks = {
    {"Water", 0},
    {"Coffee", 18},
};

/* map<string, map<string, vector<int>>> product_menu = {
    {"Bread", {
        {"Loaf Bread", 20},
        {"French Bread", 44},
        {"Croissant", 70},
        {"Swiss Roll", 80},
        {"Buns", 90},
        {"Bagel", 50},
        {"Swiss Roll", 33}
    }},
    {"Pastries", {
        {"Donuts", 10},
        {"Cake", 15},
        {"Macarons", 28},
        {"Eclairs", 75},
        {"Pretzel", 100},
        {"Pie", 121},
        {"Danishes", 59},
    }}, 
    {
    "Drinks", {
        {"Water", 5},
        {"Coffee", 18},
    }}
}; */

void print_ordered_item(int i, string text) {
    cout << i << ". " << text << endl;
}
void print_cost(map<string, int> products) {
    int i = 0;
    for (auto product: products) {
        i++;
        cout <<  i << ". " << product.first << " - Php " << product.second << endl;
    }
}

bool exitCode = 0;

int main() {
    int menu_state = 0;
    while (!exitCode) {

        switch(menu_state) {
            case 0:
                for (string category: categories) {
                    cout << category << endl;
                }
                break;
            case 1:
                print_cost(bread_list);
                break;
            case 2: 
                print_cost(pastries);
                break;
            case 3:
                print_cost(drinks);
                break;
            case 4:
                exitCode = true;
                break;
        }

        if (!exitCode) {
            cout << "Enter action: ";
            cin >> menu_state;
            cout << endl;
        }
    }

    return 0;
}