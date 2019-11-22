#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <ctime>
using std::vector;

vector<int> Lotto(int lot_num, int set_num);

int main() {
	using std::cout;
	using std::cin;
	int lottery_numbers, selected_numbers;
	cout << "�� �ζ� ��ȣ �� : ";
	cin >> lottery_numbers;
	cout << "���� �� �� �ִ� ��ȣ �� : ";
	cin >> selected_numbers;
	vector<int> lottery = Lotto(lottery_numbers, selected_numbers);
	cout << "��÷�� �ζ� ��ȣ : ";
	std::ostream_iterator<int, char> out_iter(cout, " ");
	copy(lottery.begin(), lottery.end(), out_iter);
	cout << "\n";
	return 0;
}

vector<int> Lotto(int lot_num, int sel_num) {
	vector<int> temp(sel_num);
	vector<int> numbers(lot_num);
	vector<int>::iterator ii;
	int i = 0;
	for (ii = numbers.begin(); ii != numbers.end(); ii++)
		*ii = ++i;
	srand((unsigned int)std::time(0));
	std::random_shuffle(numbers.begin(), numbers.end());
	copy(numbers.begin(), numbers.begin() + sel_num, temp.begin());
	sort(temp.begin(), temp.end());
	return temp;
}