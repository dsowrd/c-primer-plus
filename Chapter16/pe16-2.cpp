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
	cout << "회문 체크(quit으로 종료) : ";
	while (getline(cin, word) && word != "quit") {
		if (palindrome(word))
			cout << word << "는 회문이 맞습니다.\n";
		else
			cout << word << "는 회문이 아닙니다.\n";
		cout << "회문 체크(quit으로 종료) :";
	}
	cout << "프로그램을 종료합니다.\n";
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