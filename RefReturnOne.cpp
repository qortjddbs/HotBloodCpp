#include <iostream>
using namespace std;

int& RefRetFuncOne(int& ref) {
	ref++;
	return ref;
}

int main(void) {
	int num1 = 1;
	int& num2 = RefRetFuncOne(num1);

	num1++;
	num2++;
	cout << "NUM1 : " << num1 << endl;
	cout << "NUM2 : " << num2 << endl;
	return 0;
}