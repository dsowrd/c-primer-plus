#ifndef LIST_H_
#define LIST_H_

typedef unsigned long Item;

class List {
private:
	enum { MAX = 10 };
	Item items[MAX];
	int top;
public:
	List() { items[0] = NULL; top = 0; }
	bool addlist(Item it);
	bool isempty() const;
	bool isfull() const;
	void visit(void(*pf)(Item &));
	void showlist() const;
};
#endif // !LIST_H_