#ifndef PLORG_H_
#define PLORG_H_

class Plorg {
private:
	enum { SIZE = 20 };
	char name[SIZE];
	int ci;
public:
	Plorg();
	Plorg(char * nm);
	void changeci(int c);
	void showplg() const;
};
#endif // !PLORG_H_