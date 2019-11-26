#include "cpmv.h"
#include <iostream>

Cpmv::Cpmv() {
	pi = new Info;
	pi->qcode = "none";
	pi->zcode = "none";
}

Cpmv::Cpmv(std::string q, std::string z) {
	if (pi = new Info) {
		pi->qcode = q;
		pi->zcode = z;
	}
}

Cpmv::Cpmv(const Cpmv& cp) {
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
}

Cpmv::Cpmv(Cpmv&& mv) {
	pi = mv.pi;
	mv.pi = nullptr;
}

Cpmv::~Cpmv() {
	delete pi;
	pi = nullptr;
}

Cpmv& Cpmv::operator=(const Cpmv& cp) {
	delete pi;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
	return *this;
}

Cpmv& Cpmv::operator=(Cpmv&& mv) {
	pi = mv.pi;
	mv.pi = nullptr;
	return *this;
}

Cpmv Cpmv::operator+(const Cpmv& obj) const {
	Cpmv temp;
	temp.pi = new Info;
	temp.pi->qcode = pi->qcode + obj.pi->qcode;
	temp.pi->zcode = pi->zcode + obj.pi->zcode;
	return temp;
}

void Cpmv::Display() const {
	using std::cout;
	using std::endl;
	cout << "qcode : " << pi->qcode << endl;
	cout << "zcode : " << pi->zcode << endl;
}