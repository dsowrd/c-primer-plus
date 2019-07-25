#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vect.h"
int main() {
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	unsigned long max, min, avg, sum;
	double target;
	double dstep;
	int n;
	
	
	cout << "목표 거리를 입력하십시오(끝내려면 q): ";
	while (cin >> target) {
		cout << "보폭을 입력하십시오: ";
		if (!(cin >> dstep)) {
			break;
		}
		cout << "시도할 횟수를 입력하십시오: ";
		cin >> n;
		unsigned long * all_steps = new unsigned long[n];
		for (int i = 0; i < n; i++) {
			while (result.magval() < target) {
				direction = rand() % 360;
				step.reset(dstep, direction, Vector::POL);
				result = result + step;
				steps++;
			}
			all_steps[i] = steps;
			steps = 0;
			result.reset(0.0, 0.0);
		}
		max = min = sum = all_steps[0];
		for (int i = 1; i < n; i++) {
			if (all_steps[i] > max) {
				max = all_steps[i];
			}
			else if(all_steps[i] < min) {
				min = all_steps[i];
			}
			sum += all_steps[i];
		}
		avg = sum / (unsigned long)n;
		cout << n << "번 시도한 결과" << endl;
		cout << "최고 걸음 수: " << max << endl;
		cout << "최저 걸음 수: " << min << endl;
		cout << "평균 걸음 수: " << avg << endl;
		delete[] all_steps;
		cout << "목표 거리를 입력하십시오(끝내려면 q): ";
	}
	

	cout << "프로그램을 종료합니다.\n";
	cin.clear();
	while (cin.get() != '\n') {
		continue;
	}
	return 0;
}