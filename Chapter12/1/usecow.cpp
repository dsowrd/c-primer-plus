#include <iostream>
#include "cow.h"

int main() {
	Cow cow1;
	Cow cow2("흑두루미", "투자", 60);
	Cow cow3 = Cow("말랑카우", "주식", 89);
	cow1 = Cow("흑우", "트위치보기", 66);
	cow1.ShowCow();
	cow2.ShowCow();
	cow3.ShowCow();
	cow1 = cow3;
	cow1.ShowCow();
	return 0;
}