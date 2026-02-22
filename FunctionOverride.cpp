#include <iostream>
using namespace std;

class First {
public:
	void MyFunc() {
		cout << "First's MyFunc" << endl;
	}
};

class Second : public First {
	public:
	void MyFunc() {
		cout << "Second's MyFunc" << endl;
	}
};

class Third : public Second {
	public:
	void MyFunc() {
		cout << "Third's MyFunc" << endl;
	}
};

int main() {
	Third* tptr = new Third();
	Second* sptr = tptr;
	First* fptr = tptr;

	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();
	delete tptr;
	return 0;d
}