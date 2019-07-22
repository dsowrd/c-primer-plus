#include <iostream>
#include "list.h"

bool List::addlist(Item it) {
	if (top < MAX) {
		items[top++] = it;
		return true;
	}
	else
		return false;
}

bool List::isempty() const {
	return top == 0;
}

bool List::isfull() const {
	return top == MAX;
}

void List::visit(void(*pf)(Item &)) {
	for (int i = 0; i < top; i++)
		pf(items[i]);
}

void List::showlist() const {
	for (int i = 0; i < top; i++)
		std::cout << items[i] << " ";
	std::cout << std::endl;
}