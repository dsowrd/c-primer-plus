#include <iostream>
#include <fstream>
const int SIZE = 50;

int main() {
	using namespace std;
	char filename[SIZE];
	ifstream infile;
	cin.getline(filename, SIZE);
	infile.open(filename);

	if (!infile.is_open()) {
		cout << "can't open " << filename << endl;
		cout << "exit program" << endl;
		exit(EXIT_FAILURE);
	}

	char word[SIZE];
	int count = 0;

	infile >> word;
	while (infile.good()) {
		count++;
		infile >> word;
	}
	if (infile.eof()) {
		count++;
		cout << "end of file" << endl;
	}
	else if (infile.fail())
		cout << "data is not corresponding" << endl;
	else
		cout << "input ended of cause do not know" << endl;

	cout << "words : " << count << endl;
	infile.close();
	return 0;
}