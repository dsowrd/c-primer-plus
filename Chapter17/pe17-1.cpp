#include <iostream>

int main() {
	int ct = 0;
	while (std::cin.get() != '$')
		ct++;
	std::cout << "Ä«¿îÆ® : " << ct << std::endl;
	return 0;
}