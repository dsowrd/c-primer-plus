#include <iostream>
int count = 0;

void show(const char * arr, int n = 0);

int main() {
	char * alphabet[4]={ "apple", "banana", "car", "dolphin" };
	show(alphabet[0]);
	show(alphabet[1]);
	show(alphabet[2]);
	show(alphabet[3]);
	show(alphabet[1], 3);
	show(alphabet[3], 5);
	return 0;
}

void show(const char * arr, int n) {
	using namespace std;
	if (n != 0) {
		cout << "\nÈ£ÃâµÈ È½¼ö : " << ::count << endl;
		for (int i = 1; i <= ::count; i++) {
			cout << arr << endl;
		}
	}
	else cout << arr << endl;
	::count++;
}