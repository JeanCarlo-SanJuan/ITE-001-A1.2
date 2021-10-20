#include <iostream>

using namespace std;

const float MERCH_DISCOUNT = 0.85;
const float DESIRED_PROFIT = 1.10;

int main() {
  int merchandise, salary, rent, electricity;

  cout << "Enter the cost of your merchandise: ";
  cin >> merchandise;

  cout << "Enter the salary of employess: ";
  cin >> salary;

  cout << "Enter the yearly rent: ";
  cin >> rent;

  cout << "Enter the electricity cost: ";
  cin >> electricity;

  float noMerchandise = salary + rent + electricity;
  float rawExpenses = merchandise +  noMerchandise;
  float desiredProfit = rawExpenses * DESIRED_PROFIT;
  float desiredMarkup = (desiredProfit - noMerchandise)
                      / (merchandise   * MERCH_DISCOUNT);

  cout << endl;
  cout << "Raw Expenses: " << rawExpenses << endl;
  cout << "Desired Profit: " << desiredProfit << endl;

  cout << endl;
  cout << "The merchandise should be marked up by " << (desiredMarkup * 100) - 100 << "%" << endl;
  cout << "before applying the 15% discount to merchandise." << endl;

  float markedUpMerch = merchandise * desiredMarkup;
  float withDiscount = markedUpMerch * 0.85;
  float totalVerify = noMerchandise + withDiscount;

  cout << endl;
  cout << "Marked up merchandise:     " << markedUpMerch << endl;
  cout << "After applying discount:   " << withDiscount << endl;
  cout << "All other expenses:        " << noMerchandise << endl;
  cout << "------------------------------------------------" << endl;
  cout << "Final:                     " << totalVerify << " = " << desiredProfit << endl;

  return 0;
}

//merch_cost, rent, salary, electricity
// total = merch_cost + rent + salary + electricity
// markedup_total = total * 1.1
// discounted_total = markedup_total * 0.85
