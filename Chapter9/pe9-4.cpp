#include <iostream>
#include "sales.h"
const int ArSize = 3;
const int N = 2;

int main() {
	SALES::Sales ss[N];
	double arr[ArSize] = { 1.1, 2.2, 3.3 };

	SALES::setSales(ss[0]);
	SALES::setSales(ss[1], arr, ArSize);

	for (int i = 0; i < N; i++)
		SALES::showSales(ss[i]);
}