#include <iostream>

int main() {
	using namespace std;
	int income, tax;

	cout << "income :";

	while (cin >> income && income >= 0) {
		if (income <= 5000)
			tax = 0;
		else if (income <= 15000)
			tax = (income - 5000) * 0.1;
		else if (income <= 35000)
			tax = 10000 * 0.10 + (income - 15000) * 0.15;
		else
			tax = 10000 * 0.10 + 20000 * 0.15 + (income - 35000)*0.20;
		cout << "tax : " << tax << endl;
	}
	return 0;
}