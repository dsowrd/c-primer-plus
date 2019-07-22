#include "plorg.h"

int main() {
	Plorg p1;
	Plorg p2("apple");
	Plorg p3("banana");
	p1.showplg();
	p2.showplg();
	p3.showplg();
	p1.changeci(70);
	p1.showplg();
	return 0;
}