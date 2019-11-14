#ifndef WINE2_H_
#define WINE2_H_
#include <string>
#include <valarray>
template <class T1, class T2>
class Pair {
private:
	T1 a;	//int형 배열
	T2 b;	//int형 배열
public:
	T1& first();	//int형 배열(수확 년도)리턴
	T2& second();	//int형 배열(생산 수량)리턴
	T1 first() const { return a; }
	T2 second() const { return b; }
	Pair(const T1& aval, const T2& bval) : a(aval), b(bval) {}	//생성자
	Pair() {}
};

class Wine : private std::string, private Pair<std::valarray<int>, std::valarray<int>> {
private:
	typedef std::valarray<int> ArrayInt;
	typedef Pair<ArrayInt, ArrayInt> PairArray;
	int num_harv;	//포도수확한 년도합
public:
	Wine(const char* l, int y, const int yr[], const int bot[]);	//생성자
	Wine(const char* l, int y);
	void GetBottles();	//정보입력or수정
	const std::string& Label() const { return (const std::string &)(*this); }	//와인이름 리턴
	int sum();	//와인 전체 수량 리턴
	void Show() const;
};
#endif // !WINE2_H_
