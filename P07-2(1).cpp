#include <iostream>
using namespace std;

class Rectangle {

};

class Square : public Rectangle {

};

int main(void) {
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();

	return 0;
}