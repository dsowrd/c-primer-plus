#include "stonewt2.h"
using std::cout;

Stonewt::Stonewt(double lbs) {
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
	mode = LBS;
}

Stonewt::Stonewt(int stn, double lbs) {
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
	mode = STN;
}

Stonewt::Stonewt() {
	stone = 0;
	pounds = pds_left = 0.0;
	mode = LBS;
}

Stonewt::~Stonewt() {
}

void Stonewt::lbs_mode() {
	mode = LBS;
}

void Stonewt::stn_mode() {
	mode = STN;
}

Stonewt Stonewt::operator+(const Stonewt & st) const {
	Stonewt result;
	result.pounds = pounds + st.pounds;
	result.stone = int(result.pounds) / Lbs_per_stn;
	result.pds_left = result.pounds - result.stone * Lbs_per_stn;
	result.mode = mode;
	return result;
}

Stonewt Stonewt::operator-(const Stonewt & st) const {
	Stonewt result;
	result.pounds = pounds - st.pounds;
	result.stone = int(result.pounds) / Lbs_per_stn;
	result.pds_left = result.pounds - result.stone * Lbs_per_stn;
	result.mode = mode;
	return result;
}

Stonewt Stonewt::operator*(const double n) const {
	Stonewt result;
	result.pounds = pounds * n;
	result.stone = int(result.pounds) / Lbs_per_stn;
	result.pds_left = result.pounds - result.stone * Lbs_per_stn;
	result.mode = mode;
	return result;
}

Stonewt operator*(double n, Stonewt & st){
	return st * n;
}

std::ostream & operator<<(std::ostream & os, const Stonewt & st) {
	if (st.mode == Stonewt::LBS) {
		os << st.pounds << "파운드\n";
	}
	else if (st.mode == Stonewt::STN) {
		os << st.stone << "스톤, " << st.pds_left << "파운드\n";
	}
	else {
		os << "잘못된 모드입니다.\n";
	}
	return os;
}