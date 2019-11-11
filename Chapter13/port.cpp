#include "port.h"
#include <cstring>

Port::Port(const char* br, const char* st, int b) {
	brand = new char[strlen(br) + 1];
	strcpy(brand, br);
	strncpy(style, st, 19);
	style[19] = '\0';
	bottles = b;
}

Port::Port(const Port& p) {
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strncpy(style, p.style, 19);
	style[19] = '\0';
	bottles = p.bottles;
}

Port& Port::operator=(const Port& p) {
	if (this == &p)
		return *this;
	delete[] brand;
	brand = new char[strlen(p.brand) + 1];
	strncpy(style, p.style, 19);
	style[19] = '\0';
	bottles = p.bottles;
	return *this;
}

Port& Port::operator+=(int b) {
	bottles += b;
}

Port& Port::operator-=(int b) {
	if (b < 0)
		cout << "남아 있는 수량보다 적습니다. 작업을 취소합니다." << endl;
	else
		bottles -= b;
}

void Port::Show() const {
	cout << "브랜드 : " << brand << endl;
	cout << "스타일 : " << style << endl;
	cout << "수량 : " << bottles << endl;
}

ostream& operator<<(ostream& os, const Port& p) {
	os << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
}

VintagePort::VintagePort() : Port() {
	strcpy(nickname, "none");
	year = 0;
}

VintagePort::VintagePort(const char* br, int b, const char* nn, int y) : Port(br, "vintage", b) {
	nickname = new char[strlen(nn) + 1];
	strcpy(nickname, nn);
	year = y;
}

VintagePort::VintagePort(const VintagePort& vp) : Port(vp) {
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
}

VintagePort& VintagePort::operator=(const VintagePort& vp) {
	if (this == &vp)
		return *this;
	Port::operator=(vp);
	delete[] nickname;
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
}

void VintagePort::Show() const {
	Port::Show();
	cout << "별명 : " << nickname << endl;
	cout << "포도 수확 년도 : " << year << endl;
}

ostream& operator<<(ostream& os, const VintagePort& vp) {
	os << (const Port&)vp;
	cout << ", " << vp.nickname << ", " << vp.year;
	return os;
}