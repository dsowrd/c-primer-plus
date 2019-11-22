#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

struct Review {
	std::string title;
	int rating;
	int price;
};

bool operator<(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2);
bool alphabet(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2);
bool rating(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2);
bool price(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2);
bool FillReview(Review& rr);
void ShowReview(const std::shared_ptr<Review> rr);

int main() {
	using namespace std;
	
	vector<shared_ptr<Review>> books;
	shared_ptr<Review> temp(new Review);

	while (FillReview(*temp)) {
		books.push_back(temp);
		temp.reset(new Review);
	}

	cout << "ǥ�� ����� �����Ͻʽÿ�(q�� �����մϴ�) : \n";
	cout << "1. ���� ����\t2. ���ĺ� ����\t3.������ ����\n";
	cout << "4. ������ ����\t5. ���� ���� ����\t6. ���� ���� ����\n";
	int selection;
	while (cin >> selection) {
		vector<shared_ptr<Review>> temp_books(books.begin(), books.end());
		switch (selection) {
		case 1:
			cout << "�����մϴ�. ����� ������ ���� " << books.size()
				<< "���� å ����� �Է��ϼ̽��ϴ�.\n" << "���\t����\n";
			for_each(books.begin(), books.end(), ShowReview);
			break;
		case 2:
			sort(temp_books.begin(), temp_books.end(), alphabet);
			cout << "���ĺ� ������ ���� : \n���\t����\n";
			for_each(temp_books.begin(), temp_books.end(), ShowReview);
			break;
		case 3:
			sort(temp_books.begin(), temp_books.end(), rating);
			cout << "������ ������ ���� : \n���\t����\n";
			for_each(temp_books.begin(), temp_books.end(), ShowReview);
			break;
		case 4:
			sort(temp_books.rbegin(), temp_books.rend(), rating);
			cout << "������ ������ ���� : \n���\t����\n";
			for_each(temp_books.begin(), temp_books.end(), ShowReview);
			break;
		case 5:
			sort(temp_books.begin(), temp_books.end(), price);
			cout << "���� ���� ������ ���� : \n���\t����\n";
			for_each(temp_books.begin(), temp_books.end(), ShowReview);
			break;
		case 6:
			sort(temp_books.rbegin(), temp_books.rend(), price);
			cout << "���� ���� ������ ���� : \n���\t����\n";
			for_each(temp_books.begin(), temp_books.end(), ShowReview);
			break;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻʽÿ�.\n";
			break;
		}
		cout << "ǥ�� ����� �����Ͻʽÿ�(q�� �����մϴ�) : \n";
		cout << "1. ���� ����\t2. ���ĺ� ����\t3.������ ����\n";
		cout << "4. ������ ����\t5. ���� ���� ����\t6. ���� ���� ����\n";
	}
	cout << "���α׷��� �����մϴ�.\n";
	return 0;
}

bool operator<(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2) {
	if (r1->title < r2->title)
		return true;
	else if (r1->title == r2->title && r1->rating < r2->rating)
		return true;
	else if (r1->title == r2->title && r1->rating == r2->rating && r1->price < r2->price)
		return true;
	else
		return false;
}

bool alphabet(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2) {
	if (r1->title < r2->title)
		return true;
	else
		return false;
}

bool rating(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2) {
	if (r1->rating < r2->rating)
		return true;
	else
		return false;
}

bool price(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2) {
	if (r1->price < r2->price)
		return true;
	else
		return false;
}

bool FillReview(Review& rr) {
	std::cout << "å ������ �Է��Ͻʽÿ�(�������� quit) : ";
	std::getline(std::cin, rr.title);
	if (rr.title == "quit")
		return false;
	std::cout << "å ���(0-10)�� �Է��Ͻʽÿ� : ";
	std::cin >> rr.rating;
	if (!std::cin)
		return false;
	while (std::cin.get() != '\n')
		continue;
	std::cout << "å ������ �Է��Ͻʽÿ� : ";
	std::cin >> rr.price;
	if (!std::cin)
		return false;
	while (std::cin.get() != '\n')
		continue;
	return true;
}

void ShowReview(const std::shared_ptr<Review> rr) {
	std::cout << rr->rating << "\t" << rr->title << "\t" << rr->price << std::endl;
}