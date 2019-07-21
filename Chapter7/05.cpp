#include <iostream>

int factorial(int n);

int main() {
	using namespace std;
	int num;
	cout << "put number to calculate factorial : ";
	cin >> num;
	cout << num << "! = " << factorial(num) << endl;
	return 0;
}

int factorial(int n) {
	if (n == 0)
		return 1;
	else return n * factorial(n - 1);
}