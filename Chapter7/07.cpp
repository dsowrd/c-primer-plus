#include <iostream>
const int Max = 5;

int fill_array(int * begin, int * end, int &size);
void show_array(int * begin, int * end);
void revalue(int r, int * begin, int * end);

int main() {
	using namespace std;
	int properties[Max];
	int size;
	int end = fill_array(properties, properties + Max, size);
	show_array(properties, properties + size);
	if (size > 0) {
		cout << "input revalue : ";
		double factor;
		while (!(cin >> factor)) {
			cin.clear();
			while (cin.get() != '\n') {
				continue;
				cout << "wrong input. put number : ";
			}
		}
		revalue(factor, properties, properties + size);
		show_array(properties, properties + size);
	}
	cout << "exit program.\n";
	cin.get();
	return 0;
}

int fill_array(int * begin, int * end, int &size) {
	using namespace std;
	int temp;
	int * i;
	int num = 1;
	for (i = begin; i != end; i++, num++) {
		cout << num << "# property value : $";
		cin >> temp;
		if (!cin) {
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "wrong input; exiting input process.\n";
			break;
		}
		else if (temp < 0)
			break;
		*i = temp;
	}
	size = --num;
	return *i;
}
void show_array(int * begin, int * end) {
	using namespace std;
	int num = 1;
	for (int * i = begin; i != end; i++, num++) {
		cout << num << "# property : $";
		cout << *i << endl;
	}
}
void revalue(int r, int * begin, int * end) {
	for (int * i = begin; i != end; i++)
		*i *= r;
}