#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "emp.h"
const int MAX = 10;

int main() {
	using namespace std;
	abstr_emp* pc[MAX];
	int classtype;
	int i = 0;
	char ch;
	ifstream fin;
	fin.open("employee.txt");
	

	while ((fin >> classtype).get(ch)) {
		switch (classtype) {
		case Employee:
			pc[i] = new employee;
			break;
		case Manager:
			pc[i] = new manager;
			break;
		case Fink:
			pc[i] = new fink;
			break;
		case Highfink:
			pc[i] = new highfink;
			break;
		}
		pc[i++]->GetAll(fin);
	}
	int index = i;
	for (int i = 0; i < index; i++)
		pc[i]->ShowAll();

	fin.close();
	ofstream fout("employee.txt", ios_base::out | ios_base::app);

	cout << "생성할 객체 선택 : " << endl;
	cout << "0 : Employee, 1 : Manager" << endl;
	cout << "2 : Fink, 3 : Highfink, q : Quit" << endl;
	int select;
	for (int i = index; i < MAX; i++) {
		if (cin >> select) {
			switch (select) {
			case Employee:
				pc[i] = new employee;
				break;
			case Manager:
				pc[i] = new manager;
				break;
			case Fink:
				pc[i] = new fink;
				break;
			case Highfink:
				pc[i] = new highfink;
				break;
			}
			pc[i]->SetAll();
			pc[i]->WriteAll(fout);
		}
		else
			break;
		cout << "생성할 객체 선택 : " << endl;
		cout << "0 : Employee, 1 : Manager" << endl;
		cout << "2 : Fink, 3 : Highfink, q : Quit" << endl;
	}
	index = i;
	fout.close();
	for (int i = 0; i < index; i++) {
		pc[i]->ShowAll();
	}
	for (int i = 0; i < index; i++) {
		delete pc[i];
	}
	cout << "프로그램을 종료합니다.\n";
	return 0;
}