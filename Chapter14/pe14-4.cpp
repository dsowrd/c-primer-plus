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
		cout << "직종을 입력하십시오 : \n";
		cout << "g : 건슬링어 p : 포커플레이어 b : 나쁜놈 q : 종료\n";
		cin >> choice;
		while (strchr("gpbq", choice) == NULL) {
			cout << "g, p, b, q 중에서 하나를 선택하십시오 :";
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

	cout << "\n사원 현황은 다음과 같습니다 : \n";
	int i;
	for (i = 0; i < ct; i++) {
		cout << endl;
		lolas[i]->Show();
	}
	for (i = 0; i < ct; i++) {
		delete lolas[i];
	}
	cout << "프로그램을 종료합니다.\n";
	return 0;
}