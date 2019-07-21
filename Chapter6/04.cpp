#include <iostream>
const int strsize = 20;

int main() {
	using namespace std;
	struct bop {
		char fullname[strsize];
		char title[strsize];
		char bopname[strsize];
		int preference;
	};
	char ch;

	bop inf[5] = { {
		"Wimp Macho",
		"Web Designer",
		"Machoking",
		0
	}, {
		"Raki Rhodes",
		"Junior Programmer",
		"Rhino",
		1
	}, {
		"Cella Laiter",
		"DBA",
		"MIPS",
		2
	}, {
		"Hoppy Hipman",
		"analyst Trainee",
		"Hipster",
		1
	}, {
		"Pat Hand",
		"Illustrator",
		"LOOPY",
		2
	} };

	cout << "Benevolent Order of Programmers" << endl;
	cout << "a.fullname\t\tb.title" << endl;
	cout << "c.bopname\t\td.preference" << endl;
	cout << "q.quit" << endl;
	cin >> ch;

	while (ch != 'q') {
		switch (ch) {
		case 'a' :
			for (int i = 0; i < 5; i++)
				cout << inf[i].fullname << endl;
			break;
			
		case 'b':
			for (int i = 0; i < 5; i++)
				cout << inf[i].title << endl;
			break;

		case 'c':
			for (int i = 0; i < 5; i++)
				cout << inf[i].bopname << endl;
			break;

		case 'd':
			for (int i = 0; i < 5; i++) {
				switch (inf[i].preference) {
				case 0 :
					cout << inf[i].fullname << endl;
					break;

				case 1:
					cout << inf[i].title << endl;
					break;

				case 2:
					cout << inf[i].bopname << endl;
					break;
				}
			}
		}
		cout << "select : ";
		cin >> ch;
	}
	cout << "exit program" << endl;
	return 0;
}