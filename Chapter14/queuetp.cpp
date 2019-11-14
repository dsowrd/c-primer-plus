#include "queuetp.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

Worker::~Worker() {}

void Worker::Set() {}

void Worker::Show() const {}

void Worker::Data() const {
	cout << "사원 이름 : " << fullname << endl;
}

void Worker::Get() {
	getline(cin, fullname);
	cout << "사원 번호를 입력하십시오 : ";
	cin >> id;
	while (cin.get() != '\n')
		continue;
}

void Waiter::Set() {
	cout << "웨이터의 이름을 입력하십시오 : ";
	Worker::Get();
	Get();
}

void Waiter::Show() const {
	cout << "직종 : 웨이터\n";
	Worker::Data();
	Data();
}

void Waiter::Data() const {
	cout << "웨이터 등급 : " << panache << endl;
}

void Waiter::Get() {
	cout << "웨이터 등급을 입력하십시오 : ";
	cin >> panache;
	while (cin.get() != '\n')
		continue;
}

void Singer::Set() {
	cout << "가수의 이름을 입력하십시오 : ";
	Worker::Get();
	Get();
}

void Singer::Show() const {
	cout << "직종 : 가수\n";
	Worker::Data();
	Data();
}

void Singer::Data() const {
	cout << "목소리 유형 : " << pv[voice] << endl;
}

void Singer::Get() {
	cout << "가수의 목소리 유형 번호를 입력하십시오 : \n";
	int i;
	for (i = 0; i < Vtypes; i++) {
		cout << i << " : " << pv[i] << " ";
		if (i % 4 == 3)
			cout << endl;
	}
	if (i % 4 != 0)
		cout << '\n';
	cin >> voice;
	while (cin.get() != '\n')
		continue;
}

void SingingWaiter::Data() const {
	Waiter::Data();
	Singer::Data();
}

void SingingWaiter::Get() {
	Waiter::Get();
	Singer::Get();
}

void SingingWaiter::Set() {
	cout << "가수 겸 웨이터의 이름을 입력하십시오 : ";
	Worker::Get();
	Get();
}

void SingingWaiter::Show() const {
	cout << "직종 : 가수 겸 웨이터\n";
	Worker::Data();
	Data();
}

template<class T>
QueueTp<T>::QueueTp(int s) : size(s) {
	front = rear = NULL;
	items = 0;
}

template<class T>
QueueTp<T>::~QueueTp() {
	Node* temp;
	while (front != NULL) {
		temp = front;
		front = front->next;
		delete temp;
	}
}

template<class T>
bool QueueTp<T>::isempty() const {
	return items = 0;
}

template<class T>
bool QueueTp<T>::isfull() const {
	return items == Q_SIZE;
}

template<class T>
int QueueTp<T>::queuecount() const {
	return items;
}

template<class T>
bool QueueTp<T>::enqueue(const T& item) {
	if (isfull())
		return false;
	Node* add = new Node;
	if (add == NULL)
		return false;
	add->item = item;
	add->next = NULL;
	items++;
	if (front == NULL)
		front = add;
	else
		rear->next = add;
	rear = add;
	return true;
}

template<class T>
bool QueueTp<T>::dequeue(T& item) {
	if (front == NULL)
		return false;
	item = front->item;
	items--;
	Node* temp = front;
	front = front->next;
	delete temp;
	if (items == 0)
		rear = NULL;
	return true;
}