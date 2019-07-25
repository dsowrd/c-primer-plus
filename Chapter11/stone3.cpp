#include <iostream>
#include "stonewt3.h"

int main() {
	using std::cout;
	using std::cin;
	using std::endl;
	Stonewt weight[6] = { 111, 222, 333 };
	Stonewt max, min;
	Stonewt stone_11 = Stonewt(11, 0);
	char ch;
	int stone;
	double pound;
	int over_num = 0;
	for (int i = 3; i < 6; i++) {
		cout << "#" << i + 1 << "번째 배열\n";
		cout << "S. 스톤, 파운드\n";
		cout << "P. 파운드\n";
		if (cin >> ch) {
			while (cin.get() != '\n') {
				continue;
			}
			switch (ch) {
			case 'S':
			case 's':
				cout << "스톤: ";
				cin >> stone;
				cout << "파운드: ";
				cin >> pound;
				weight[i] = Stonewt(stone, pound);
				break;
			case 'P':
			case 'p':
				cout << "파운드: ";
				cin >> pound;
				weight[i] = Stonewt(pound);
				break;
			default:
				cout << "잘못된 입력입니다. 다시 입력하세요\n";
				i--;
				break;
			}
		}
		else {
			cout << "잘못된 입력입니다. 다시 입력하십시오\n";
			while (cin.get() != '\n') {
				continue;
			}
			i--;
		}
	}
	max = min = weight[0];
	if (weight[0] >= stone_11) {
		over_num++;
	}
	
	for (int i = 1; i < 6; i++) {
		if (weight[i] > max) {
			max = weight[i];
		}
		else if (weight[i] < min) {
			min = weight[i];
		}
		if (weight[i] >= stone_11) {
			over_num++;
		}
	}

	cout << "최대 원소: ";
	max.show_stn();
	cout << "최소 원소: ";
	min.show_stn();
	cout << "11스톤보다 크거나 같은 원소의 개수: " << over_num << endl;
}