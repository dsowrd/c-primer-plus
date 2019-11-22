#include <iostream>
#include <string>

bool palindrome(std::string& str);

int main() {
	using std::string;
	using std::cin;
	using std::cout;

	string word;
	cout << "ȸ�� üũ(quit���� ����) : ";
	while (cin >> word && word != "quit") {
		if (palindrome(word))
			cout << word << "�� ȸ���� �½��ϴ�.\n";
		else
			cout << word << "�� ȸ���� �ƴմϴ�.\n";
		cout << "ȸ�� üũ(quit���� ����) :";
	}
	cout << "���α׷��� �����մϴ�.\n";
	return 0;
}

bool palindrome(std::string& str) {
	std::string temp(str.rbegin(), str.rend());
	return str == temp;
}