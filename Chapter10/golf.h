#ifndef _GOLF_H
#define _GOLF_H

class Golf {
private:
	enum { Len = 40 };
	char fullname[Len];
	int handicap;
public:
	Golf();
	Golf (const char * name, int hc);
	void changehc(int hc);
	void showgolf() const;
};
#endif // !_GOLF_H
