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
	cout << "이름을 입력하십시오 : ";
	cin >> firstname;
	cout << "성을 입력하십시오 : ";
	cin >> lastname;
}

double Gunslinger::Draw() {
	return draw;
}

void Gunslinger::Show() {
	Person::Show();
	cout << "총 뽑는 속도 : " << draw << endl << "총의 금 수 : " << notch << endl;
}

void Gunslinger::Set() {
	Person::Set();
	cout << "권총을 빼내는 데 걸리는 시간 : ";
	cin >> draw;
	cout << "권총에 새겨진 금 수 : ";
	cin >> notch;
}

int PokerPlayer::Draw() {
	srand((unsigned int)time(NULL));
	return rand() % 52 + 1;
}

void PokerPlayer::Set() {
	Person::Set();
	cout << Draw() << "번 카드 드로우" << endl;
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
	cout << Cdraw() << "번 카드 드로우" << endl;
}