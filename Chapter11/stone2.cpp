#include <iostream>
#include "stonewt2.h"
using std::cout;
void display(Stonewt & st, int n);

int main() {
	Stonewt pavarotti = 275;
	Stonewt wolfe(285.7);
	Stonewt taft(21, 8);

	pavarotti.stn_mode();
	cout << "�׳� ������ ������: " << pavarotti;
	wolfe.stn_mode();
	cout << "Ž���� ������: " << wolfe;
	taft.lbs_mode();
	cout << "������� ������: " << taft;
	pavarotti = pavarotti + 1.3;
	Stonewt diff = wolfe - pavarotti;
	pavarotti.stn_mode();
	cout << "���� �Ļ縦 ��ģ �� �׳� ������ ������: " << pavarotti;
	diff.lbs_mode();
	cout << "Ž���� �׳� ������ ������ ����: " << diff;
	cout << "������� �θ��̸�..\n";
	display(taft * 2, 2);
	cout << "Ž���� �����̸�..\n";
	display(3 * wolfe, 3);
	cout << "���� �ǰ��� �ִ��� ���̴�.\n";
	return 0;
}

void display(Stonewt & st, int n) {
	for (int i = 0; i < n; i++) {
		st.stn_mode();
		cout << "��! " << st;
	}
}