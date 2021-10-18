#include <iostream>
#include <iomanip>
using namespace std;

// Contributed by Cyrill Eustaquio
int main()
{
	double totalCost;
	double salary;
	double rent;
	double electric;	

    cout << fixed << setprecision(2);
	cout << "\nEnter total cost of merchandise: ";
	cin >> totalCost;
	cout << "Enter total salary: ";
	cin >> salary;
	cout << "Enter yearly rent: ";
	cin >> rent;
	cout << "Enter estimated electric cost: ";
	cin >> electric;

	double expense = (totalCost + salary + rent + electric);
    double profit = totalCost * (0.1);
    double earning = (expense + profit) / (0.85);
    double markup = earning - totalCost;
    double percent = (markup / totalCost) * 100;
    cout << "\nMerchandise should have the markup of " << percent << "%\n\n";
	return 0;
}