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
	cout << "Mat�� ģ�� �̸�(quit���� ����) : ";
	while (cin >> temp && temp != "quit")
		Mat.insert(temp);
	std::ostream_iterator<string, char> out(cout, "\n");
	cout << "Mat�� ģ�� ����Ʈ : \n";
	copy(Mat.begin(), Mat.end(), out);

	cout << "Pat�� ģ�� �̸�(quit���� ����) : ";
	while (cin >> temp && temp != "quit")
		Pat.insert(temp);
	cout << "Pat�� ģ�� ����Ʈ : \n";
	copy(Pat.begin(), Pat.end(), out);

	set_union(Mat.begin(), Mat.end(), Pat.begin(), Pat.end(), std::insert_iterator<set<string>>(party, party.begin()));
	cout << "��Ƽ �ο� ����Ʈ : \n";
	copy(party.begin(), party.end(), out);
	return 0;
}