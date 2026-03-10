// cin은 isteream 클래스의 객체이다
// istream은 이름공간 std안에 선언되어 있으며, 이의 사용을 위해서는 헤더파일 <iostream>을 포함해야 한다

#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	void ShowPosition() const {
		cout << '[' << xpos << ", " << ypos << "]" << endl;
	}
	friend ostream& operator<<(ostream&, const Point&);
	friend istream& operator>>(istream&, Point&);
};

ostream& operator<<(ostream& os, const Point& pos) {
	os << '[' << pos.xpos << ", " << pos.ypos << "]" << endl;
	return os;
}

istream& operator>>(istream& is, Point& pos) {
	is >> pos.xpos >> pos.ypos;
	return is;
}

int main(void) {
	Point pos1;
	cout << "x, y 좌표 순으로 입력: ";
	cin >> pos1;			// operator>>(cin, ~)
	cout << pos1;

	Point pos2;
	cout << "x, y 좌표 순으로 입력: ";
	cin >> pos2;
	cout << pos2;
}