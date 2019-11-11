#include <iostream>
#include "dmaabc.h"
#include <string>
const int DMAS = 4;
const int ARRMAX = 50;

int main() {
	using std::cin;
	using std::cout;
	using std::endl;
	using std::string;
	
	dmaABC* p_dmas[DMAS];
	string templab;
	string tempetc;
	long tempnum;
	char kind;

	for (int i = 0; i < DMAS; i++) {
		cout << "��ǥ�� �̸��� �Է��Ͻʽÿ� : ";
		cin >> templab;
		cout << "����� �Է��Ϸ��� 1, ������ �Է��Ϸ��� 2" << endl;
		cout << "��Ÿ���� �Է��Ϸ��� 3" << endl << " : ";
		while (cin >> kind && (kind != '1' && kind != '2' && kind != '3'))
			cout << "1 2 3 �� �ϳ��� �Է��Ͻʽÿ� : ";
		switch (kind) {
		case '1':
			cout << "����� �Է��Ͻʽÿ� : ";
			cin >> tempnum;
			p_dmas[i] = new baseDMA(templab, tempnum);
			break;
		case '2':
			cout << "������ �Է��Ͻʽÿ� : ";
			cin >> tempetc;
			p_dmas[i] = new lacksDMA(tempetc, templab);
			break;
		case '3':
			cout << "��Ÿ���� �Է��Ͻʽÿ� : ";
			cin >> tempetc;
			p_dmas[i] = new hasDMA(tempetc, templab);
			break;
		}
		while (cin.get() != '\n')
			continue;
	}
	cout << endl;

	for (int i = 0; i < DMAS; i++) {
		p_dmas[i]->view();
		cout << endl;
	}

	for (int i = 0; i < DMAS; i++) {
		delete p_dmas[i];
	}
	cout << "���α׷��� �����մϴ�.\n";
	return 0;
}