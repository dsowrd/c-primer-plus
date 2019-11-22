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
	cout << "���� �ܾ� ������ �Ͻðڽ��ϱ�? <y/n>";
	cin >> play;
	play = tolower(play);
	while (play == 'y') {
		string target = words[std::rand() % num];
		int length = target.length();
		string attempt(length, '-');
		string badchars;
		int guesses = 6;
		cout << "�������� �ܾ ������ ���ʽÿ�.\n";
		cout << length << "���� ���ڷ� �̷���� �ֽ��ϴ�.\n";
		cout << "�� ���� �� ���ھ� �����Ͻʽÿ�.\n";
		cout << "Ʋ�� �� �ִ� ��ȸ : " << guesses << "��\n";
		cout << "�����ϴ� �ܾ� : " << attempt << endl;
		while (guesses > 0 && attempt != target) {
			char letter;
			cout << "���ڸ� �����Ͻʽÿ� : ";
			cin >> letter;
			if (badchars.find(letter) != string::npos || attempt.find(letter) != string::npos) {
				cout << "�̹� ������ �����Դϴ�. �ٽ� �Ͻʽÿ�.\n";
				continue;
			}
			int loc = target.find(letter);
			if (loc == string::npos) {
				cout << "��! Ʋ�Ƚ��ϴ�.\n";
				--guesses;
				cout << "Ʋ�� �� �ִ� ��ȸ : " << guesses << "��\n";
				badchars += letter;
			}
			else {
				cout << "������! �¾ҽ��ϴ�.\n";
				attempt[loc] = letter;
				loc = target.find(letter, loc + 1);
				while (loc != string::npos) {
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}
			cout << "�����ϴ� �ܾ� : " << attempt << endl;
			if (attempt != target) {
				if (badchars.length() > 0)
					cout << "Ʋ���� ������ ���ڵ� : " << badchars << endl;
			}
		}
		if (guesses > 0)
			cout << "�׷����ϴ�. �װ��� �������� �ܾ��Դϴ�.\n";
		else
			cout << "��Ÿ�����ϴ�. �������� �ܾ�� " << target << "�Դϴ�.\n";
		cout << "������ �ٽ� �Ͻðڽ��ϱ�? <y/n>";
		cin >> play;
		play = tolower(play);
	}
	cout << "���α׷��� �����մϴ�.\n";
	return 0;
}