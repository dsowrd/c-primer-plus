#include <iostream>
#include "golf.h"

void setgolf(golf & g, const char * name, int hc) {
	strcpy(g.fullname, name);
	g.handicap = hc;
}

int setgolf(golf & g) {
	using std::cout;
	using std::cin;
	char name[Len];
	int hc;
	cout << "사용자 이름 입력 : ";
	cin >> name;
	cout << "핸디캡 입력: ";
	cin >> hc;
	setgolf(g, name, hc);
	if (name == NULL)
		return false;
	else
		return true;
}

void handicap(golf & g, int hc) {
	g.handicap = hc;
}

void showgolf(const golf & g) {
	using std::cout;
	cout << "\n이름: " << g.fullname << std::endl;
	cout << "핸디캡: " << g.handicap << std::endl;
}