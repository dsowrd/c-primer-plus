#include <iostream>

int main() {
	using namespace std;
	int iAsum = 100000, iBsum = 100000, iCount = 0;

	while (iAsum >= iBsum) {
		iAsum += 10000;
		iBsum = iBsum * 1.05;
		iCount++;
	}

	cout << "고객 B의 원리금은 " << iCount << "년 후 고객 A의 원리금을 초과하며" << endl;
	cout << "이 때 원리금은 고객 A : " << iAsum << ", 고객 B : " << iBsum  << "입니다." << endl;
	return 0;
}