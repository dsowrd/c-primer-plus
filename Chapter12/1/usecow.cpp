#include <iostream>
#include "cow.h"

int main() {
	Cow cow1;
	Cow cow2("��η��", "����", 60);
	Cow cow3 = Cow("����ī��", "�ֽ�", 89);
	cow1 = Cow("���", "Ʈ��ġ����", 66);
	cow1.ShowCow();
	cow2.ShowCow();
	cow3.ShowCow();
	cow1 = cow3;
	cow1.ShowCow();
	return 0;
}