#include <iostream>
using namespace std;

int RefRetFuncTwo(int& ref) {
	ref++;
	return ref;
}

int main(void) {
	int num1 = 1;
	int num2 = RefRetFuncTwo(num1);
	// int& num2 = RefRetFuncTwo(num1); // 오류 발생 (참조자는 반드시 변수로 초기화 되어야 함 - RefRetFuncTwo의 반환값은 상수취급)

	num1 += 1;
	num2 += 100;
	cout << "NUM1 : " << num1 << endl;
	cout << "NUM2 : " << num2 << endl;
	return 0;
}