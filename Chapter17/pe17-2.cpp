#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

int main() {
	using namespace std;
	ofstream fout;
	fout.open("copy.txt");

	string temp;
	while (temp != "exit") {
		cout << "$ ";
		getline(cin, temp);
		fout << "$ " << temp << endl;
	}
	fout.close();

	return 0;
}