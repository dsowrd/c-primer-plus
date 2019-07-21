#include <iostream>
#include <cctype>

template<class T>
T maxn(T * arr, int num);
template <> char * maxn(char * str[], int num);

int main() {
	using namespace std;
	int iarr[6] = { 1, 2, 3, 4, 5, 6 };
	double darr[4] = { 9.9, 8.8, 7.7, 6.6 };
	char * carr[5] = { "apple", "banana", "car", "dolphin", "eagle" };
	cout << maxn(iarr, 6) << endl;
	cout << maxn(darr, 4) << endl;
	cout << maxn(carr, 5) << endl;
	return 0;
}

template<class T>
T maxn(T * arr, int num) {
	T max = arr[0];
	for (int i = 1; i < num; i++) {
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

template <> char * maxn(char * str[], int num) {
	int max = strlen(str[0]);
	char * maxarr = str[0];
	for (int i = 1; i < num; i++) {
		if (strlen(str[i]) > max) {
			max = strlen(str[i]);
			maxarr = str[i];
		}
	}
	return maxarr;
}