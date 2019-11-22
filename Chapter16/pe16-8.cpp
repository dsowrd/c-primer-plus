#include <iostream>
#include <set>
#include <string>
#include <iterator>
#include <algorithm>

int main() {
	using std::string;
	using std::cout;
	using std::cin;
	using std::set;
	set<string> Mat, Pat, party;
	string temp;
	cout << "Mat의 친구 이름(quit으로 종료) : ";
	while (cin >> temp && temp != "quit")
		Mat.insert(temp);
	std::ostream_iterator<string, char> out(cout, "\n");
	cout << "Mat의 친구 리스트 : \n";
	copy(Mat.begin(), Mat.end(), out);

	cout << "Pat의 친구 이릅(quit으로 종료) : ";
	while (cin >> temp && temp != "quit")
		Pat.insert(temp);
	cout << "Pat의 친구 리스트 : \n";
	copy(Pat.begin(), Pat.end(), out);

	set_union(Mat.begin(), Mat.end(), Pat.begin(), Pat.end(), std::insert_iterator<set<string>>(party, party.begin()));
	cout << "파티 인원 리스트 : \n";
	copy(party.begin(), party.end(), out);
	return 0;
}