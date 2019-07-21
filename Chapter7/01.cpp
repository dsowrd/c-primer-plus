#include <iostream>

double calculate(int x, int y);

int main() {
	using namespace std;
	double a, b, result;

	cin >> a;
	cin >> b;

	while (a != 0 && b != 0) {
		result = calculate(a, b);
		cout << result << endl;
		cin >> a;
		cin >> b;
	}
	return 0;
}

double calculate(int x, int y) {
	return 2.0 * x * y / (x + y);
}