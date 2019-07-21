#include <iostream>

int main() {
	using namespace std;
	int num, sum = 0;
	cout << "수 입력(0입력시 종료) : ";
	cin >> num;
	while (num != 0) {
		sum += num;
		cout << "합계 : " << sum << endl;
		cout << "더할 수 입력(0 입력시 종료) : ";
		cin >> num;
	}
	return 0;
}