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
	cout << "사례 연구 : 히서 은행의 ATM\n";
	cout << "큐의 최대 길이를 입력하십시오 : ";
	int qs;
	cin >> qs;
	std::queue<Item> line;

	cout << "시뮬레이션 시간 수를 입력하십시오 : ";
	int hours;
	cin >> hours;
	long cyclelimit = MIN_PER_HR * hours;

	cout << "시간당 평균 고객 수를 입력하십시오 : ";
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
		cout << "큐에 줄을 선 고객 수 : " << customers << endl;
		cout << "거래를 처리한 고객 수 : " << served << endl;
		cout << "발길을 돌린 고객 수 : " << turnaways << endl;
		cout << "평균 큐의 길이 : ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout.setf(ios_base::showpoint);
		cout << (double)sum_line << cyclelimit << endl;
		cout << "평균 대기 시간 : " << (double)line_wait / served << "분\n";
	}
	else
		cout << "고객이 한 명도 없습니다!\n";
	cout << "완료!\n";
	return 0;
}

bool newcustomer(double x) {
	return (std::rand() * x / RAND_MAX < 1);
}