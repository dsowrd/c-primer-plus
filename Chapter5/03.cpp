#include <iostream>

int main() {
	using namespace std;
	int num, sum = 0;
	cout << "�� �Է�(0�Է½� ����) : ";
	cin >> num;
	while (num != 0) {
		sum += num;
		cout << "�հ� : " << sum << endl;
		cout << "���� �� �Է�(0 �Է½� ����) : ";
		cin >> num;
	}
	return 0;
}