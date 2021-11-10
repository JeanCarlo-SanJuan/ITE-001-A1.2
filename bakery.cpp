#include <iostream>
#include <iomanip>
#include <iterator>
#include <vector>
using namespace std;
    void print_ordered_item(int, string);

int denominations[] = {
    1,5,10, 20,50,100,200,500,1000
};

string invalid_denomination = "Invalid denomination!\n Valid denominations are: \n 1, 5, 10, 20, 50, 100, 200, 500, and 1000\n\n";

int const main_menu_size = 4;

string items[] = {
    "Loaf Bread",
    "French Bread",
    "Croissant",
    "Swiss Roll",
    "Buns",
    "Bagel",
    "Swiss Roll",

    "Donuts",
    "Cake",
    "Macarons",
    "Eclairs",
    "Pretzel",
    "Pie",
    "Danishes",

    "Water",
    "Coffee"
};

int start[main_menu_size] = {
    0, 7, 14
};

string categories[] = {
    "Bread",
    "Pastries",
    "Drinks",
    "Exit",
};

/*  vector<string> bread_list = {
    "Loaf Bread",
    "French Bread",
    "Croissant",
    "Swiss Roll",
    "Buns",
    "Bagel",
    "Swiss Roll",
 };

vector<string> pastries = {
    "Donuts",
    "Cake",
    "Macarons",
    "Eclairs",
    "Pretzel",
    "Pie",
    "Danishes",
};

vector<string> drinks = {
    "Water",
    "Coffee"
}; */

/* float prices[][] = {
    {20, 44m 70, 80, 90, 50, 33},
    {10,15,28,75,100,121,59},
    {0,18}
}; */

bool exitCode = false;

void determine_start_indices() {
    int i, j;
    for(i = 0; i < int(sizeof(items) / sizeof(items[0])); i++) {
        for (j = 0; j < int(sizeof(categories) / sizeof(categories[0])); j++) {
            if (categories[j] == items[i]) {
                start[j] = i;
                break;
            }
        }
    }
}

void print_ordered_item(int i, string item) {
    cout << i + 1 << ". " << item << endl;
} 

len(string array[], string first) {
    return int(sizeof(array) / sizeof(array[0]));
}

int main() {
    int i;

    int state = 0;
    while (!exitCode) {

        switch(state) {
            case 0:
                for(i = 0; i < len(categories, categories[0]); i++) {
                    print_ordered_item(i, categories[i]);
                }
                break;
            case 1:

                //print_cost(bread_list);
                break;
            case 2: 
                //print_cost(pastries);
                break;
            case 3:
                //print_cost(drinks);
                break;
            case 4:
                exitCode = true;
                break;
        }

        if (!exitCode) {
            cout << "Enter action: ";
            cin >> state;
            cout << endl;
        }
    }
    return 0;
}