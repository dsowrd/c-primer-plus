#include "classic.h"
#include <cstring>
#include <iostream>
using std::strcpy;

Classic::Classic(const char* s1, const char* s2, const char* s3, int n, double x) : Cd(s1, s2, n, x) {
	strcpy(favorite, s3);
}

Classic::Classic() : Cd() {
	strcpy(favorite, "nomusic");
}

void Classic::Report() const {
	using std::cout;
	using std::endl;

	Cd::Report();

	cout << "´ëÇ¥°î : ";
	cout << favorite << endl;
}