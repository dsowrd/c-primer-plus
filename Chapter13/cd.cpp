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
	cout << "작곡가 : ";
	cout << performers << endl;

	cout << "커버명 : ";
	cout << label << endl;
	cout << "수록 곡목 수 : " << selections << endl;
	cout << "연주 시간 : " << playtime << endl;
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