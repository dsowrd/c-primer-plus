#include <iostream>
#include "complex0.h"
using namespace std;

int main() {
	Complex a(3.0, 4.0);
	Complex c;
	cout << "하나의 복소수를 입력하십시오(끝내려면 q): \n";
	while (cin >> c) {
		cout << "c = " << c << endl;
		cout << "공액복소수 = " << ~c << endl;
		cout << "a = " << a << endl;
		cout << "a + c = " << a + c << endl;
		cout << "a - c = " << a - c << endl;
		cout << "a * c = " << a * c << endl;
		cout << "2 * c = " << 2 * c << endl;
		cout << "하나의 복소수를 입력하십시오(끝내려면q):\n";
	}
	cout << "\n프로그램을 종료합니다.\n";
	return 0;
}