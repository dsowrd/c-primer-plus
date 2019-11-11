#include "cd.h"
#include <cstring>
#include <iostream>
using std::strcpy;

Cd::Cd(const char* s1, const char* s2, int n, double x) {
	strcpy(performers, s1);
	strcpy(label, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd& d) {
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd() {
	strcpy(performers, "noname");
	strcpy(label, "nocover");
	selections = 0;
	playtime = 0.0;
}

Cd::~Cd() {
}

void Cd::Report() const {
	using std::cout;
	using std::endl;
	cout << "�۰ : ";
	cout << performers << endl;

	cout << "Ŀ���� : ";
	cout << label << endl;
	cout << "���� ��� �� : " << selections << endl;
	cout << "���� �ð� : " << playtime << endl;
}

Cd& Cd::operator=(const Cd& d) {
	if (this == &d)
		return *this;
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}