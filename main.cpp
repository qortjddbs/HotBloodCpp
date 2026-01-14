// 01-5 이름공간(namespace)에 대한 소개
#include <iostream>

namespace Parent {
	int num = 2;

	namespace SubOne {
		int num = 3;
	}

	namespace SubTwo {
		int num = 4;
	}
}

int main(void) {
	std::cout << Parent::num << std::endl;
	std::cout << Parent::SubOne::num << std::endl;
	std::cout << Parent::SubTwo::num << std::endl;

	return 0;
}