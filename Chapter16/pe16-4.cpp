#include <iostream>
#include <set>
#include <iterator>
const int NUM = 10;

int reduce(long ar[], int n);

int main() {
	using std::cout;
	using std::endl;
	long array[NUM] = { 1, 3, 5, 5, 23, 66, 55, 23, 98, 6 };
	for(int i = 0; i < NUM; i++)
		cout << array[i] << " ";
	int red_num = reduce(array, NUM);
	cout << endl;
	for (int i = 0; i < red_num; i++)
		cout << array[i] << " ";
	return 0;
}

int reduce(long ar[], int n) {
	std::set<long> temp(ar, ar + n);
	std::set<long>::iterator il;
	int i = 0;
	for (il = temp.begin(); il != temp.end(); il++)
		ar[i++] = *il;
	for (; i < n; i++)
		ar[i] = '\0';
	return temp.size();
}