#include <iostream>
#include <cstring>

int main() {
	using namespace std;
	char word[20];
	int count = 0;

	cout << "���� �ܾ���� �Է��Ͻʽÿ�(�������� done�� �Է�) :" << endl;

	do {
		count++;
		cin >> word;
	} while (strcmp(word, "done") != 0);
	count--;

	cout << "�� " << count << " �ܾ �ԷµǾ����ϴ�." << endl;
	return 0;
}