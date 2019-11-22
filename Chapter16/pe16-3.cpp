#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

int main() {
	using std::cout;
	using std::cin;
	using std::tolower;
	using std::endl;
	using std::string;

	std::ifstream fin;
	fin.open("wordlist.txt");
	std::vector<string> words;
	string temp;
	while (fin >> temp) {
		words.push_back(temp);
	}
	int num = words.size();
	std::srand((unsigned int)time(0));
	char play;
	cout << "영어 단어 게임을 하시겠습니까? <y/n>";
	cin >> play;
	play = tolower(play);
	while (play == 'y') {
		string target = words[std::rand() % num];
		int length = target.length();
		string attempt(length, '-');
		string badchars;
		int guesses = 6;
		cout << "수수께끼 단어를 추측해 보십시오.\n";
		cout << length << "개의 문자로 이루어져 있습니다.\n";
		cout << "한 번에 한 문자씩 추측하십시오.\n";
		cout << "틀릴 수 있는 기회 : " << guesses << "번\n";
		cout << "추측하는 단어 : " << attempt << endl;
		while (guesses > 0 && attempt != target) {
			char letter;
			cout << "문자를 추측하십시오 : ";
			cin >> letter;
			if (badchars.find(letter) != string::npos || attempt.find(letter) != string::npos) {
				cout << "이미 추측한 문자입니다. 다시 하십시오.\n";
				continue;
			}
			int loc = target.find(letter);
			if (loc == string::npos) {
				cout << "땡! 틀렸습니다.\n";
				--guesses;
				cout << "틀릴 수 있는 기회 : " << guesses << "번\n";
				badchars += letter;
			}
			else {
				cout << "딩동댕! 맞았습니다.\n";
				attempt[loc] = letter;
				loc = target.find(letter, loc + 1);
				while (loc != string::npos) {
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}
			cout << "추측하는 단어 : " << attempt << endl;
			if (attempt != target) {
				if (badchars.length() > 0)
					cout << "틀리게 추측한 문자들 : " << badchars << endl;
			}
		}
		if (guesses > 0)
			cout << "그렇습니다. 그것이 수수께끼 단어입니다.\n";
		else
			cout << "안타깝습니다. 수수께끼 단어는 " << target << "입니다.\n";
		cout << "게임을 다시 하시겠습니까? <y/n>";
		cin >> play;
		play = tolower(play);
	}
	cout << "프로그램을 종료합니다.\n";
	return 0;
}