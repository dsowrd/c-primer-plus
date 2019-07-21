#include <iostream>
#include <cstring>
#include <new>
using namespace std;
const int BUF = 512;
const int N = 2;
char buffer[BUF];

struct chaff {
	char dross[20];
	int slag;
};

void setchaff(chaff & cf);
void showchaff(const chaff & cf);

int main() {
	chaff * pc;
	pc = new (buffer) chaff[N];
	for (int i = 0; i < N; i++) {
		cout << "chaff #" << i + 1 << "ют╥б" << endl;
		setchaff(pc[i]);
	}
	for (int i = 0; i < N; i++) {
		cout << "chaff #" << i + 1 << endl;
		showchaff(pc[i]);
	}
	return 0;
}

void setchaff(chaff & cf) {
	char name[20];
	cout << "dross : ";
	cin >> name;
	strcpy(cf.dross, name);
	cout << "slag: ";
	cin >> cf.slag;

}
void showchaff(const chaff & cf) {
	if (cf.dross != '\0')
		cout << cf.dross;
	else
		return;
	cout << "\n" << cf.slag << endl;
}