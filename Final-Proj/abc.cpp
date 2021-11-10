#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
    //Prototypes
    void randomize_stocks(void);

//Global vars
time_t current_time;
const int CAT = 2;

string product_names[CAT][3] = {
    {"Bread", // First element in column contains category
        // Items
        "Pandesal",
        "Wheat Loaf Bread",
    },
    {"Pastries",
        "Chocolate Cookies"
        "Mocha Cake",
    }
};

// product_data[i][j][k]
// determines...
// i - category
// j - product
// k - price, stock, slices, quantity in cart
float product_data[CAT][2][4] = {
    { // Bread
        //{price per slice, stock in slices, slices per whole (1 means 1 whole ), quantity in cart by slices}
        {5, 50, 1, 0}, // Pandesal
        {11, 45, 10, 0} // Wheat Loaf
    }, 
    { // Pastries
        {18, 33, 1, 0}, // Choco cookies
        {30, 60, 6, 0} // Mocha cake
    }
};

int main() {
    time(&current_time);
    randomize_stocks();
    return 0;
}

void randomize_stocks() {
    int i, j;
    float *stocks;
    for (i = 0; i < CAT; i++) {
        for (j = 0; j < 2; j++) {
            stocks = &product_data[i][j][1];
            *stocks += current_time % 100;
            *stocks = (int(pow(*stocks, 2)) % 100) + (current_time % int(product_data[i][j][2])) + 5;

            cout << product_data[i][j][1] << endl;
        }
    }
}