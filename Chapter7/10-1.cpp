#include <iostream>
using namespace std;

double add(double x, double y);
double sub(double x, double y);
double mul(double x, double y);
double calculate(double x, double y, double(*pt) (double, double));

int main() {
	double a, b;
	cout << "�� �� �Է�(q �Է½� ����) : ";
	while (cin >> a >> b) {
		cout << calculate(a, b, add) << endl;
		cout << calculate(a, b, sub) << endl;
		cout << calculate(a, b, mul) << endl;
		cout << "�� �� �Է�(q �Է½� ����) : ";
	}
	return 0;
}

double add(double x, double y) {
	return x + y;
}
double sub(double x, double y) {
	return x - y;
}
double mul(double x, double y) {
	return x * y;
}
double calculate(double x, double y, double(*pt) (double, double)) {
	return (*pt)(x, y);
}