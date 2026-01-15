//#include <iostream>
//using namespace std;
//
//typedef struct __Point {
//	int xpos;
//	int ypos;
//} Point;
//
//Point& PntAdder(const Point& p1, const Point& p2);
//
//int main(void) {
//	Point *p1 = new Point;
//	p1->xpos = 5; p1->ypos = 5;
//	Point* p2 = new Point;
//	p2->xpos = 3; p2->ypos = -2;
//	Point* add = new Point;
//	*add = PntAdder(*p1, *p2);
//	cout << p1->xpos << ", " << p1->ypos << endl;
//	cout << p2->xpos << ", " << p2->ypos << endl;
//	cout << add->xpos << ", " << add->ypos << endl;
//
//	delete p1;
//	delete p2;
//	delete add;
//
//	return 0;
//}
//
//Point& PntAdder(const Point& p1, const Point& p2) {
//	Point* temp = new Point;
//	temp->xpos = p1.xpos + p2.xpos;
//	temp->ypos = p1.ypos + p2.ypos;
//	return *temp;
//}

#include <iostream>
using namespace std;

typedef struct __Point {
	int xpos;
	int ypos;
} Point;

Point& PntAdder(const Point& p1, const Point& p2);

int main(void) {
	Point* p1 = new Point;
	p1->xpos = 5; p1->ypos = 5;
	Point* p2 = new Point;
	p2->xpos = 3; p2->ypos = -2;
	Point& pref = PntAdder(*p1, *p2);

	cout << p1->xpos << ", " << p1->ypos << endl;
	cout << p2->xpos << ", " << p2->ypos << endl;
	cout << pref.xpos << ", " << pref.ypos << endl;

	delete p1;
	delete p2;
	delete &pref;

	return 0;
}

Point& PntAdder(const Point& p1, const Point& p2) {
	Point* temp = new Point;
	temp->xpos = p1.xpos + p2.xpos;
	temp->ypos = p1.ypos + p2.ypos;
	return *temp;
}