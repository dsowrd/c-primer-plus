#ifndef DMAABC_H_
#define DMAABC_H_
#include <string>
using std::string;

class dmaABC {
private:
	string label;
protected:
	const string Label() const { return label; }
public:
	dmaABC(const string l = "NULL");
	dmaABC(const dmaABC& rs);
	virtual ~dmaABC();
	dmaABC& operator=(const dmaABC& rs);
	virtual void view() const = 0;
};

class baseDMA : public dmaABC {
private:
	int rating;
public:
	baseDMA(const string l = "NULL", int r = 0);
	baseDMA(const baseDMA& rs);
	virtual ~baseDMA() {}
	baseDMA& operator=(const baseDMA& rs);
	virtual void view() const;
};

class lacksDMA : public dmaABC {
private:
	string color;
public:
	lacksDMA(const string c = "blank", const string l = "NULL");
	lacksDMA(const string c, const dmaABC& rs);
	virtual void view() const;
};

class hasDMA : public dmaABC {
private:
	string style;
public:
	hasDMA(const string s = "none", const string l = "NULL");
	hasDMA(const string s, const dmaABC& rs);
	hasDMA(const hasDMA& hs);
	virtual ~hasDMA();
	hasDMA& operator=(const hasDMA& rs);
	virtual void view() const;
};
#endif