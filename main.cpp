// 01-5 이름공간(namespace)에 대한 소개
#include <iostream>
using namespace std;

int main(void) {
	int num = 20;
	cout << "Hello World!" << endl;
	cout << "Hello " << "World!" << endl;
	cout << num << ' ' << 'A';
	cout <<' ' << 3.14 << endl;

	return 0;
}