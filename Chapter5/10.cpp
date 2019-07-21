#include <iostream>

int main() {
	using namespace std;
	int rows;
	int j;

	cout << "출력할 행 수를 입력하십시오 : ";
	cin >> rows;

	for (int i = 0; i < rows; i++) {
		for (j = 0; j < rows - i - 1; j++)
			cout << ".";
		for (int k = j; k < rows; k++)
			cout << "*";
		cout << endl;
	}
	return 0;
}