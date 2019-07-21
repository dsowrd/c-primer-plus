#include <iostream>
const int YEAR = 12;
int main() {
	using namespace std;
	char * Months[YEAR] = { "January", "February", "March", "April", "May", "June",
							"July", "August", "September", "October", "November", "December" };
	int sales[3][YEAR];
	int year_sum = 0, total_sum = 0;

	for (int i = 0; i < 3; i++) {
		cout << "put sales of the month" << endl;
		for (int j = 0; j < YEAR; j++) {
			cout << Months[j] << " sales = ";
			cin >> sales[i][j];
			year_sum += sales[i][j];
			total_sum += sales[i][j];
		}
		cout << "Year sales = " << year_sum << endl;
		cout << "Total sales = " << total_sum << endl;
		year_sum = 0;
	}
	return 0;
}