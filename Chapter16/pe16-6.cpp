#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
const int MIN_PER_HR = 60;

class Customer {
private:
	long arrive;
	int processtime;
public:
	Customer() { arrive = processtime = 0; }
	void set(long when);
	long when() const { return arrive; }
	int ptime() const { return processtime; }
};

void Customer::set(long when) {
	processtime = std::rand() % 3 + 1;
	arrive = when;
}

typedef Customer Item;

bool newcustomer(double x);

int main() {
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;
	std::srand((unsigned int)std::time(0));
	cout << "��� ���� : ���� ������ ATM\n";
	cout << "ť�� �ִ� ���̸� �Է��Ͻʽÿ� : ";
	int qs;
	cin >> qs;
	std::queue<Item> line;

	cout << "�ùķ��̼� �ð� ���� �Է��Ͻʽÿ� : ";
	int hours;
	cin >> hours;
	long cyclelimit = MIN_PER_HR * hours;

	cout << "�ð��� ��� �� ���� �Է��Ͻʽÿ� : ";
	double perhour;
	cin >> perhour;
	double min_per_cust;
	min_per_cust = MIN_PER_HR / perhour;

	Item temp;
	long turnaways = 0;
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	int wait_time = 0;
	long line_wait = 0;

	for (int cycle = 0; cycle < cyclelimit; cycle++) {
		if (newcustomer(min_per_cust)) {
			if (line.size() == qs)
				turnaways++;
			else {
				customers++;
				temp.set(cycle);
				line.push(temp);
			}
		}
		if (wait_time <= 0 && !line.empty()) {
			wait_time = line.front().ptime();
			line_wait += cycle - line.front().when();
			served++;
			line.pop();
		}
		if (wait_time > 0)
			wait_time--;
		sum_line += line.size();
	}

	if (customers > 0) {
		cout << "ť�� ���� �� �� �� : " << customers << endl;
		cout << "�ŷ��� ó���� �� �� : " << served << endl;
		cout << "�߱��� ���� �� �� : " << turnaways << endl;
		cout << "��� ť�� ���� : ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout.setf(ios_base::showpoint);
		cout << (double)sum_line << cyclelimit << endl;
		cout << "��� ��� �ð� : " << (double)line_wait / served << "��\n";
	}
	else
		cout << "���� �� �� �����ϴ�!\n";
	cout << "�Ϸ�!\n";
	return 0;
}

bool newcustomer(double x) {
	return (std::rand() * x / RAND_MAX < 1);
}