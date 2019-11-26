#include <iostream>
#include <set>
#include <string>
#include <iterator>
#include <fstream>
#include <algorithm>

int main() {
	using std::set;
	using std::string;
	using std::cerr;
	using std::cout;
	set<string> Mat, Pat, party;
	string temp;
	std::ifstream fin1, fin2;
	std::ofstream fout;

	fin1.open("mat.dat");
	if (!fin1.is_open()) {
		cerr << "mat.dat가 열리지 않습니다.\n";
		exit(EXIT_FAILURE);
	}
	fin2.open("pat.dat");
	if (!fin2.is_open()) {
		cerr << "pat.dat가 열리지 않습니다.\n";
		exit(EXIT_FAILURE);
	}
	fout.open("matnpat.dat");
	if (!fout.is_open()) {
		cerr << "matnpat.dat가 열리지 않습니다.\n";
		exit(EXIT_FAILURE);
	}

	while (!fin1.eof() && fin1 >> temp)
		Mat.insert(temp);
	std::ostream_iterator<string, char> out(cout, "\n");
	cout << "Mat의 친구 리스트 : \n";
	copy(Mat.begin(), Mat.end(), out);

	while (!fin2.eof() && fin2 >> temp)
		Pat.insert(temp);
	cout << "Pat의 친구 리스트 : \n";
	copy(Pat.begin(), Pat.end(), out);

	set_union(Mat.begin(), Mat.end(), Pat.begin(), Pat.end(), std::insert_iterator<set<string>>(party, party.begin()));
	std::ostream_iterator<string, char> f_out(fout, "\n");
	copy(party.begin(), party.end(), f_out);
	return 0;
}