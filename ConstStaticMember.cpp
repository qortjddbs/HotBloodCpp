#include <iostream>
using namespace std;

class CountArea {
public:
	const static int RUSSIA = 1707540;
	const static int CANADA = 998467;
	const static int CHINA = 957290;
	const static int SOUTH_KOEAK = 9922;
};

int main(void) {
	cout << "러시아의 면적 : " << CountArea::RUSSIA << " km^2" << endl;
	cout << "캐나다의 면적 : " << CountArea::CANADA << " km^2" << endl;
	cout << "중국의 면적 : " << CountArea::CHINA << " km^2" << endl;
	cout << "대한민국의 면적 : " << CountArea::SOUTH_KOEAK << " km^2" << endl;
	return 0;
}