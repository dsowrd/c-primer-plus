#include <iostream>
#include <string>

int main() {
	using namespace std;
	string word;
	char ch;
	int vowel = 0, consonent = 0, others = 0;

	cout << "put words(q to quit) : " << endl;

	cin >> word;
	while (word != "q") {
		ch = tolower(word[0]);

		if (isalpha(word[0])) {
			if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') 
				vowel++;
			else 
				consonent++;
		}
		else
			others++;
		cin >> word;
	}

	cout << "words starts with vowels : " << vowel << endl;
	cout << "words starts with consonents : " << consonent << endl;
	cout << "others : " << others << endl;
	return 0;
}