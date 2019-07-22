#include <iostream>
#include <string>
#include <cstring>
#include "person.h"
using std::string;

Person::Person(const string & ln, const char * fn) {
	lname = ln;
	strcpy(fname, fn);
}

void Person::Show() const {
	for (int i = 0; i < LIMIT; i++) {
		if (fname[i] == '\0')
			break;
		else
			std::cout << fname[i];
	}
	std::cout << ", " << lname;
}

void Person::FormalShow() const{
	std::cout << lname << ", ";
	for (int i = 0; i < LIMIT; i++) {
		if (fname[i] == '\0')
			break;
		else
			std::cout << fname[i];
	}
}