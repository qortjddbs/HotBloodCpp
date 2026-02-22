#include <iostream>
using namespace std;

class First {
public:
	virtual void MyFunc() {
		cout << "First's MyFunc" << endl;
	}
};

class Second : public First {
	public:
	virtual void MyFunc() {
		cout << "Second's MyFunc" << endl;
	}
};

class Third : public Second {
	public:
	virtual void MyFunc() {
		cout << "Third's MyFunc" << endl;
	}
};

int main() {
	Third* tptr = new Third();
	Second* sptr = tptr;
	First* fptr = sptr;
	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();
	delete tptr;
	return 0;
}