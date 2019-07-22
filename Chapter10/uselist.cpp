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
	cout << "���� �߰��Ϸ��� A, �����Ϸ��� Q�� �Է��Ͻʽÿ�.\n";
	while (cin >> ch && toupper(ch) != 'Q') {
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch)) {
			cout << '\a';
			continue;
		}
		if (toupper(ch) == 'A') {
			
			if (list.isfull())
				cout << "������ ���� �� �ֽ��ϴ�.\n";
			else {
				cout << "�߰��� �����͸� �Է��Ͻʽÿ� : ";
				cin >> item;
				list.addlist(item);
			}
		}
		cout << "\n���� �߰��Ϸ��� A, �����Ϸ��� Q�� �Է��Ͻʽÿ�.\n";
	}
	cout << "\n��ü ������ ���� : \nA. 5 ���ϱ� \nM. 2 ���ϱ�\nS. ������ ���\nQ. ����" << endl;
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
		cout << "\n��ü ������ ���� : \nA. 5 ���ϱ� \nM. 2 ���ϱ�\nS. ������ ���\nQ. ����" << endl;
	}
	cout << "\n���α׷��� �����մϴ�." << endl;
	return 0;
}

