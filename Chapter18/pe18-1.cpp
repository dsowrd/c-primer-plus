#include <iostream>

template<class T>
T average_list(std::initializer_list<T> li);

int main() {
	using namespace std;
	//double ����Ʈ
	auto q = average_list({ 15.4, 10.7, 9.0 });
	cout << q << endl;
	//int ����Ʈ
	cout << average_list({ 20, 30, 19, 17, 45, 38 }) << endl;
	//double ���� ����ȯ
	auto ad = average_list<double>({ 'A', 70, 65.33 });
	cout << ad << endl;
	return 0;
}

template<class T>
T average_list(std::initializer_list<T> li) {
	T sum = 0;
	for (auto p = li.begin(); p != li.end(); p++)
		sum += *p;
	return sum / li.size();
}