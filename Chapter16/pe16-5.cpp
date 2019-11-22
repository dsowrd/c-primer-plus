#include <iostream>
#include <iterator>
#include <algorithm>
const int NUM = 10;

template<class T>
int reduce(T ar[], int n);

int main() {
	using std::cout;
	using std::endl;
	long array[NUM] = { 1, 3, 5, 5, 23, 66, 55, 23, 98, 6 };
	for (int i = 0; i < NUM; i++)
		cout << array[i] << " ";
	int red_num = reduce(array, NUM);
	cout << endl;
	for (int i = 0; i < red_num; i++)
		cout << array[i] << " ";
	cout << endl;

	std::string str_array[NUM] = { "palindrome|", "tot", "otto", "bool", "false", 
		"otto", "otto", "madamimadam", "cctype", "stl" };
	for (int i = 0; i < NUM; i++)
		cout << str_array[i] << " ";
	int red_str_num = reduce(str_array, NUM);
	cout << endl;
	for (int i = 0; i < red_str_num; i++)
		cout << str_array[i] << " ";
	return 0;
}

template<class T>
int reduce(T ar[], int n) {
	std::sort(ar, ar + n);
	T* past_end;
	past_end = std::unique(ar, ar + n);
	return past_end - ar;
}