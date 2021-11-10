#include <iostream>
using namespace std;

int main() {
	int cases;
	cin >> cases;
	string txt;
	for (int i = 0; i < cases; i++) {
		cin >> txt;

		for (int j = txt.size();j > -1; j--) {
			cout << txt[j];
		}

		cout << endl;
	}

	return 0;
}