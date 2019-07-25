#ifndef STONEWT2_H_
#define STONEWT2_H_
#include <iostream>

class Stonewt {
public:
	enum Mode { LBS, STN };
private:
	enum { Lbs_per_stn = 14 };
	int stone;
	double pds_left;
	double pounds;
	Mode mode;
public:
	Stonewt(double lbs);
	Stonewt(int stn, double lbs);
	Stonewt();
	~Stonewt();
	void lbs_mode();
	void stn_mode();
	Stonewt operator+(const Stonewt & st) const;
	Stonewt operator-(const Stonewt & st) const;
	Stonewt operator*(const double n) const;
	friend Stonewt operator*(double n, Stonewt & st);
	friend std::ostream & operator<<(std::ostream & os, const Stonewt & st);
};
#endif // !STONEWT2_H_