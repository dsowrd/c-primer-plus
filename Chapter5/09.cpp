#include <iostream>
#include <string>

int main() {
	using namespace std;
	string word;
	int count = 0;

	cout << "���� �ܾ���� �Է��Ͻʽÿ�(�������� done�� �Է�) :" << endl;

	while (cin >> word && word != "done")
		count++;
	cout << "�� " << count << " �ܾ �ԷµǾ����ϴ�." << endl;
	return 0;
}