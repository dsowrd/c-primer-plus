#include <iostream>
#include <cctype>
#include "stack.h"

int main() {
	using namespace std;
	Stack st;
	char ch;
	double income = 0;
	Item ctm;
	cout << "고객을 추가하려면 A, 고객을 처리하려면 P, \n"
		<< "종료하려면 Q를 입력하십시오.\n";
	while (cin >> ch && toupper(ch) != 'Q') {
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch)) {
			cout << '\a';
			continue;
		}
		switch (ch) {
		case 'A':
		case 'a':
			
			if (st.isfull())
				cout << "스택이 가득 차 있습니다.\n";
			else {
				cout << "추가할 고객의 이름을 입력하십시오 : ";
				cin >> ctm.fullname;
				cout << "추가할 고객이 지출한 금액을 입력하십시오 : ";
				cin >> ctm.payment;
				st.push(ctm);
			}
			break;
		case 'P':
		case 'p':
			if (st.isempty())
				cout << "스택이 비어 있습니다.\n";
			else {
				st.pop(ctm);
				income += ctm.payment;
				cout << ctm.fullname << "고객을 처리하였습니다." << endl;
				cout << ctm.payment << "원을 지불하여 총 수입은 " << income << "원 입니다." << endl;
			}
			break;
		}
		cout << "\n고객을 추가하려면 A, 고객을 처리하려면 P, \n"
			<< "종료하려면 Q를 입력하십시오.\n";
	}
	cout << "프로그램을 종료합니다.\n";
	return 0;
}