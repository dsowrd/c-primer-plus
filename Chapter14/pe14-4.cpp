#include <iostream>
#include <cstring>
#include "baddude.h"
const int SIZE = 5;

int main() {
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;

	Person* lolas[SIZE];

	int ct;
	for (ct = 0; ct < SIZE; ct++) {
		cout << "========================================================" << endl;
		char choice;
		cout << "������ �Է��Ͻʽÿ� : \n";
		cout << "g : �ǽ����� p : ��Ŀ�÷��̾� b : ���۳� q : ����\n";
		cin >> choice;
		while (strchr("gpbq", choice) == NULL) {
			cout << "g, p, b, q �߿��� �ϳ��� �����Ͻʽÿ� :";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice) {
		case 'g':
			lolas[ct] = new Gunslinger;
			break;
		case 'p':
			lolas[ct] = new PokerPlayer;
			break;
		case 'b':
			lolas[ct] = new BadDude;
			break;
		}
		cin.get();
		lolas[ct]->Set();
		cout << "----------------------------------------------------" << endl;
	}

	cout << "\n��� ��Ȳ�� ������ �����ϴ� : \n";
	int i;
	for (i = 0; i < ct; i++) {
		cout << endl;
		lolas[i]->Show();
	}
	for (i = 0; i < ct; i++) {
		delete lolas[i];
	}
	cout << "���α׷��� �����մϴ�.\n";
	return 0;
}