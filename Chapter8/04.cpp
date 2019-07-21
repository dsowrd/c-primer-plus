#include <iostream>
#include <cstring>
using namespace std;

struct stringy {
	char * str;
	int ct;
};

void set(stringy & sty, char * str);
void show(const stringy & sty, int n = 1);
void show(const char * str, int n = 1);

int main() {
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";
	set(beany, testing);
	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done!");
	delete[] beany.str;
	return 0;
}

void set(stringy & sty, char * str) {
	int len = strlen(str);
	char * cpy = new char[len + 1];
	strcpy(cpy, str);
	sty.str = cpy;
}
void show(const stringy & sty, int n) {
	for (int i = 1; i <= n; i++)
		cout << sty.str << endl;
}
void show(const char * str, int n) {
	for (int i = 1; i <= n; i++)
		cout << str << endl;
}