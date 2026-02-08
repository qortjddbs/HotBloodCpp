// 이건 그냥 내가 짜본 코드
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//namespace COMP_POS {
//	enum {
//		CLERK = 1,
//		SENIOR = 2,
//		ASSIST = 3,
//		MANAGER = 4
//	};
//}
//
//class NameCard {
//private:
//	const char* name;
//	const char* company;
//	const char* num;
//	int rank;
//public:
//	NameCard(const char* name, const char* company, const char* num, int rank) : name(name), company(company), num(num), rank(rank) {
//	}
//	void ShowNameCardInfo() {
//		cout << "이름 : " << name << endl;
//		cout << "회사 : " << company << endl;
//		cout << "전화번호 : " << num << endl;
//		cout << "직급 : ";
//		switch (rank) {
//		case COMP_POS::CLERK:
//			cout << "사원";
//			break;
//		case COMP_POS::SENIOR:
//			cout << "주임";
//			break;
//		case COMP_POS::ASSIST:
//			cout << "대리";
//			break;
//		case COMP_POS::MANAGER:
//			cout << "과장";
//			break;
//		}
//		cout << endl << endl;
//	}
//};
//
//int main(void) {
//	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
//	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
//	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
//	manClerk.ShowNameCardInfo();
//	manSENIOR.ShowNameCardInfo();
//	manAssist.ShowNameCardInfo();
//	return 0;
//}


// 동적할당 한 버전
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS {
	enum {
		CLERK = 1,
		SENIOR = 2,
		ASSIST = 3,
		MANAGER = 4
	};
}

class NameCard {
private:
	char* name;
	char* company;
	char* num;
	int rank;
public:
	NameCard(const char* myName, const char* myCompany, const char* myNum, int myRank) {
		int lenName = strlen(myName) + 1;
		name = new char[lenName];
		strcpy(name, myName);
		int lenCompany = strlen(myCompany) + 1;
		company = new char[lenCompany];
		strcpy(company, myCompany);
		int lenNum = strlen(myNum) + 1;
		num = new char[lenNum];
		strcpy(num, myNum);
		rank = myRank;
	}
	NameCard(const NameCard& copy) : rank(copy.rank) {
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
		company = new char[strlen(copy.company) + 1];
		strcpy(company, copy.company);
		num = new char[strlen(copy.num) + 1];
		strcpy(num, copy.num);
	}
	~NameCard() {
		delete[] name;
		delete[] company;
		delete[] num;
	}
	void ShowNameCardInfo() {
		cout << "이름 : " << name << endl;
		cout << "회사 : " << company << endl;
		cout << "전화번호 : " << num << endl;
		cout << "직급 : ";
		switch (rank) {
		case COMP_POS::CLERK:
			cout << "사원";
			break;
		case COMP_POS::SENIOR:
			cout << "주임";
			break;
		case COMP_POS::ASSIST:
			cout << "대리";
			break;
		case COMP_POS::MANAGER:
			cout << "과장";
			break;
		}
		cout << endl << endl;
	}
};

int main(void) {
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard copy1 = manClerk;
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard copy2 = manSENIOR;
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();
	return 0;
}