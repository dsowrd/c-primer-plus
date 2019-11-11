#include "classic1.h"
#include <cstring>
#include <iostream>
using std::strcpy;

Classic::Classic(const char* s1, const char* s2, const char* s3, int n, double x) : Cd(s1, s2, n, x) {
	int len = strlen(s3);
	favorite = new char[len + 1];
	strcpy(favorite, s3);
}

Classic::Classic(const Classic& d) : Cd(d) {
	int len = strlen(d.favorite);
	favorite = new char[len + 1];
	strcpy(favorite, d.favorite);
}

Classic::Classic() : Cd() {
	favorite = new char[0];
}

Classic::~Classic() {
	delete[] favorite;
}

void Classic::Report() const {
	using std::cout;
	using std::endl;

	Cd::Report();

	cout << "´ëÇ¥°î : ";
	cout << favorite << endl;
}

Classic& Classic::operator=(const Classic& d) {
	if (this == &d)
		return *this;
	Cd::operator=(d);
	delete[] favorite;
	int len = strlen(d.favorite);
	favorite = new char[len + 1];
	strcpy(favorite, d.favorite);
	return *this;
}