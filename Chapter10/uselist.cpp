#include <iostream>
#include "list.h"

void add5(Item &it) {
	it += 5;
}

void mul2(Item & it) {
	it *= 2;
}

int main() {
	using namespace std;
	Item item;
	List list;
	char ch;
	cout << "고객을 추가하려면 A, 종료하려면 Q를 입력하십시오.\n";
	while (cin >> ch && toupper(ch) != 'Q') {
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch)) {
			cout << '\a';
			continue;
		}
		if (toupper(ch) == 'A') {
			
			if (list.isfull())
				cout << "스택이 가득 차 있습니다.\n";
			else {
				cout << "추가할 데이터를 입력하십시오 : ";
				cin >> item;
				list.addlist(item);
			}
		}
		cout << "\n고객을 추가하려면 A, 종료하려면 Q를 입력하십시오.\n";
	}
	cout << "\n전체 데이터 조작 : \nA. 5 더하기 \nM. 2 곱하기\nS. 데이터 출력\nQ. 종료" << endl;
	while (cin >> ch && toupper(ch) != 'Q') {
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch)) {
			cout << '\a';
			continue;
		}
		switch (ch) {
		case 'A':
		case 'a':
			list.visit(add5);
			break;
		case 'M':
		case 'm':
			list.visit(mul2);
			break;
		case 'S':
		case 's':
			list.showlist();
			break;
		}
		cout << "\n전체 데이터 조작 : \nA. 5 더하기 \nM. 2 곱하기\nS. 데이터 출력\nQ. 종료" << endl;
	}
	cout << "\n프로그램을 종료합니다." << endl;
	return 0;
}

