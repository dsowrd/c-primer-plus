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
	cout << "����� �̸� �Է� : ";
	cin >> name;
	cout << "�ڵ�ĸ �Է�: ";
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
	cout << "\n�̸�: " << g.fullname << std::endl;
	cout << "�ڵ�ĸ: " << g.handicap << std::endl;
}