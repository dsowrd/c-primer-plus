#include <iostream>
#include "golf.h"
const int max = 3;

int main() {
	using std::cout;
	using std::endl;
	using std::cin;
	golf gf[max];
	int count = 0, flag;
	for (int i = 0; i < max; i++) {
		flag = setgolf(gf[i]);
		if (flag == false)
			break;
		count++;
	}
	for (int i = 0; i < count; i++)
		showgolf(gf[i]);
	for (int i = 0; i < count; i++) {
		int hc;
		cout << "\nÇÚµðÄ¸ º¯°æ #" << i + 1 << " : ";
		cin >> hc;
		handicap(gf[i], hc);
	}
	for (int i = 0; i < count; i++)
		showgolf(gf[i]);
	return 0;
}