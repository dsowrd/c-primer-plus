#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>

class Store {
public:
	std::ostream& os;
	Store(std::ostream& o) : os(o) {}
	void operator()(const std::string& str);
};

void Store::operator()(const std::string& s) {
	std::size_t len = s.size();
	os.write((char *)&len, sizeof(std::size_t));
	os.write(s.data(), len);
}

void ShowStr(const std::string& str);
void GetStrs(std::ifstream& fin, std::vector<std::string>& vst);

int main() {
	using namespace std;
	vector<string> vostr;
	string temp;

	//���ڿ����� ��´�
	cout << "���ڿ����� �Է��Ͻʽÿ� (�������� �� �� �Է�) : \n";
	while (getline(cin, temp) && temp[0] != '\0')
		vostr.push_back(temp);
	cout << "������ ���� �Է��ϼ̽��ϴ�.\n";
	for_each(vostr.begin(), vostr.end(), ShowStr);

	//���Ͽ� �����Ѵ�
	ofstream fout("strings.dat", ios_base::out | ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();

	//���� ������ �����Ѵ�
	vector<string> vistr;
	ifstream fin("strings.dat", ios_base::in | ios_base::binary);
	if (!fin.is_open()) {
		cerr << "�Է��� ���� ������ �� �� �����ϴ�.\n";
		exit(EXIT_FAILURE);
	}
	GetStrs(fin, vistr);
	cout << "\n���Ϸκ��� ���� ���ڿ����� ������ �����ϴ� : \n";
	for_each(vistr.begin(), vistr.end(), ShowStr);
	fin.close();
	return 0;
}

void ShowStr(const std::string& str) {
	std::cout << str << std::endl;
}

void GetStrs(std::ifstream& fin, std::vector<std::string>& vst) {
	std::string temp;
	size_t len;
	while (fin.read((char*)&len, sizeof(size_t)) && len > 0)
	{
		char ch;
		temp = "";
		for (int j = 0; j < len; j++)
		{
			if (fin.read(&ch, 1))
			{
				temp += ch;
			}
			else
				break;
		}
		if (fin)
			vst.push_back(temp);
	}
}