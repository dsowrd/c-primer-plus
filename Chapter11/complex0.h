#ifndef COMPLEX0_H_
#define COMPLEX0_H_
#include <iostream>

class Complex {
private:
	int real;
	int imaginary;
public:
	Complex();
	Complex(int rl, int imag);
	~Complex();
	Complex operator+(const Complex & cpx) const;
	Complex operator-(const Complex & cpx) const;
	Complex operator*(const Complex & cpx) const;
	Complex operator*(double mult) const;
	Complex operator~() const;
	friend Complex operator*(double m, const Complex & cpx);
	friend std::ostream & operator<<(std::ostream & os, const Complex & cpx);
	friend std::istream & operator>>(std::istream & is, Complex & cpx);
};
#endif // !COMPLEX0_H_
