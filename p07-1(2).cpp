#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo {
private:
	char* name;
	int age;
public:
	MyFriendInfo(const char* myname, int myage) : age(myage) {
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
	}
	void ShowMyFriendInfo() const {
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~MyFriendInfo() {
		delete[] name;
	}
};

class MyFriendDetailInfo : public MyFriendInfo {
private:
	char* addr;
	char* phone;
public:
	MyFriendDetailInfo(const char* name, int age, const char* myaddr, const char* myphone) : MyFriendInfo(name, age) {
		addr = new char[strlen(myaddr) + 1];
		strcpy(addr, myaddr);
		phone = new char[strlen(myphone) + 1];
		strcpy(phone, myphone);
	}
	void ShowMyFriendDetailInfo() const {
		ShowMyFriendInfo();
		cout << "주소: " << addr << endl;
		cout << "전화: " << phone << endl << endl;
	}
	~MyFriendDetailInfo() {
		delete[] addr;
		delete[] phone;
	}
};

int main(void) {
	MyFriendDetailInfo fren1("김진성", 22, "충남 아산", "010-1234-00XX");
	MyFriendDetailInfo fren2("이주성", 19, "경기 인천", "010-3333-00XX");
	fren1.ShowMyFriendDetailInfo();
	fren2.ShowMyFriendDetailInfo();

	return 0;
}