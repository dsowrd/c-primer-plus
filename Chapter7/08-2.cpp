#include <iostream>
#include <array>
#include <string>
const int Seasons = 4;
const char * Sname[Seasons] = { "Spring", "Summer", "Fall", "Winter" };

struct cost {
	double expenses[Seasons];
};

void fill(cost *ps);
void show(cost ds);

int main() {
	cost exp;
	fill(&exp);
	show(exp);
	return 0;
}

void fill(cost *ps) {
	using std::cin;
	using std::cout;
	for (int i = 0; i < Seasons; i++) {
		cout << Sname[i] << "�� �Ҹ�Ǵ� ���: ";
		cin >> ps->expenses[i];
	}
}
void show(cost ds) {
	using std::cout;
	using std::endl;
	double total = 0.0;
	cout << "\n������ ���\n";
	for (int i = 0; i < Seasons; i++) {
		cout << Sname[i] << " : $" << ds.expenses[i] << endl;
		total += ds.expenses[i];
	}
	cout << "�� ��� : $" << total << endl;
}