#include <iostream>
#include "namesp.h"

SALES::Sales::Sales() {
	int sum, m, n;
	std::cout << "1분기 판매액 : ";
	std::cin >> sales[0];
	sum = m = n = sales[0];
	for (int i = 1; i < QUARTERS; i++) {
		std::cout << i + 1 << "분기 판매액 : ";
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
		std::cout << i + 1 << "분기 판매액 : " << sales[i] << std::endl;
	std::cout << "평균값 : " << average << std::endl;
	std::cout << "최대값 : " << max << std::endl;
	std::cout << "최소값 : " << min << std::endl;
}