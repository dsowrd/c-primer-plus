#ifndef _NAMESP_H
#define _NAMESP_H

namespace SALES {
	class Sales {
	private:
		enum { QUARTERS = 4 };
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	public:
		Sales();
		Sales(double s[], int size);
		void showSales() const;
	};
}
#endif // !_NAMESP_H
