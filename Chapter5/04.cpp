#include <iostream>

int main() {
	using namespace std;
	int iAsum = 100000, iBsum = 100000, iCount = 0;

	while (iAsum >= iBsum) {
		iAsum += 10000;
		iBsum = iBsum * 1.05;
		iCount++;
	}

	cout << "�� B�� �������� " << iCount << "�� �� �� A�� �������� �ʰ��ϸ�" << endl;
	cout << "�� �� �������� �� A : " << iAsum << ", �� B : " << iBsum  << "�Դϴ�." << endl;
	return 0;
}