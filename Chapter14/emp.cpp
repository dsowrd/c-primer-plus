#include "emp.h"

//abstr_emp �޼����
abstr_emp::abstr_emp() : fname("none"), lname("none"), job("none") {}

abstr_emp::abstr_emp(const std::string& fn, const std::string& ln, const std::string& j)
	: fname(fn), lname(ln), job(j) {}

abstr_emp::~abstr_emp() {}

void abstr_emp::ShowAll() const {
	using std::cout;
	using std::cin;
	using std::endl;
	cout << "�̸� : " << fname << ", " << lname << endl;
	cout << "���� : " << job << endl;
}

void abstr_emp::SetAll() {
	using std::cout;
	using std::cin;
	cout << "�۽�Ʈ ���� : ";
	cin >> fname;
	cout << "��Ʈ ���� : ";
	cin >> lname;
	cout << "���� : ";
	cin >> job;
}

//employee �޼����
employee::employee() : abstr_emp() {}

employee::employee(const std::string& fn, const std::string& ln, const std::string& j)
	: abstr_emp(fn, ln, j) {}

void employee::ShowAll() const {
	abstr_emp::ShowAll();
}

void employee::SetAll() {
	abstr_emp::SetAll();
}

manager::manager() : abstr_emp(), inchargeof(0) {}

manager::manager(const std::string& fn, const std::string& ln, const std::string& j, int ico)
	: abstr_emp(fn, ln, j), inchargeof(ico) {}

manager::manager(const abstr_emp& e, int ico) : abstr_emp(e), inchargeof(ico) {}

manager::manager(const manager& m) : abstr_emp(m), inchargeof(m.inchargeof) {}

void manager::ShowAll() const {
	using std::cout;
	using std::endl;
	abstr_emp::ShowAll();
	cout << "�����ϴ� ���� �� : " << inchargeof << endl;
}

void manager::SetAll() {
	using std::cout;
	using std::cin;
	abstr_emp::SetAll();
	cout << "�����ϴ� ���� �� : ";
	cin >> inchargeof;
}

//fink �޼����
fink::fink() : abstr_emp(), reportsto("none") {}

fink::fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo)
	: abstr_emp(fn, ln, j), reportsto(rpo) {}

fink::fink(const abstr_emp& e, const std::string& rpo) : abstr_emp(e), reportsto(rpo) {}

fink::fink(const fink& e) : abstr_emp(e), reportsto(e.reportsto) {}

void fink::ShowAll() const {
	using std::cout;
	using std::endl;
	abstr_emp::ShowAll();
	cout << "�����ϴ� ��� : " << reportsto << endl;
}

void fink::SetAll() {
	using std::cout;
	using std::cin;
	abstr_emp::SetAll();
	cout << "�����ϴ� ��� : ";
	cin >> reportsto;
}

//highfink �޼����
highfink::highfink() : manager(), fink() {}

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
	cout << "�����ϴ� ���� �� : " << InChargeOf() << endl;
	cout << "�����ϴ� ��� : " << ReportsTo() << endl;
}

void highfink::SetAll() {
	using std::cout;
	using std::cin;
	using std::endl;
	abstr_emp::SetAll();
	cout << "�����ϴ� ���� �� : ";
	cin >> InChargeOf();
	cout << "�����ϴ� ��� : ";
	cin >> ReportsTo();
}

//friend �޼����
std::ostream& operator<<(std::ostream& os, const abstr_emp& e) {
	os << e.fname << ", " << e.lname << std::endl;
	return os;
}