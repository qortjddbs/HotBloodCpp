// 01-5 이름공간(namespace)에 대한 소개
#include <iostream>

namespace BestComImpl {
	void SimpleFunc(void) {
		std::cout << "BestCom이 정의한 함수" << std::endl;
	}
}

namespace ProgComImpl {
	void SimpleFunc(void) {
		std::cout << "ProgCom이 정의한 함수" << std::endl;
	}
}

int main(void) {
	BestComImpl::SimpleFunc();
	ProgComImpl::SimpleFunc();

	return 0;
}