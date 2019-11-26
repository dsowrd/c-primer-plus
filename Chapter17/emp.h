#ifndef EMP_H_
#define EMP_H_
#include <iostream>
#include <string>
#include <fstream>

enum classkind { Employee, Manager, Fink, Highfink };

class abstr_emp {
private:
	std::string fname;
	std::string lname;
	std::string job;
protected:
	std::string& Job() { return job; }
	const std::string Job() const { return job; }
public:
	abstr_emp();
	abstr_emp(const std::string& fn, const std::string& ln, const std::string& j);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void GetAll(std::ifstream& fin);
	virtual void WriteAll(std::ofstream& fout);
	friend std::ostream& operator<<(std::ostream& os, const abstr_emp& e);
	virtual ~abstr_emp();
};

class employee : public abstr_emp {
public:
	employee();
	employee(const std::string& fn, const std::string& ln, const std::string& j);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void GetAll(std::ifstream& fin);
	virtual void WriteAll(std::ofstream& fout);
};

class manager : virtual public abstr_emp {
private:
	int inchargeof;
protected:
	int InChargeOf() const { return inchargeof; }
	int& InChargeOf() { return inchargeof; }
public:
	manager();
	manager(const std::string& fn, const std::string& ln, const std::string& j, int ico = 0);
	manager(const abstr_emp& e, int ico);
	manager(const manager& m);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void GetAll(std::ifstream& fin);
	virtual void WriteAll(std::ofstream& fout);
};

class fink : virtual public abstr_emp {
private:
	std::string reportsto;
protected:
	const std::string ReportsTo() const { return reportsto; }
	std::string& ReportsTo() { return reportsto; }
public:
	fink();
	fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo);
	fink(const abstr_emp& e, const std::string& rpo);
	fink(const fink& f);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void GetAll(std::ifstream& fin);
	virtual void WriteAll(std::ofstream& fout);
};

class highfink : public manager, public fink {
public:
	highfink();
	highfink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo, int ico);
	highfink(const abstr_emp& e, const std::string& rpo, int ico);
	highfink(const fink& f, int ico);
	highfink(const manager& m, const std::string& rpo);
	highfink(const highfink& h);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void GetAll(std::ifstream& fin);
	virtual void WriteAll(std::ofstream& fout);
};
#endif // !EMP_H_