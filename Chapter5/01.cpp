#include <iostream>

int main() {
	using namespace std;
	int iStart, iFinish, iCount = 0;

	cout << "첫 번째 수를 입력: ";
	cin >> iStart;
	cout << "마지막 수를 입력: ";
	cin >> iFinish;

	for (int num = iStart; num <= iFinish; num++)
		iCount += num;

	cout << iStart << "부터 " << iFinish << "까지의 합은 " << iCount << "입니다" << endl;
	return 0;
}