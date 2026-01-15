#include <iostream>
using namespace std;

// 1번
//void addOne(int& ref) {
//	ref++;
//}
//
//void reverseSign(int& ref) {
//	ref *= -1;
//}
//
//int main(void) {
//	int num = 10;
//	cout << num << endl;
//	addOne(num);
//	cout << num << endl;
//	reverseSign(num);
//
//
//	return 0;
//}

// 2번
// 답 : 참조자 초기화시에는 무조건 변수명을 넣어줘야하기 때문

// 3번
void SwapPointer(int *ref1, int *ref2) {
	int temp = *ref1;
	*ref1 = *ref2;
	*ref2 = temp;
}

int main(void) {
	int num1 = 5;
	int* ptr1 = &num1;
	int num2 = 10;
	int* ptr2 = &num2;
	cout << *ptr1 << endl;
	cout << *ptr2 << endl;
	SwapPointer(ptr1, ptr2);
	cout << *ptr1 << endl;
	cout << *ptr2 << endl;

	return 0;
}