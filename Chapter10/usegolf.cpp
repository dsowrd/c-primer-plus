#include <iostream>
#include "golf.h"
const int Len = 40;
const int MAX = 5;

int main() {
	Golf * gf = new Golf[MAX];
	char name[Len];
	int hc;
	for (int i = 0; i < MAX; i++)
		gf[i].showgolf();

	for (int i = 0; i < MAX; i++) {
		std::cout << "#" << i + 1 << "adjust handicap : ";
		std::cin >> hc;
		gf[i].changehc(hc);
	}
	for (int i = 0; i < MAX; i++)
		gf[i].showgolf();
	delete[] gf;
	return 0;
}