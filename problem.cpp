#include <iostream>

int main(void) {
	int num1, num2, num3, num4, num5;

	std::cout << "1번째 정수 입력 : ";
	std::cin >> num1;
	std::cout << "2번째 정수 입력 : ";
	std::cin >> num2;
	std::cout << "3번째 정수 입력 : ";
	std::cin >> num3;
	std::cout << "4번째 정수 입력 : ";
	std::cin >> num4;
	std::cout << "5번째 정수 입력 : ";
	std::cin >> num5;

	int result = num1 + num2 + num3 + num4 + num5;

	std::cout << "합계 : " << result << std::endl;

	return 0;
}