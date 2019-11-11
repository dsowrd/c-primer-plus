#ifndef CLASSIC1_H_
#define CLASSIC1_H_
#include "cd1.h"

class Classic : public Cd {
private:
	char* favorite;
public:
	Classic(const char* s1, const char* s2, const char* s3, int n, double x);
	Classic(const Classic& d);
	Classic();
	virtual ~Classic();
	virtual void Report() const;
	Classic& operator=(const Classic& d);
};
#endif // !CLASSIC_H_