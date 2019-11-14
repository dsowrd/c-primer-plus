#include "baddude.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Person::Person(Person& rp) {
	firstname = rp.firstname;
	lastname = rp.lastname;
}

Person::~Person() {}

void Person::Show() {
	cout << firstname << ", " << lastname << endl;
}

void Person::Set() {
	cout << "�̸��� �Է��Ͻʽÿ� : ";
	cin >> firstname;
	cout << "���� �Է��Ͻʽÿ� : ";
	cin >> lastname;
}

double Gunslinger::Draw() {
	return draw;
}

void Gunslinger::Show() {
	Person::Show();
	cout << "�� �̴� �ӵ� : " << draw << endl << "���� �� �� : " << notch << endl;
}

void Gunslinger::Set() {
	Person::Set();
	cout << "������ ������ �� �ɸ��� �ð� : ";
	cin >> draw;
	cout << "���ѿ� ������ �� �� : ";
	cin >> notch;
}

int PokerPlayer::Draw() {
	srand((unsigned int)time(NULL));
	return rand() % 52 + 1;
}

void PokerPlayer::Set() {
	Person::Set();
	cout << Draw() << "�� ī�� ��ο�" << endl;
}

double BadDude::Gdraw() {
	return Gunslinger::Draw();
}

int BadDude::Cdraw() {
	return PokerPlayer::Draw();
}

void BadDude::Show() {
	Gunslinger::Show();
}

void BadDude::Set() {
	Gunslinger::Set();
	cout << Cdraw() << "�� ī�� ��ο�" << endl;
}