#include <iostream>
#include <cstring>
#include "queuetp.h"
const int SIZE = 5;

int main() {
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;

	QueueTp<Worker> lolas(SIZE);

	int ct;
	for (ct = 0; ct < SIZE; ct++) {
		char choice;
		cout << "������ �Է��Ͻʽÿ� : \n";
		cout << "w : ������ s : ���� : "
			<< "t : ���� �� ������ q : ����\n";
		cin >> choice;
		while (strchr("wstq", choice) == NULL) {
			cout << "w, s, t, q �߿��� �ϳ��� �����Ͻʽÿ� : ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice) {
			bool error;
		case 'w': {
			Waiter temp;
			temp.Set();
			error = lolas.enqueue(temp);
			break;
		}
		case 's': {
			Singer temp;
			temp.Set();
			error = lolas.enqueue(temp);
			break;
		}
		case 't': {
			SingingWaiter temp;
			temp.Set();
			error = lolas.enqueue(temp);
			break;
		}
		}
		cin.get();
	}

	cout << "\n��� ��Ȳ�� ������ �����ϴ� : \n";
	int i;
	for (i = 0; i < ct; i++) {
		cout << endl;
		Worker* temp = NULL;
		lolas.dequeue(*temp);
		temp->Show();
	}

	return 0;
}