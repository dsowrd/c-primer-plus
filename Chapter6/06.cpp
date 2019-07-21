#include <iostream>
const int StrSize = 20;

int main() {
	using namespace std;
	struct donator {
		char name[StrSize];
		double donation;
	};
	int num, count = 0;

	cout << "numbers of donator: ";
	cin >> num;
	cout << endl;

	donator * spr = new donator[num];

	for (int i = 0; i < num; i++) {
		cout << "donator #" << i + 1 << " : ";
		cin >> spr[i].name;
		cout << "donation : ";
		cin >> spr[i].donation;
		cout << endl;
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

	count = 0;
	cout << "low-rated donator" << endl;
	for (int i = 0; i < num; i++) {
		count = 0;
		
		if (spr[i].donation < 10000) {
			cout << spr[i].name << endl;
			count++;
		}
	}
	if (count == 0)
		cout << "no donator" << endl;

	delete[] spr;
	return 0;
}