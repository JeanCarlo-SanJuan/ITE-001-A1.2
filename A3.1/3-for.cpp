#include <iostream>
using namespace std;

int main() {
    int const STEP = 5;
    int const COLUMNS = 8;
    int n = -100;

   cout << "Using for loop...\n";

    for (int i = 0; i < COLUMNS; i++)
    {
        cout << n << "\t";

        if (i == (COLUMNS / 2) - 1) {
            n *=-1;
        } else {
            n += STEP;
        }
    }
    return 0;
}