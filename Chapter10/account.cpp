#include <iostream>
#include <string>
#include "account.h"

BankAccount::BankAccount(const std::string & client, const std::string & num, double bal) {
	name = client;
	acctnum = num;
	balance = bal;
}

void BankAccount::show(void) const {
	std::cout << "�������� �̸� : " << BankAccount::name << std::endl;
	std::cout << "���� ��ȣ : " << BankAccount::acctnum << std::endl;
	std::cout << "�ܾ� : " << BankAccount::balance << std::endl;
}

void BankAccount::deposit(double cash) {
	std::cout << "�Աݵ� �ݾ� : " << cash << std::endl;
	BankAccount::balance += cash;
	std::cout << "�ܾ� : " << BankAccount::balance << std::endl;
}

void BankAccount::withdraw(double cash) {
	if ((BankAccount::balance - cash) < 0)
		std::cout << "����� �ݾ��� �ܾ׺��� �����ϴ�. �ʱ� ȭ������ �̵��մϴ�." << std::endl;
	else {
		std::cout << "����� �ݾ� : " << cash << std::endl;
		BankAccount::balance -= cash;
		std::cout << "�ܾ� : " << BankAccount::balance << std::endl;
	}
}