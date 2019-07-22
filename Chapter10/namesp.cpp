#include <iostream>
#include "namesp.h"

SALES::Sales::Sales() {
	int sum, m, n;
	std::cout << "1�б� �Ǹž� : ";
	std::cin >> sales[0];
	sum = m = n = sales[0];
	for (int i = 1; i < QUARTERS; i++) {
		std::cout << i + 1 << "�б� �Ǹž� : ";
		std::cin >> sales[i];
		sum += sales[i];
		if (sales[i] > m)
			m = sales[i];
		if (sales[i] < n)
			n = sales[i];
	}
	average = sum / QUARTERS;
	max = m;
	min = n;
}

SALES::Sales::Sales(double s[], int size) {
	for (int i = 0; i < size; i++)
		sales[i] = s[i];
	if (size < QUARTERS)
		for (int i = size; i < QUARTERS; i++)
			sales[i] = 0;
}

void SALES::Sales::showSales() const {
	for (int i = 0; i < QUARTERS; i++)
		std::cout << i + 1 << "�б� �Ǹž� : " << sales[i] << std::endl;
	std::cout << "��հ� : " << average << std::endl;
	std::cout << "�ִ밪 : " << max << std::endl;
	std::cout << "�ּҰ� : " << min << std::endl;
}