#include <iostream>
#include "sales.h"

namespace SALES
{
	void setSales(Sales & s, const double ar[], int n) {
		int num = 4;
		double sum, avg, max, min;
		if (n < num)
			num = n;
		for (int i = 0; i < num; i++)
			s.sales[i] = ar[i];
		sum = max = min = s.sales[0];
		for (int i = 1; i < num; i++) {
			sum += s.sales[i];
			if (s.sales[i] > max)
				max = s.sales[i];
			if (s.sales[i] < min)
				min = s.sales[i];
		}
		for (int i = num; i <= 4; i++)
			s.sales[i] = 0;
		avg = sum / num;
		s.average = avg;
		s.max = max;
		s.min = min;
	}

	void setSales(Sales & s) {
		using std::cout;
		using std::cin;
		using std::endl;
		double sum, avg, max, min;
		for (int i = 0; i < QUARTERS; i++) {
			cout << i + 1 << "분기 판매액: ";
			cin >> s.sales[i];
		}
		sum = max = min = s.sales[0];
		for (int i = 1; i < QUARTERS; i++) {
			sum += s.sales[i];
			if (s.sales[i] > max)
				max = s.sales[i];
			if (s.sales[i] < min)
				min = s.sales[i];
		}
		avg = sum / QUARTERS;
		s.average = avg;
		s.max = max;
		s.min = min;
	}

	void showSales(const Sales & s) {
		using std::cout;
		using std::endl;
		for (int i = 0; i < QUARTERS; i++)
			cout << i + 1 << "분기 판매액: " << s.sales[i] << endl;
		cout << "평균: " << s.average << endl;
		cout << "최대값: " << s.max << endl;
		cout << "최소값: " << s.min << endl;
	}
}