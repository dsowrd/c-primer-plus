#include <iostream>

template<class T>

T max5(T * arr);

int main() {
	using namespace std;
	int iarr[5] = { 1, 2, 3, 4, 5 };
	double darr[5] = { 9.9, 8.8, 7.7, 6.6, 5.5 };
	cout << max5(iarr) << endl;
	cout << max5(darr) << endl;
	return 0;
}

template<class T>
T max5(T * arr) {
	T max = arr[0];
	for (int i = 1; i < 5; i++) {
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}