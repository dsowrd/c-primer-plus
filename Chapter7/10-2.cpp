#include <iostream>
using namespace std;

double add(double x, double y);
double sub(double x, double y);
double mul(double x, double y);
double calculate(double x, double y, double (*pt) (double, double));

int main() {
	double a, b;
	double (*funp[3])(double, double) = { add, sub, mul };

	cout << "�� �� �Է�(q�Է½� ����) : ";
	while (cin >> a >> b) {
		for (int i = 0; i < 3; i++)
			cout << calculate(a, b, *funp[i]) << endl;
		cout << "�� �� �Է�(q�Է½� ����) : ";
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
double calculate(double x, double y, double (*pt) (double, double)) {
	return (*pt)(x, y);
}