#include "cd1.h"
#include <cstring>
#include <iostream>
using std::strcpy;

Cd::Cd(const char* s1, const char* s2, int n, double x) {
	int len = strlen(s1);
	performers = new char[len + 1];
	strcpy(performers, s1);

	len = strlen(s2);
	label = new char[len + 1];
	strcpy(label, s2);

	selections = n;
	playtime = x;
}

Cd::Cd(const Cd& d) {
	int len = strlen(d.performers);
	performers = new char[len + 1];
	strcpy(performers, d.performers);

	len = strlen(d.label);
	label = new char[len + 1];
	strcpy(label, d.label);

	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd() {
	performers = new char[0];
	label = new char[0];
	selections = 0;
	playtime = 0.0;
}

Cd::~Cd() {
	delete[] performers, label;
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

	delete[] performers;
	int len = strlen(d.performers);
	performers = new char[len + 1];
	strcpy(performers, d.performers);

	delete[] label;
	len = strlen(d.label);
	label = new char[len + 1];
	strcpy(label, d.label);

	selections = d.selections;
	playtime = d.playtime;
	return *this;
}