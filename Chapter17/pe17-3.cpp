#include <iostream>
#include <fstream>
#include <string>

int main() {
	using namespace std;
	ifstream fin;
	ofstream fout;
	fin.open("old.txt");
	fout.open("new.txt");
	if (!fin.is_open()) {
		cout << "old.txt������ �� �� �����ϴ�.\n";
		exit(EXIT_FAILURE);
	}
	if (!fout.is_open()) {
		cout << "new.txt������ �� �� �����ϴ�.\n";
		exit(EXIT_FAILURE);
	}
	string temp;
	while (getline(fin, temp)) {
		fout << temp << endl;
	}
	return 0;
}