#include <iostream>

int main() {
	using namespace std;
	struct car {
		char company[20];
		int year;
	};
	int num;
	
	cout << "�� ���� ���� ������� �����Ͻðڽ��ϱ�? ";
	cin >> num;

	car * own = new car[num];

	for (int i = 0; i < num; i++) {
		cout << "�ڵ��� #" << i + 1 << endl;
		cout << "���۾�ü : ";
		cin >> own[i].company;
		cout << "���۳⵵ :";
		cin >> own[i].year;
	}

	cout << "���� ���ϰ� �����ϰ� �ִ� �ڵ��� ����� ������ �����ϴ�." << endl;

	for (int i = 0; i < num; i++) {
		cout << own[i].year << "���� " << own[i].company << endl;
	}
	delete[] own;
	return 0;
}