#include <iostream>

int main() {
	using namespace std;
	int iStart, iFinish, iCount = 0;

	cout << "ù ��° ���� �Է�: ";
	cin >> iStart;
	cout << "������ ���� �Է�: ";
	cin >> iFinish;

	for (int num = iStart; num <= iFinish; num++)
		iCount += num;

	cout << iStart << "���� " << iFinish << "������ ���� " << iCount << "�Դϴ�" << endl;
	return 0;
}