#include <iostream>
#include <string>
#include "account.h"

BankAccount::BankAccount(const std::string & client, const std::string & num, double bal) {
	name = client;
	acctnum = num;
	balance = bal;
}

void BankAccount::show(void) const {
	std::cout << "예금주의 이름 : " << BankAccount::name << std::endl;
	std::cout << "계좌 번호 : " << BankAccount::acctnum << std::endl;
	std::cout << "잔액 : " << BankAccount::balance << std::endl;
}

void BankAccount::deposit(double cash) {
	std::cout << "입금된 금액 : " << cash << std::endl;
	BankAccount::balance += cash;
	std::cout << "잔액 : " << BankAccount::balance << std::endl;
}

void BankAccount::withdraw(double cash) {
	if ((BankAccount::balance - cash) < 0)
		std::cout << "출금할 금액이 잔액보다 많습니다. 초기 화면으로 이동합니다." << std::endl;
	else {
		std::cout << "출금한 금액 : " << cash << std::endl;
		BankAccount::balance -= cash;
		std::cout << "잔액 : " << BankAccount::balance << std::endl;
	}
}