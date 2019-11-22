#include <iostream>
#include <iterator>
#include <cctype>
#include <string>

bool palindrome(std::string& str);

int main() {
	using std::string;
	using std::cin;
	using std::cout;

	string word;
	cout << "ȸ�� üũ(quit���� ����) : ";
	while (getline(cin, word) && word != "quit") {
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
	std::string temp;
	std::string::reverse_iterator ri;
	for (ri = str.rbegin(); ri != str.rend(); ri++) {
		if (!isalpha(*ri))
			continue;
		temp += tolower(*ri);
	}
	std::string rtemp(temp.rbegin(), temp.rend());
	return temp == rtemp;
}