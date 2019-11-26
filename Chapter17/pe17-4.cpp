#include <iostream>
#include <fstream>
#include <string>

int main() {
	using std::cout;
	using std::cin;
	using std::string;
	using std::endl;
	std::ifstream fin1, fin2;
	std::ofstream fout;
	string temp;

	fin1.open("1.txt");
	if (!fin1.is_open()) {
		cout << "파일 1이 열리지 않습니다.\n";
		exit(EXIT_FAILURE);
	}
	fin2.open("2.txt");
	if (!fin2.is_open()) {
		cout << "파일 2가 열리지 않습니다.\n";
		exit(EXIT_FAILURE);
	}
	fout.open("3.txt");
	if (!fout.is_open()) {
		cout << "파일 3가 열리지 않습니다.\n";
		exit(EXIT_FAILURE);
	}

	while (!fin1.eof() || !fin2.eof()) {
		if (!fin1.eof()) {
			getline(fin1, temp);
			fout << temp << " ";
		}
		if (!fin2.eof()) {
			getline(fin2, temp);
			fout << temp;
		}
		fout << endl;
	}
	fin1.close();
	fin2.close();
	fout.close();
	return 0;
}