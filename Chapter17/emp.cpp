#include "emp.h"

//abstr_emp 메서드들
abstr_emp::abstr_emp() : fname("none"), lname("none"), job("none") {}

abstr_emp::abstr_emp(const std::string& fn, const std::string& ln, const std::string& j)
	: fname(fn), lname(ln), job(j) {}

abstr_emp::~abstr_emp() {}

void abstr_emp::ShowAll() const {
	using std::cout;
	using std::endl;
	cout << "이름 : " << fname << ", " << lname << endl;
	cout << "직무 : " << job << endl;
}

void abstr_emp::SetAll() {
	using std::cout;
	using std::cin;
	cout << "퍼스트 네임 : ";
	cin >> fname;
	cout << "라스트 네임 : ";
	cin >> lname;
	cout << "직무 : ";
	cin >> job;
}

void abstr_emp::GetAll(std::ifstream& fin) {
	fin >> fname;
	fin.get();
	fin >> lname;
	fin.get();
	fin >> job;
	fin.get();
}

void abstr_emp::WriteAll(std::ofstream& fout) {
	using std::endl;
	std::string temp;
	temp = fname;
	fout << temp << endl;
	temp = lname;
	fout << temp << endl;
	temp = job;
	fout << temp << endl;
}

//employee 메서드들
employee::employee() : abstr_emp() {}

employee::employee(const std::string& fn, const std::string& ln, const std::string& j) : abstr_emp(fn, ln, j) {}

void employee::ShowAll() const {
	abstr_emp::ShowAll();
}

void employee::SetAll() {
	abstr_emp::SetAll();
}

void employee::GetAll(std::ifstream& fin) {
	abstr_emp::GetAll(fin);
}

void employee::WriteAll(std::ofstream& fout) {
	using std::endl;
	fout << Employee << endl;
	abstr_emp::WriteAll(fout);
}

//manager 메서드들
manager::manager() : abstr_emp(), inchargeof(0) {}

manager::manager(const std::string& fn, const std::string& ln, const std::string& j, int ico)
	: abstr_emp(fn, ln, j), inchargeof(ico) {}

manager::manager(const abstr_emp& e, int ico) : abstr_emp(e), inchargeof(ico) {}

manager::manager(const manager& m) : abstr_emp(m), inchargeof(m.inchargeof) {}

void manager::ShowAll() const {
	using std::cout;
	using std::endl;
	abstr_emp::ShowAll();
	cout << "관리하는 직원 수 : " << inchargeof << endl;
}

void manager::SetAll() {
	using std::cout;
	using std::cin;
	abstr_emp::SetAll();
	cout << "관리하는 직원 수 : ";
	cin >> inchargeof;
}

void manager::GetAll(std::ifstream& fin) {
	abstr_emp::GetAll(fin);
	fin >> inchargeof;
	fin.get();
}

void manager::WriteAll(std::ofstream& fout) {
	using std::endl;
	fout << Manager << endl;
	abstr_emp::WriteAll(fout);
	std::string temp;
	temp = Job();
	fout << temp << endl;
}

//fink 메서드들
fink::fink() : abstr_emp(), reportsto("none") {}

fink::fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo)
	: abstr_emp(fn, ln, j), reportsto(rpo) {}

fink::fink(const abstr_emp& e, const std::string& rpo) : abstr_emp(e), reportsto(rpo) {}

fink::fink(const fink& e) : abstr_emp(e), reportsto(e.reportsto) {}

void fink::ShowAll() const {
	using std::cout;
	using std::endl;
	abstr_emp::ShowAll();
	cout << "보고하는 대상 : " << reportsto << endl;
}

void fink::SetAll() {
	using std::cout;
	using std::cin;
	abstr_emp::SetAll();
	cout << "보고하는 대상 : ";
	cin >> reportsto;
}

void fink::GetAll(std::ifstream& fin) {
	abstr_emp::GetAll(fin);
	fin >> reportsto;
	fin.get();
}

void fink::WriteAll(std::ofstream& fout) {
	using std::endl;
	fout << Fink << endl;
	abstr_emp::WriteAll(fout);
	std::string temp;
	temp = reportsto;
	fout << temp << endl;
}

//highfink 메서드들
highfink::highfink() {}

highfink::highfink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo, int ico)
	: abstr_emp(fn, ln, j), fink(fn, ln, j, rpo), manager(fn, ln, j, ico) {}

highfink::highfink(const abstr_emp& e, const std::string& rpo, int ico)
	: abstr_emp(e), fink(e, rpo), manager(e, ico) {}

highfink::highfink(const fink& f, int ico) : abstr_emp(f), fink(f), manager(f, ico) {}

highfink::highfink(const manager& m, const std::string& rpo)
	: abstr_emp(m), manager(m), fink(m, rpo) {}

highfink::highfink(const highfink& h) : abstr_emp(h), manager(h), fink(h) {}

void highfink::ShowAll() const {
	using std::cout;
	using std::endl;
	abstr_emp::ShowAll();
	cout << "관리하는 직원 수 : " << InChargeOf() << endl;
	cout << "보고하는 대상 : " << ReportsTo() << endl;
}

void highfink::SetAll() {
	using std::cout;
	using std::cin;
	using std::endl;
	abstr_emp::SetAll();
	cout << "관리하는 직원 수 : ";
	cin >> InChargeOf();
	cout << "보고하는 대상 : ";
	cin >> ReportsTo();
}

void highfink::GetAll(std::ifstream& fin) {
	abstr_emp::GetAll(fin);
	fin >> InChargeOf();
	fin.get();
	fin >> ReportsTo();
	fin.get();
}

void highfink::WriteAll(std::ofstream& fout) {
	using std::endl;
	fout << Highfink << endl;
	abstr_emp::WriteAll(fout);
	std::string temp;
	temp = InChargeOf();
	fout << temp << endl;
	temp = ReportsTo();
	fout << temp << endl;
}

//friend 메서드들
std::ostream& operator<<(std::ostream& os, const abstr_emp& e) {
	os << e.fname << ", " << e.lname << std::endl;
	return os;
}