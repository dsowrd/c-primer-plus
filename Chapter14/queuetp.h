#ifndef QUEUETP_H_
#define QUEUETP_H_
#include <string>
class Worker {
private:
	std::string fullname;
	long id;
protected:
	virtual void Data() const;
	virtual void Get();
public:
	Worker() : fullname("noname"), id(0L) {}
	Worker(const std::string& s, long n) : fullname(s), id(n) {}
	virtual ~Worker();
	void Set();
	void Show() const;
};

class Waiter : virtual public Worker {
private:
	int panache;
protected:
	void Data() const;
	void Get();
public:
	Waiter() : Worker(), panache(0) {}
	Waiter(const std::string& s, long n, int p = 0) : Worker(s, n), panache(p) {}
	Waiter(const Worker& wk, int p = 0) : Worker(wk), panache(p) {}
	void Set();
	void Show() const;
};

class Singer : virtual public Worker {
protected:
	enum { other, alto, contralto, soprano, bass, baritone, tenor };
	enum { Vtypes = 7 };
	void Data() const;
	void Get();
private:
	const char* pv[Vtypes] = { "other", "alto", "contralto", "soprano", "bass", "baritone", "tenor" };
	int voice;
public:
	Singer() : Worker(), voice(other) {}
	Singer(const std::string& s, long n, int v = other) : Worker(s, n), voice(v) {}
	Singer(const Worker& wk, int v = other) : Worker(wk), voice(v) {}
	void Set();
	void Show() const;
};

class SingingWaiter : public Singer, public Waiter {
protected:
	void Data() const;
	void Get();
public:
	SingingWaiter() {}
	SingingWaiter(const std::string & s, long n, int p = 0, int v = other)
		: Worker(s, n), Waiter(s, n, p), Singer(s, n, v) {}
	SingingWaiter(const Worker& wk, int p = 0, int v = other)
		: Worker(wk), Waiter(wk, p), Singer(wk, v) {}
	SingingWaiter(const Singer& wt, int p = 0)
		: Worker(wt), Waiter(wt, p), Singer(wt) {}
	void Set();
	void Show() const;
};

template <class T>
class QueueTp {
public:
	struct Node { T item; struct Node* next; };
	enum { Q_SIZE = 10 };
private:
	Node* front;
	Node* rear;
	int items;
	int size;
	QueueTp(const QueueTp& q) : size(0) {}
	QueueTp& operator=(const QueueTp& qt) { return *this; }
public:
	QueueTp(int s = Q_SIZE);
	~QueueTp();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const T& item);
	bool dequeue(T& item);
};
#endif // !QUEUETP_H_