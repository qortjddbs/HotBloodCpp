#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;

public:
	Point() {}
	Point (int x, int y) : xpos(x), ypos(y) {
	}
	void ShowPointInfo() const {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

class Circle {
private:
	Point p;
	int radius;
public:
	Circle() {}
	Circle(int x, int y, int rad) : p(x, y), radius(rad) {
	}
	void ShowCircleInfo() const {
		cout << "radius: " << radius << endl;
		p.ShowPointInfo();
	}
};

class Ring {
private:
	Circle in;
	Circle out;
public:
	Ring() {}
	Ring (int x1, int y1, int rad1, int x2, int y2, int rad2) : in(x1, y1, rad1), out(x2, y2, rad2) {
	}
	void ShowRingInfo() const {
		cout << "Inner Circle Information" << endl;
		in.ShowCircleInfo();
		cout << "Outter Circle Information" << endl;
		out.ShowCircleInfo();
	}
};

int main(void) {
	Ring ring(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}