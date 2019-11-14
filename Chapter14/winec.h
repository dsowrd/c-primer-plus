#ifndef WINE_H_
#define WINE_H_
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

class Wine {
protected:
	typedef std::valarray<int> ArrayInt;
	typedef Pair<ArrayInt, ArrayInt> PairArray;
private:
	std::string label;	//���� �̸�
	PairArray pa;	//������Ȯ�⵵, ���� ����
	int num_harv;	//������Ȯ�� �⵵��
public:
	Wine(const char* l, int y, const int yr[], const int bot[]);	//������
	Wine(const char* l, int y);
	void GetBottles();	//�����Է�or����
	std::string& Label() { return label; }	//�����̸� ����
	int sum();	//���� ��ü ���� ����
	void Show();
};
#endif // !WINE_H_
