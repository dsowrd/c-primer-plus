#include <iostream>
long double probability(unsigned numbers, unsigned picks, unsigned mega);

int main() {
	using namespace std;
	int total, choices, megaball;
	cout << "put total numbers, picking numbers and megaball numbers :\n";
	while ((cin >> total >> choices >> megaball) && choices < total) {
		cout << "winning probability is "
		<< probability(total, choices, megaball)
		<< "per once.\n"
		<< "put numbers again (q to quit)";
	}
	cout << "exit program\n";
	return 0;
}

long double probability(unsigned numbers, unsigned picks, unsigned mega) {
	long double result = 1.0;
	long double n;
	unsigned p;

	for (n = numbers, p = picks; p > 0; n--, p--)
		result = result * n / p;
	return result * mega;
}