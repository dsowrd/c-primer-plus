#include <iostream>
#include <string>
using namespace std;

void strcount(string str);

int main() {
	string input;
	char next;

	cout << "�������� �� ���� �Է��Ͻʽÿ�:\n";
	getline(cin, input);
	while (input != "") {
		strcount(input);
		cout << "���� ���� �Է��Ͻʽÿ�(�������� �� ���� �Է�) : \n";
		getline(cin, input);
	}
	cout << "���α׷��� �����մϴ�.\n";
	return 0;
}

void strcount(string str) {
	static int total = 0;
	int count = 0;

	cout << "\"" << str << "\"���� ";
	for (int i = 0; str[i] != NULL; i++)
		count++;
	total += count;
	cout << count << "���� ���ڰ� �ֽ��ϴ�.\n";
	cout << "���ݱ��� �� " << total << "���� ���ڸ� �Է��ϼ̽��ϴ�.\n";
}