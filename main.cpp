// 01-4 인라인(inline) 함수
#include <iostream>

inline int SQUARE(int x) {
	return x * x;
}

int main(void) {
	std::cout << SQUARE(5) << std::endl;
	std::cout << SQUARE(12) << std::endl;
	return 0;
}