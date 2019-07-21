#include <iostream>
const int SIZE = 10;

int Fill_array(double arr[], int size);
void Show_array(double arr[], int n);
void Reverse_array(double arr[], int n);

int main() {
	double array[SIZE];
	int num;
	num = Fill_array(array, SIZE);
	Show_array(array, num);
	Reverse_array(array, num);
	Show_array(array, num);
	Reverse_array(array, num);
	Show_array(array, num);
	return 0;
}

int Fill_array(double arr[], int size) {
	using namespace std;
	int count = 0;
	cout << "put numbers : " << endl;
	for (int i = 0; i < size; i++) {
		if (!(cin >> arr[i]))
			break;
		count++;
	}
	return count;
}
void Show_array(double arr[], int n) {
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";
}
void Reverse_array(double arr[], int n) {
	double temp;
	for (int i = 0; i < n / 2; i++) {
		temp = arr[i];
		arr[i] = arr[n - i - 1];
		arr[n - i - 1] = temp;
	}
}