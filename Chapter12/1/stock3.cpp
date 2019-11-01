#include "stock3.h"
#include <cstring>

Stock::Stock() {
	company = new char[8];
	std::strcpy(company, "no name");
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const char* co, long n, double pr) {
	int len = std::strlen(co);
	company = new char[len + 1];
	std::strcpy(company, co);

	if (n < 0) {
		std::cout << "�ֽ� ���� ������ �� �� �����Ƿ�, " << company << " shares�� 0���� �����մϴ�.\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}

Stock::~Stock() {
	delete[] company;
}

void Stock::buy(long num, double price) {
	if (num < 0)
		std::cout << "���� �ֽ� ���� ������ �� �� �����Ƿ�, �ŷ��� ��ҵǾ����ϴ�.\n";
	else {
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(long num, double price) {
	using std::cout;
	if (num < 0)
		cout << "�ŵ� �ֽ� ���� ������ �� �� �����Ƿ�, �ŷ��� ��ҵǾ����ϴ�.\n";
	else if (num > shares)
		cout << "���� �ֽĺ��� ���� �ֽ��� �ŵ��� �� �����Ƿ�, �ŷ��� ��ҵǾ����ϴ�.\n";
	else {
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price) {
	share_val = price;
	set_tot();
}

std::ostream& operator<<(std::ostream& os, const Stock& s) {
	using std::ios_base;
	ios_base::fmtflags orig = os.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = os.precision(3);

	os << "ȸ���: " << s.company << std::endl << "�ֽ� ��: " << s.shares << std::endl;
	os << "�ְ�: $" << s.share_val << std::endl;
	os.precision(2);
	os << "�ֽ� �� ��ġ : $" << s.total_val << std::endl;

	os.setf(orig, ios_base::floatfield);
	os.precision(prec);
	return os;
}

const Stock& Stock::topval(const Stock& s) const {
	if (s.total_val > total_val)
		return s;
	else
		return *this;
}