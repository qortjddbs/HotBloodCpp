#include <iostream>

int main(void) {
	char name[100];
	char num[100];

	std::cout << "이름과 전화번호를 순서대로 입력하세요 : ";
	std::cin >> name >> num;

	std::cout << "이름 : " << name << std::endl;
	std::cout << "전화번호 : " << num << std::endl;

	return 0;
}