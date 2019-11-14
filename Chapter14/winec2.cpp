#include "winec2.h"
#include <iostream>

template<class T1, class T2>
T1& Pair<T1, T2>::first() {
	return a;
}

template<class T1, class T2>
T2& Pair<T1, T2>::second() {
	return b;
}

Wine::Wine(const char* l, int y, const int yr[], const int bot[])
	: std::string(l), num_harv(y), PairArray(ArrayInt(yr, y), ArrayInt(bot, y)) {
}

Wine::Wine(const char* l, int y)
	: std::string(l), num_harv(y), PairArray(ArrayInt(0, y), ArrayInt(0, y)) {
}

void Wine::GetBottles() {
	using std::cout;
	using std::cin;
	cout << num_harv << "�Ⱓ�� " << Label() << " �����͸� �Է��Ͻʽÿ� :\n";
	for (int i = 0; i < num_harv; i++) {
		cout << "�⵵�� �Է��Ͻʽÿ� : ";
		cin >> PairArray::first()[i];
		cout << "������ �Է��Ͻʽÿ� : ";
		cin >> PairArray::second()[i];
	}
}

int Wine::sum() {
	int temp = 0;
	for (int i = 0; i < num_harv; i++) {
		temp += PairArray::second()[i];
	}
	return temp;
}

void Wine::Show() const {
	using std::cout;
	using std::endl;

	cout << "���� : " << (std::string)(*this) << endl;
	cout << "\t�⵵\t����\n";
	for (int i = 0; i < num_harv; i++) {
		cout << "\t" << PairArray::first()[i] << "\t" << PairArray::second()[i] << endl;
	}
}