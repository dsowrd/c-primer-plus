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
	
	
	cout << "��ǥ �Ÿ��� �Է��Ͻʽÿ�(�������� q): ";
	while (cin >> target) {
		cout << "������ �Է��Ͻʽÿ�: ";
		if (!(cin >> dstep)) {
			break;
		}
		cout << "�õ��� Ƚ���� �Է��Ͻʽÿ�: ";
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
		cout << n << "�� �õ��� ���" << endl;
		cout << "�ְ� ���� ��: " << max << endl;
		cout << "���� ���� ��: " << min << endl;
		cout << "��� ���� ��: " << avg << endl;
		delete[] all_steps;
		cout << "��ǥ �Ÿ��� �Է��Ͻʽÿ�(�������� q): ";
	}
	

	cout << "���α׷��� �����մϴ�.\n";
	cin.clear();
	while (cin.get() != '\n') {
		continue;
	}
	return 0;
}