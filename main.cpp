// 01-5 이름공간(namespace)에 대한 소개
#include <iostream>
using namespace std;

int val = 100;

int SimpleFunc(void) {
	int val = 20;
	val += 3;
	cout << "지역변수 val : " << val << endl;
	::val += 7;
	cout << "전역변수 val : " << ::val << endl;

	return 0;
}

int main(void) {
	SimpleFunc();

	return 0;
}