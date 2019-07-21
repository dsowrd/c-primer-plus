#include <iostream>
using namespace std;
const int SIZE = 10;

int input(double arr[], int max);
void output(double arr[], int num);
double average(const double arr[], int num);

int main() {
	double arr[SIZE];
	double avg;
	int num;
	num = input(arr, SIZE);
	output(arr, num);
	avg = average(arr, num);
	cout << avg << endl;
	return 0;
}

int input(double arr[], int max) {
	int count = 0;
	for (int i = 0; i < max; i++) {
		if (cin >> arr[i])
			count++;
		else return count;
	}
	return count;
}

void output(double arr[], int num) {
	for (int i = 0; i < num; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

double average(const double arr[], int num) {
	double sum = 0, avg;
	for (int i = 0; i < num; i++)
		sum += arr[i];
	avg = sum / num;
	return avg;
}