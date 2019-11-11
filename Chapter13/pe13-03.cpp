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
		cout << "상표의 이름을 입력하십시오 : ";
		cin >> templab;
		cout << "등급을 입력하려면 1, 색상을 입력하려면 2" << endl;
		cout << "스타일을 입력하려면 3" << endl << " : ";
		while (cin >> kind && (kind != '1' && kind != '2' && kind != '3'))
			cout << "1 2 3 중 하나를 입력하십시오 : ";
		switch (kind) {
		case '1':
			cout << "등급을 입력하십시오 : ";
			cin >> tempnum;
			p_dmas[i] = new baseDMA(templab, tempnum);
			break;
		case '2':
			cout << "색상을 입력하십시오 : ";
			cin >> tempetc;
			p_dmas[i] = new lacksDMA(tempetc, templab);
			break;
		case '3':
			cout << "스타일을 입력하십시오 : ";
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
	cout << "프로그램을 종료합니다.\n";
	return 0;
}