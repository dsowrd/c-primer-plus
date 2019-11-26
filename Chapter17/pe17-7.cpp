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

	//문자열들을 얻는다
	cout << "문자열들을 입력하십시오 (끝내려면 빈 줄 입력) : \n";
	while (getline(cin, temp) && temp[0] != '\0')
		vostr.push_back(temp);
	cout << "다음과 같이 입력하셨습니다.\n";
	for_each(vostr.begin(), vostr.end(), ShowStr);

	//파일에 저장한다
	ofstream fout("strings.dat", ios_base::out | ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();

	//파일 내용을 복원한다
	vector<string> vistr;
	ifstream fin("strings.dat", ios_base::in | ios_base::binary);
	if (!fin.is_open()) {
		cerr << "입력을 위한 파일을 열 수 없습니다.\n";
		exit(EXIT_FAILURE);
	}
	GetStrs(fin, vistr);
	cout << "\n파일로부터 읽은 문자열들은 다음과 같습니다 : \n";
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