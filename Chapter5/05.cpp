#include <iostream>
const int YEAR = 12;
int main() {
	using namespace std;
	char * Months[YEAR] = { "January", "February", "March", "April", "May", "June",
							"July", "August", "September", "October", "November", "December"};
	int sales[YEAR];
	int sum = 0;

	cout << "put sales of the month" << endl;

	for (int i = 0; i < YEAR; i++) {
		cout << Months[i] << "sales = ";
		cin >> sales[i];
	}

	for (int i = 0; i < YEAR; i++)
		sum += sales[i];

	cout << "Total sales of the year = " << sum << endl;
	return 0;
}