#include "complex0.h"
using std::cout;

Complex::Complex() {
	real = imaginary = 0;
}

Complex::Complex(int rl, int imag) {
	real = rl;
	imaginary = imag;
}

Complex::~Complex() {
}

Complex Complex::operator+(const Complex & cpx) const {
	return Complex(real + cpx.real, imaginary + cpx.imaginary);
}

Complex Complex::operator-(const Complex & cpx) const {
	return Complex(real - cpx.real, imaginary - cpx.imaginary);
}

Complex Complex::operator*(const Complex & cpx) const {
	return Complex(real * cpx.real - imaginary * cpx.imaginary, real * cpx.imaginary + imaginary * cpx.real);
}

Complex Complex::operator*(double mult) const {
	return Complex(mult * real, mult * imaginary);
}

Complex Complex::operator~() const {
	return Complex(real, imaginary * (-1));
}

Complex operator*(double m, const Complex & cpx) {
	return cpx * m;
}

std::ostream & operator<<(std::ostream & os, const Complex & cpx) {
	os << "(" << cpx.real << ", " << cpx.imaginary << "i)";
	return os;
}

std::istream & operator>>(std::istream & is, Complex & cpx) {
	cout << "실수부: ";
	is >> cpx.real;
	cout << "허수부: ";
	is >> cpx.imaginary;
	return is;
}