#include "winec.h"
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
: label(l), num_harv(y), pa(ArrayInt(yr,y), ArrayInt(bot,y)) {
}

Wine::Wine(const char* l, int y) : label(l), num_harv(y), pa(ArrayInt(0, y), ArrayInt(0, y)) {
}

void Wine::GetBottles() {
	using std::cout;
	using std::cin;
	cout << num_harv << "년간의 " << label << " 데이터를 입력하십시오 :\n";
	for (int i = 0; i < num_harv; i++) {
		cout << "년도를 입력하십시오 : ";
		cin >> pa.first()[i];
		cout << "수량을 입력하십시오 : ";
		cin >> pa.second()[i];
	}
}

int Wine::sum() {
	int temp = 0;
	for (int i = 0; i < num_harv; i++) {
		temp += pa.second()[i];
	}
	return temp;
}

void Wine::Show() {
	using std::cout;
	using std::endl;

	cout << "와인 : " << label << endl;
	cout << "\t년도\t수량\n";
	for (int i = 0; i < num_harv; i++) {
		cout << "\t" << pa.first()[i] << "\t" << pa.second()[i] << endl;
	}
}