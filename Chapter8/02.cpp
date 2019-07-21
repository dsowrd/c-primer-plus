#include <iostream>
const int NUM = 3;
const int SIZE = 20;

struct CandyBar {
	char brand[SIZE];
	double weight;
	int calorie;
};

void set(CandyBar & cb, char * brand = "Millennium Munch", double weight = 2.85, int calorie = 350);
void show(const CandyBar cb[]);

int main() {
	using namespace std;
	CandyBar product[NUM];
	char brand[SIZE];
	double weight;
	int calorie;

	for (int i = 0; i < NUM; i++) {
		cout << "#" << i + 1 << endl;
		cout << "상표 : ";
		cin >> brand;
		cout << "중량 : ";
		cin >> weight;
		cout << "칼로리 :";
		cin >> calorie;
		set(product[i], brand, weight, calorie);
	}
	show(product);
	return 0;
}

void set(CandyBar & cb, char * brand, double weight, int calorie) {
	strcpy(cb.brand, brand);
	cb.weight = weight;
	cb.calorie = calorie;
}
void show(const CandyBar cb[]) {
	using namespace std;
	for (int i = 0; i < NUM; i++) {
		cout << "#" << i + 1 << endl;
		cout << cb[i].brand << endl;
		cout << cb[i].weight << endl;
		cout << cb[i].calorie << endl;
	}
}