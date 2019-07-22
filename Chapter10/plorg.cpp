#include <iostream>
#include <cstring>
#include "plorg.h"

Plorg::Plorg() {
	strcpy(name, "Plorga");
	ci = 50;
}

Plorg::Plorg(char * nm) {
	strcpy(name, nm);
	ci = 50;
}

void Plorg::changeci(int c) {
	ci = c;
}

void Plorg::showplg() const {
	std::cout << "ÀÌ¸§ : ";
	for (int i = 0; i < SIZE; i++) {
		if (name[i] == NULL)
			break;
		else
			std::cout << name[i];
	}
	std::cout << "\nCI : " << ci << std::endl;
}