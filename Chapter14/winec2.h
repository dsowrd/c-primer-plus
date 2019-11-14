#ifndef WINE2_H_
#define WINE2_H_
#include <string>
#include <valarray>
template <class T1, class T2>
class Pair {
private:
	T1 a;	//int�� �迭
	T2 b;	//int�� �迭
public:
	T1& first();	//int�� �迭(��Ȯ �⵵)����
	T2& second();	//int�� �迭(���� ����)����
	T1 first() const { return a; }
	T2 second() const { return b; }
	Pair(const T1& aval, const T2& bval) : a(aval), b(bval) {}	//������
	Pair() {}
};

class Wine : private std::string, private Pair<std::valarray<int>, std::valarray<int>> {
private:
	typedef std::valarray<int> ArrayInt;
	typedef Pair<ArrayInt, ArrayInt> PairArray;
	int num_harv;	//������Ȯ�� �⵵��
public:
	Wine(const char* l, int y, const int yr[], const int bot[]);	//������
	Wine(const char* l, int y);
	void GetBottles();	//�����Է�or����
	const std::string& Label() const { return (const std::string &)(*this); }	//�����̸� ����
	int sum();	//���� ��ü ���� ����
	void Show() const;
};
#endif // !WINE2_H_
