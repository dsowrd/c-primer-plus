#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void capital(string & str);
void show(const string str);

int main() {
	string str;
	cout << "���ڿ��� �Է��Ͻÿ�(�������� q): ";

	while (getline(cin, str) && str != "q") {
		capital(str);
		show(str);
		cout << "���� ���ڿ��� �Է��Ͻÿ�(�������� q): ";
	}
	cout << "��" << endl;
	return 0;
}

void capital(string & str) {
	for (int i = 0; str[i] ; i++)
		str[i] = toupper(str[i]);
}
void show(const string str) {
	cout << str << endl;
}