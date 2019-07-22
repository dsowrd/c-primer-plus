#include <iostream>
#include <cstring>
#include "golf.h"

Golf::Golf() {
	char name[Len];
	int hc;
	std::cout << "name : ";
	std::cin >> name;
	std::cout << "handicap : ";
	std::cin >> hc;
	std::cout << std::endl;;
	Golf g = Golf(name, hc);
	*this = g;
}

Golf::Golf(const char * name, int hc) {
	strcpy(fullname, name);
	handicap = hc;
}

void Golf::changehc(int hc) {
	handicap = hc;
}

void Golf::showgolf() const {
	std::cout << "ÀÌ¸§ : ";
	for (int i = 0; i < Len; i++) {
		if (fullname[i] == NULL)
			break;
		else
			std::cout << fullname[i];
	}
	std::cout << "\nÇÚµðÄ¸ : " << handicap << std::endl;
}