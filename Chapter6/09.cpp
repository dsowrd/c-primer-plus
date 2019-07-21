#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main() {
	using namespace std;
	struct donator {
		string name;
		double donation;
	};
	int num;
	int count = 0;
	ifstream inFile;
	inFile.open("Society for the Preservation of Rightful Infulence.txt");
	if (!inFile.is_open()) {
		cout << "can't open " << endl;
		cout << "exit program" << endl;
		exit(EXIT_FAILURE);
	}

	inFile >> num;
	inFile.get();

	donator * spr = new donator[num];

	for (int i = 0; i < num; i++) {
		getline(inFile, spr[i].name);
		inFile >> spr[i].donation;
		inFile.get();
	}

	cout << "high-rated donator" << endl;
	for (int i = 0; i < num; i++) {
		if (spr[i].donation >= 10000) {
			cout << spr[i].name << endl;
			count++;
		}
	}
	if (count == 0)
		cout << "no donator" << endl;
	cout << endl;

	count = 0;
	cout << "low-rated donator" << endl;
	for (int i = 0; i < num; i++) {

		if (spr[i].donation < 10000) {
			cout << spr[i].name << endl;
			count++;
		}
	}
	if (count == 0)
		cout << "no donator" << endl;

	delete[] spr;
	inFile.close();
	return 0;
}