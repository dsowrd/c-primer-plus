#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>
#include <iterator>
#include <algorithm>

double sort_vector(std::vector<int> vec);
double sort_list(std::list<int> lis);
double sort_convert(std::list<int> lis, std::vector<int> vec);

int main() {
	using std::cout;
	using std::endl;
	using std::vector;
	using std::list;
	vector<int> vi0(10000000);
	srand((unsigned int)time(0));
	vector<int>::iterator ii;
	for (ii = vi0.begin(); ii != vi0.end(); ii++)
		*ii = rand() % 10000000 + 1;

	vector<int> vi;
	list<int> li;
	vi.assign(vi0.begin(), vi0.end());
	li.assign(vi0.begin(), vi0.end());
	double time_sort_vector = sort_vector(vi);
	double time_sort_list = sort_list(li);
	cout << "vector 정렬에 걸린 시간 : " << time_sort_vector << endl;
	cout << "list 정렬에 걸린 시간 : " << time_sort_list << endl;

	li.assign(vi0.begin(), vi0.end());
	double time_sort_convert = sort_convert(li, vi);
	cout << "list -> vector -> list 변형 정렬에 걸린 시간 : " << time_sort_convert << endl;
	return 0;
}

double sort_vector(std::vector<int> vec) {
	clock_t start = clock();
	std::sort(vec.begin(), vec.end());
	clock_t end = clock();
	return (double)(end - start) / CLOCKS_PER_SEC;
}

double sort_list(std::list<int> lis) {
	clock_t start = clock();
	lis.sort();
	clock_t end = clock();
	return (double)(end - start) / CLOCKS_PER_SEC;
}

double sort_convert(std::list<int> lis, std::vector<int> vec) {
	clock_t start = clock();
	vec.assign(lis.begin(), lis.end());
	std::sort(vec.begin(), vec.end());
	lis.assign(vec.begin(), vec.end());
	clock_t end = clock();
	return (double)(end - start) / CLOCKS_PER_SEC;
}