#include <iostream>
#include "stonewt2.h"
using std::cout;
void display(Stonewt & st, int n);

int main() {
	Stonewt pavarotti = 275;
	Stonewt wolfe(285.7);
	Stonewt taft(21, 8);

	pavarotti.stn_mode();
	cout << "테너 가수의 몸무게: " << pavarotti;
	wolfe.stn_mode();
	cout << "탐정의 몸무게: " << wolfe;
	taft.lbs_mode();
	cout << "대통령의 몸무게: " << taft;
	pavarotti = pavarotti + 1.3;
	Stonewt diff = wolfe - pavarotti;
	pavarotti.stn_mode();
	cout << "저녁 식사를 마친 후 테너 가수의 몸무게: " << pavarotti;
	diff.lbs_mode();
	cout << "탐정과 테너 가수의 몸무게 차이: " << diff;
	cout << "대통령이 두명이면..\n";
	display(taft * 2, 2);
	cout << "탐정이 세명이면..\n";
	display(3 * wolfe, 3);
	cout << "비만은 건강의 최대의 적이다.\n";
	return 0;
}

void display(Stonewt & st, int n) {
	for (int i = 0; i < n; i++) {
		st.stn_mode();
		cout << "와! " << st;
	}
}