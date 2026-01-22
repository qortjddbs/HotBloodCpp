#define _CRT_SECURE_NO_WARNINGS
#include <cstring>	// 이거 안써도 되네??
#include <iostream>
using namespace std;

class Printer {
private:
	char str[100];
public:
	void SetString(const char* s);
	void ShowString();
};

void Printer::SetString(const char* s) {
	strcpy(str, s);
}

void Printer::ShowString() {
	cout << str << endl;
}

int main(void) {
	Printer pnt;
	pnt.SetString("Hello world!");
	pnt.ShowString();

	pnt.SetString("I love C++");
	pnt.ShowString();
	return 0;
}