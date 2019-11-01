#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"
const int MIN_PER_HR = 60;

bool newcustomer(double x);

int main() {
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;
	std::srand(std::time(0));
	cout << "��� ���� : ���� ������ ATM\n";
	cout << "ť�� �ִ� ���̸� �Է��Ͻʽÿ� : ";
	int qs;
	cin >> qs;
	Queue line(qs);
	bool success = false;

	cout << "�ùķ��̼� �ð� ���� �Է��Ͻʽÿ� : ";
	int hours;
	cin >> hours;
	long cyclelimit = MIN_PER_HR * hours;

	double perhour = 0;
	double min_per_cust;

	Item temp;
	long turnaways = 0;
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	int wait_time = 0;
	long line_wait = 0;
	double avg_line_wait = 0;

	while (!success) {
		while (!((avg_line_wait > 0.9) && (avg_line_wait < 1.1)) && (++perhour < cyclelimit)) {
			min_per_cust = MIN_PER_HR / perhour;
			for (int cycle = 0; cycle < cyclelimit; cycle++) {
				if (newcustomer(min_per_cust)) {
					if (line.isfull())
						turnaways++;
					else {
						customers++;
						temp.set(cycle);
						line.enqueue(temp);
					}
				}
				if (wait_time <= 0 && !line.isempty()) {
					line.dequeue(temp);
					wait_time = temp.ptime();
					line_wait += cycle - temp.when();
					served++;
				}
				if (wait_time > 0)
					wait_time--;
				sum_line += line.queuecount();
			}
			avg_line_wait = (double)line_wait / served;
		}
		if (perhour >= cyclelimit)
			cout << "�ùķ��̼� ����, �ٽ� �õ��մϴ�." << endl;
		else
			success = true;
	}
	cout << "��� ��� �ð�: " << avg_line_wait << endl;
	cout << "�ð��� ��� �� ��: " << perhour << endl;
	return 0;
}

bool newcustomer(double x) {
	return (std::rand() * x / RAND_MAX < 1);
}