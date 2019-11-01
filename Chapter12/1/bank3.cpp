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
	cout << "사례 연구 : 히서 은행의 ATM\n";
	cout << "큐의 최대 길이를 입력하십시오 : ";
	int qs;
	cin >> qs;
	Queue line1(qs);
	Queue line2(qs);
	bool success = false;

	cout << "시뮬레이션 시간 수를 입력하십시오 : ";
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
	int wait_time1 = 0;
	int wait_time2 = 0;
	long line_wait = 0;
	double avg_line_wait = 0;

	while (!success) {
		while (!((avg_line_wait > 0.9) && (avg_line_wait) < 1.1) && ++perhour < cyclelimit) {
			min_per_cust = MIN_PER_HR / perhour;
			for (int cycle = 0; cycle < cyclelimit; cycle++) {
				if (newcustomer(min_per_cust)) {
					if (line1.isfull()) {
						if (line2.isfull())
							turnaways++;
						else {
							customers++;
							temp.set(cycle);
							line2.enqueue(temp);
						}
					}
					else {
						customers++;
						temp.set(cycle);
						line1.enqueue(temp);
					}
				}
				if (wait_time1 <= 0 && !line1.isempty()) {
					line1.dequeue(temp);
					wait_time1 = temp.ptime();
					line_wait += cycle - temp.when();
					served++;
				}
				if (wait_time2 <= 0 && !line2.isempty()) {
					line2.dequeue(temp);
					wait_time2 = temp.ptime();
					line_wait += cycle - temp.when();
					served++;
				}
				if (wait_time1 > 0)
					wait_time1--;
				if (wait_time2 > 0)
					wait_time2--;
				sum_line += line1.queuecount() + line2.queuecount();
			}
			avg_line_wait = (double)line_wait / served;
		}
		if (perhour >= cyclelimit)
			cout << "시뮬레이션 실패, 다시 시도합니다." << endl;
		else
			success = true;
	}
	cout << "평균 대기 시간 : " << avg_line_wait << endl;
	cout << "시간당 평균 고객 수 : " << perhour << endl;
	return 0;
}

bool newcustomer(double x) {
	return (std::rand() * x / RAND_MAX < 1);
}