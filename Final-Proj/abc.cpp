#include <iostream>

using namespace std;

string product_names[2][3] = {
    {"Bread", // First element in column contains category
        // Items
        "Pandesal", // Size only one - pieces
        "Wheat Loaf Bread", // Size  - slice or one whole
    },
    {"Pastries",
        "Chocolate Cookies"
        "Mocha Cake",
    }
};

// product_prices[i][j][k]
// determines...
// i - category
// j - product
// k - price, stock, slices
float product_prices[2][2][3] = {
    { // Bread
        //{price per slice, stock in slices, slices per whole (1 means 1 whole )}
        {5, 50, 1}, // Pandesal
        {11, 45, 10} // Wheat Loaf
    }, 
    { // Pastries
        {18, 33, 1}, // Choco cookies
        {30, 60, 6} // Mocha cake
    }
};

int main() {
    return 0;
}