#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "vect.h"

int main() {
	using namespace std;
	using VECTOR::Vector;
	ofstream fout;
	fout.open("thewalk.txt");
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;

	cout << "��ǥ �Ÿ��� �Է��Ͻʽÿ�(�������� q) : ";
	while (cin >> target) {
		cout << "������ �Է��Ͻʽÿ�: ";
		if (!(cin >> dstep)) {
			break;
		}
		fout << "��ǥ�Ÿ� : " << target << ", ����: " << dstep << endl;
		fout << steps << ": " << result << endl;
		while (result.magval() < target) {
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
			fout << steps << ": " << result << endl;
		}
		cout << steps << " ������ ���� �� ������ ���� ��ġ:\n";
		fout << steps << " ������ ���� �� ������ ���� ��ġ:\n";
		cout << result << endl;
		fout << result << endl;
		result.polar_mode();
		cout << " �Ǵ�\n" << result << endl;
		fout << " �Ǵ�\n" << result << endl;
		cout << "������ ��տ��� ��� ��հŸ� = "
			<< result.magval() / steps << endl;
		fout << "������ ��տ��� ��� ��հŸ� = "
			<< result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "��ǥ �Ÿ��� �Է��Ͻʽÿ�(�������� q) : ";
	}
	cout << "���α׷��� �����մϴ�.\n";
	cin.clear();
	while (cin.get() != '\n') {
		continue;
	}
	fout.close();
	return 0;
}