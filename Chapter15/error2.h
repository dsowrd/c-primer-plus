#ifndef ERROR2_H_
#define ERROR2_H_
#include <iostream>
#include <stdexcept>
#include <string>

class bad : public std::logic_error {
private:
	double v1;
	double v2;
public:
	bad(double a = 0, double b = 0, std::string s = "�߸��� �Ű�����")
		: v1(a), v2(b), std::logic_error(s) {}
	double v1_val() const { return v1; }
	double v2_val() const { return v2; }
};

class bad_hmean : public bad {
public:
	bad_hmean(double a = 0, double b = 0, std::string s = "�߸��� �Ű����� : a = -b\n") : bad(a, b, s) {}
	void what();
};

inline void bad_hmean::what() {
	std::cout << bad::logic_error::what() << std::endl;
}

class bad_gmean : public bad {
public:
	bad_gmean(double a = 0, double b = 0, std::string s = "gmean() �Ű��������� >=0�̾�� �մϴ�.\n")
		: bad(a, b, s) {}
	void what();
};

inline void bad_gmean::what() {
	std::cout << bad::logic_error::what() << std::endl;
}
#endif // !ERROR2_H_