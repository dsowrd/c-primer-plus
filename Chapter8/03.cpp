#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void capital(string & str);
void show(const string str);

int main() {
	string str;
	cout << "문자열을 입력하시오(끝내려면 q): ";

	while (getline(cin, str) && str != "q") {
		capital(str);
		show(str);
		cout << "다음 문자열을 입력하시오(끝내려면 q): ";
	}
	cout << "끝" << endl;
	return 0;
}

void capital(string & str) {
	for (int i = 0; str[i] ; i++)
		str[i] = toupper(str[i]);
}
void show(const string str) {
	cout << str << endl;
}