// 문제 01-3 [매개변수의 디폴트 값]
#include <iostream>

// 문제 1
// int BoxVolume(int length, int width = 1, int height = 1);
int BoxVolume(int length) {
	return length * 1 * 1;
}

int BoxVolume(int length, int width) {
	return length * width * 1;
}

int BoxVolume(int length, int width, int height) {
	return length * width * height;
}

int main(void) {
	std::cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << std::endl;
	std::cout << "[5, 5, D] : " << BoxVolume(5, 5) << std::endl;
	std::cout << "[7, D, D] : " << BoxVolume(7) << std::endl;
	// std::cout << "[D, D, D] : " << BoxVolume() << std::endl;

	return 0;
}

// int BoxVolume(int length, int width, int height) {
// 	return length * width * height;
// }

// 문제 2
// 답 : SimpleFunc을 호출할 때 인자로 아무것도 넣지 않으면 int SimpleFunc(int a=10)을 호출했는지 int SimpleFunc(void)를 호출했는지 알 수 없다는 문제점이 있다.