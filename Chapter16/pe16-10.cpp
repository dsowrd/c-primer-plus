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

	cout << "표시 방식을 선택하십시오(q로 종료합니다) : \n";
	cout << "1. 원래 순서\t2. 알파벳 순서\t3.증가율 순서\n";
	cout << "4. 감소율 순서\t5. 가격 증가 순서\t6. 가격 감소 순서\n";
	int selection;
	while (cin >> selection) {
		vector<shared_ptr<Review>> temp_books(books.begin(), books.end());
		switch (selection) {
		case 1:
			cout << "감사합니다. 당신은 다음과 같이 " << books.size()
				<< "개의 책 등급을 입력하셨습니다.\n" << "등급\t제목\n";
			for_each(books.begin(), books.end(), ShowReview);
			break;
		case 2:
			sort(temp_books.begin(), temp_books.end(), alphabet);
			cout << "알파벳 순서로 정렬 : \n등급\t제목\n";
			for_each(temp_books.begin(), temp_books.end(), ShowReview);
			break;
		case 3:
			sort(temp_books.begin(), temp_books.end(), rating);
			cout << "증가율 순서로 정렬 : \n등급\t제목\n";
			for_each(temp_books.begin(), temp_books.end(), ShowReview);
			break;
		case 4:
			sort(temp_books.rbegin(), temp_books.rend(), rating);
			cout << "감소율 순서로 정렬 : \n등급\t제목\n";
			for_each(temp_books.begin(), temp_books.end(), ShowReview);
			break;
		case 5:
			sort(temp_books.begin(), temp_books.end(), price);
			cout << "가격 증가 순서로 정렬 : \n등급\t제목\n";
			for_each(temp_books.begin(), temp_books.end(), ShowReview);
			break;
		case 6:
			sort(temp_books.rbegin(), temp_books.rend(), price);
			cout << "가격 감소 순서로 정렬 : \n등급\t제목\n";
			for_each(temp_books.begin(), temp_books.end(), ShowReview);
			break;
		default:
			cout << "잘못 입력하셨습니다. 다시 입력하십시오.\n";
			break;
		}
		cout << "표시 방식을 선택하십시오(q로 종료합니다) : \n";
		cout << "1. 원래 순서\t2. 알파벳 순서\t3.증가율 순서\n";
		cout << "4. 감소율 순서\t5. 가격 증가 순서\t6. 가격 감소 순서\n";
	}
	cout << "프로그램을 종료합니다.\n";
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
	std::cout << "책 제목을 입력하십시오(끝내려면 quit) : ";
	std::getline(std::cin, rr.title);
	if (rr.title == "quit")
		return false;
	std::cout << "책 등급(0-10)을 입력하십시오 : ";
	std::cin >> rr.rating;
	if (!std::cin)
		return false;
	while (std::cin.get() != '\n')
		continue;
	std::cout << "책 가격을 입력하십시오 : ";
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