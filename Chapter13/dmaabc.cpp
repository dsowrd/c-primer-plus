#include "dmaabc.h"
#include <cstring>
#include <iostream>
using std::strlen;
using std::strcpy;
using std::strncpy;
using std::cout;
using std::endl;

dmaABC::dmaABC(const string l) {
	label = l;
}

dmaABC::dmaABC(const dmaABC& rs) {
	label = rs.label;
}

dmaABC::~dmaABC() {
}

dmaABC& dmaABC::operator=(const dmaABC& rs) {
	if (this == &rs)
		return *this;
	label = rs.label;
	return *this;
}

baseDMA::baseDMA(const string l, int r) : dmaABC(l) {
	rating = r;
}

baseDMA::baseDMA(const baseDMA& rs) : dmaABC(rs) {
	rating = rs.rating;
}

baseDMA& baseDMA::operator=(const baseDMA& rs) {
	if (this == &rs)
		return *this;
	dmaABC::operator=(rs);
	rating = rs.rating;
	return *this;
}

void baseDMA::view() const {
	cout << "상표 : " << Label() << endl;
	cout << "등급 : " << rating << endl << endl;
}

lacksDMA::lacksDMA(const string c, const string l) : dmaABC(l) {
	color = c;
}

lacksDMA::lacksDMA(const string c, const dmaABC& rs) : dmaABC(rs) {
	color = c;
}

void lacksDMA::view() const {
	cout << "상표 : " << Label() << endl;
	cout << "색상 : " << color << endl << endl;
}

hasDMA::hasDMA(const string s, const string l) : dmaABC(l) {
	style = s;
}

hasDMA::hasDMA(const string s, const dmaABC& rs) : dmaABC(rs) {
	style = s;
}

hasDMA::hasDMA(const hasDMA& hs) : dmaABC(hs) {
	style = hs.style;
}

hasDMA::~hasDMA() {
}

hasDMA& hasDMA::operator=(const hasDMA& hs) {
	if (this == &hs)
		return *this;
	dmaABC::operator=(hs);
	style = hs.style;
	return *this;
}

void hasDMA::view() const {
	cout << "상표 : " << Label() << endl;
	cout << "스타일 : " << style << endl << endl;
}