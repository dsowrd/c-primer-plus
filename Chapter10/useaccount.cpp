#include <iostream>
#include <string>
#include "account.h"

int main() {
	int choice;
	std::string nm;
	std::string acn;
	double bal;

	std::cout << "�������� �̸� : ";
	std::cin >> nm;
	std::cout << "���¹�ȣ : ";
	std::cin >> acn;
	std::cout << "�Աݾ� : ";
	std::cin >> bal;
	BankAccount BA(nm, acn, bal);

	std::cout << "\n�� �۾��� �����Ͻʽÿ�(5 �Է½� ����)" << std::endl;
	std::cout << "2. �������� ���" << std::endl;
	std::cout << "3. �Ա�" << std::endl;
	std::cout << "4. ���" << std::endl;

	while (std::cin >> choice && choice != 5) {
		switch (choice) {
		case 2: {
			BA.show();
			break;
		}
		case 3: {
			std::cout << "�Ա��� �ݾ� : ";
			std::cin >> bal;
			BA.deposit(bal);
			break;
		}
		case 4: {
			std::cout << "����� �ݾ� : ";
			std::cin >> bal;
			BA.withdraw(bal);
			break;
		}
		}
		std::cout << "\n�� �۾��� �����Ͻʽÿ�(5 �Է½� ����)" << std::endl;
		std::cout << "2. �������� ���" << std::endl;
		std::cout << "3. �Ա�" << std::endl;
		std::cout << "4. ���" << std::endl;
	}
	std::cout << "���α׷��� �����մϴ�." << std::endl;
	return 0;
}