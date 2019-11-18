#ifndef ERROR1_H_
#define ERROR1_H_
#include <iostream>
#include <stdexcept>
#include <string>

class bad_hmean : public std::logic_error {
private:
	double v1;
	double v2;
public:
	bad_hmean(double a = 0, double b = 0, std::string s = "잘못된 매개변수 : a = -b\n")
		: v1(a), v2(b), std::logic_error(s) {}
	void what();
};

inline void bad_hmean::what() {
	std::cout << "hmean : " << logic_error::what() << std::endl;
}

class bad_gmean : public std::logic_error {
public:
	double v1;
	double v2;
	bad_gmean(double a = 0, double b = 0, std::string s = "gmean() 매개변수들은 >=0이어야 합니다.\n")
		: v1(a), v2(b), std::logic_error(s) {}
	void what();
};

inline void bad_gmean::what() {
	std::cout << "gmean : " << logic_error::what() << std::endl;
}
#endif // !ERROR1_H_