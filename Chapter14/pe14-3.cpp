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
		cout << "직종을 입력하십시오 : \n";
		cout << "w : 웨이터 s : 가수 : "
			<< "t : 가수 겸 웨이터 q : 종료\n";
		cin >> choice;
		while (strchr("wstq", choice) == NULL) {
			cout << "w, s, t, q 중에서 하나를 선택하십시오 : ";
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

	cout << "\n사원 현황은 다음과 같습니다 : \n";
	int i;
	for (i = 0; i < ct; i++) {
		cout << endl;
		Worker* temp = NULL;
		lolas.dequeue(*temp);
		temp->Show();
	}

	return 0;
}