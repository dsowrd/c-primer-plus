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
		cout << "#" << i + 1 << "��° �迭\n";
		cout << "S. ����, �Ŀ��\n";
		cout << "P. �Ŀ��\n";
		if (cin >> ch) {
			while (cin.get() != '\n') {
				continue;
			}
			switch (ch) {
			case 'S':
			case 's':
				cout << "����: ";
				cin >> stone;
				cout << "�Ŀ��: ";
				cin >> pound;
				weight[i] = Stonewt(stone, pound);
				break;
			case 'P':
			case 'p':
				cout << "�Ŀ��: ";
				cin >> pound;
				weight[i] = Stonewt(pound);
				break;
			default:
				cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���\n";
				i--;
				break;
			}
		}
		else {
			cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��Ͻʽÿ�\n";
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

	cout << "�ִ� ����: ";
	max.show_stn();
	cout << "�ּ� ����: ";
	min.show_stn();
	cout << "11���溸�� ũ�ų� ���� ������ ����: " << over_num << endl;
}