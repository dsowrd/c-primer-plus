#include <iostream>
#include "cpmv.h"

int main() {
	Cpmv one("q1", "z1");
	std::cout << "one -> " << std::endl;
	one.Display();
	Cpmv two("q2", "z2");
	std::cout << "two -> " << std::endl;
	two.Display();
	std::cout << "--------------------------------------" << std::endl;
	Cpmv three(Cpmv("q3", "z3"));
	std::cout << "three -> " << std::endl;
	three.Display();
	std::cout << "--------------------------------------" << std::endl;
	Cpmv four;
	four = one + two + three;
	std::cout << "four -> " << std::endl;
	four.Display();
	return 0;
}