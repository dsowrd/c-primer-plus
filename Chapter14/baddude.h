#ifndef BADDUDE_H_
#define BADDUDE_H_
#include <string>
class Person {
private:
	std::string firstname;
	std::string lastname;
public:
	Person() : firstname("---"), lastname("---") {}
	Person(std::string& fn, std::string& ln) : firstname(fn), lastname(ln) {}
	Person(Person& rp);
	virtual void Show();
	virtual void Set();
	virtual ~Person() = 0;
};

class Gunslinger : virtual public Person {
private:
	double draw;
	int notch;
protected:
	void Set();
public:
	Gunslinger() : Person(), draw(0), notch(0) {}
	Gunslinger(std::string& fn, std::string& ln, double dr, int nt) 
		: Person(fn, ln), draw(dr), notch(nt) {}
	Gunslinger(Person& rp, double dr, int nt) : Person(rp), draw(dr), notch(nt) {}
	double Draw();
	void Show();
};

class PokerPlayer : virtual public Person {
public:
	PokerPlayer() : Person() {}
	PokerPlayer(std::string& fn, std::string& ln) : Person(fn, ln) {}
	PokerPlayer(Person& rp) : Person(rp) {}
	int Draw();
	void Set();
};

class BadDude : public Gunslinger, public PokerPlayer {
public:
	BadDude() : Person(), Gunslinger(), PokerPlayer() {}
	BadDude(std::string& fn, std::string& ln, double dr, int nt)
		: Person(fn, ln), Gunslinger(fn, ln, dr, nt), PokerPlayer(fn, ln) {}
	BadDude(Person& rp, double dr, int nt) 
		: Person(rp), Gunslinger(rp, dr, nt), PokerPlayer(rp) {}
	BadDude(Gunslinger& rg) : Gunslinger(rg), Person(rg), PokerPlayer(rg) {}
	BadDude(PokerPlayer& rk, double dr, int nt) 
		: Person(rk), PokerPlayer(rk), Gunslinger(rk, dr, nt) {}
	double Gdraw();
	int Cdraw();
	void Show();
	void Set();
};
#endif // !BADDUDE_H_
