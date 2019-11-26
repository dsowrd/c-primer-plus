#include <iostream>

long double sum_values() { return 0; }

template<class T>
long double sum_values(const T& value);

template<class T, typename... Args>
long double sum_values(const T& value, const Args&... args);

int main() {
	std::cout << sum_values(1.1, 2, 'A') << std::endl;
	return 0;
}

template<class T>
long double sum_values(const T& value) {
	return static_cast<long double>(value);
}

template<class T, typename... Args>
long double sum_values(const T& value, const Args&... args) {
	return sum_values(value) + sum_values(args...);
}