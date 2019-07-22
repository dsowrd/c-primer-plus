#include <iostream>
#include <cctype>
#include "stack.h"

int main() {
	using namespace std;
	Stack st;
	char ch;
	double income = 0;
	Item ctm;
	cout << "���� �߰��Ϸ��� A, ���� ó���Ϸ��� P, \n"
		<< "�����Ϸ��� Q�� �Է��Ͻʽÿ�.\n";
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
			
			if (st.isfull())
				cout << "������ ���� �� �ֽ��ϴ�.\n";
			else {
				cout << "�߰��� ���� �̸��� �Է��Ͻʽÿ� : ";
				cin >> ctm.fullname;
				cout << "�߰��� ���� ������ �ݾ��� �Է��Ͻʽÿ� : ";
				cin >> ctm.payment;
				st.push(ctm);
			}
			break;
		case 'P':
		case 'p':
			if (st.isempty())
				cout << "������ ��� �ֽ��ϴ�.\n";
			else {
				st.pop(ctm);
				income += ctm.payment;
				cout << ctm.fullname << "���� ó���Ͽ����ϴ�." << endl;
				cout << ctm.payment << "���� �����Ͽ� �� ������ " << income << "�� �Դϴ�." << endl;
			}
			break;
		}
		cout << "\n���� �߰��Ϸ��� A, ���� ó���Ϸ��� P, \n"
			<< "�����Ϸ��� Q�� �Է��Ͻʽÿ�.\n";
	}
	cout << "���α׷��� �����մϴ�.\n";
	return 0;
}