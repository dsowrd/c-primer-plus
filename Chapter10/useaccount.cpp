#include <iostream>
#include <string>
#include "account.h"

int main() {
	int choice;
	std::string nm;
	std::string acn;
	double bal;

	std::cout << "예금주의 이름 : ";
	std::cin >> nm;
	std::cout << "계좌번호 : ";
	std::cin >> acn;
	std::cout << "입금액 : ";
	std::cin >> bal;
	BankAccount BA(nm, acn, bal);

	std::cout << "\n할 작업을 선택하십시오(5 입력시 종료)" << std::endl;
	std::cout << "2. 계좌정보 출력" << std::endl;
	std::cout << "3. 입금" << std::endl;
	std::cout << "4. 출금" << std::endl;

	while (std::cin >> choice && choice != 5) {
		switch (choice) {
		case 2: {
			BA.show();
			break;
		}
		case 3: {
			std::cout << "입금할 금액 : ";
			std::cin >> bal;
			BA.deposit(bal);
			break;
		}
		case 4: {
			std::cout << "출금할 금액 : ";
			std::cin >> bal;
			BA.withdraw(bal);
			break;
		}
		}
		std::cout << "\n할 작업을 선택하십시오(5 입력시 종료)" << std::endl;
		std::cout << "2. 계좌정보 출력" << std::endl;
		std::cout << "3. 입금" << std::endl;
		std::cout << "4. 출금" << std::endl;
	}
	std::cout << "프로그램을 종료합니다." << std::endl;
	return 0;
}