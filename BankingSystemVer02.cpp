/*
* Banking System Ver 0.2
* 작성자 : 백성윤
* 내용 : Account 클래스 정의, 객체 포인터 배열 적용
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

namespace BANK_COM {
	enum {
		MAKE = 1,
		DEPOSIT = 2,
		WITHDRAWAL = 3,
		SHOWDATA = 4
	};
}

class Account {
private:
	int ID;
	char* name;
	int money;
public:
	Account(int ID, char* name, int money) : ID(ID), money(money) {
		int len = strlen(name) + 1;
		this->name = new char[len];
		strcpy(this->name, name);
	}
	int ReturnID() {
		return this->ID;
	}
	int ReturnMoney() {
		return this->money;
	}
	void Deposit(int deposit_money) {
		this->money += deposit_money;
	}
	void Withdrawal(int withdrawal_money) {
		if (this->money >= withdrawal_money) {
			this->money -= withdrawal_money;
			cout << "출금완료" << endl;
		}
		else {
			cout << "ID : " << this->ID << "의 출금 가능 금액은 최대 " << this->money << "원 입니다." << endl;
		}
	}
	void ShowData() {
		cout << "계좌ID: " << ID << endl;
		cout << "이 름: " << name << endl;
		cout << "잔 액: " << money << endl << endl;
	}
	~Account() {
		delete[] name;
	}
};

Account* AccPtr[100];		// 일단 계좌는 총 100개까지만 개설 가능
int AccNum = 0;

int main(void) {
	while (1) {
		int command = -1;

		cout << endl;
		cout << "-----Menu-----" << endl;
		cout << "1. 계좌개설" << endl;
		cout << "2. 입 금" << endl;
		cout << "3. 출 금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
		cout << "5. 프로그램 종료" << endl;
		cout << "선택 : ";
		cin >> command;
		cout << endl;

		switch (command) {
		case BANK_COM::MAKE:
			int ID;
			char name[20];		// 이름은 최대 20자까지 입력 가능
			int money;
			
			cout << "[계좌개설]" << endl;
			cout << "계좌ID : ";
			cin >> ID;
			cout << "이 름 : ";
			cin >> name;
			cout << "입금액 : ";
			cin >> money;
			AccPtr[AccNum++] = new Account(ID, name, money);
			cout << "계좌가 성공적으로 개설되었습니다!" << endl;
			break;

		case BANK_COM::DEPOSIT: {
			int ID = -1;
			int index = -1;
			int deposit_money = 0;
			cout << "[입 금]" << endl;
			cout << "계좌ID : ";
			cin >> ID;
			for (int i = 0; i < AccNum; ++i) {
				if (ID == AccPtr[i]->ReturnID()) {
					index = i;
					break;
				}
			}
			if (index != -1) {
				cout << "입금액 : ";
				cin >> deposit_money;
				AccPtr[index]->Deposit(deposit_money);
				cout << "입금완료" << endl;
			}
			else {
				cout << "해당 ID 계좌는 존재하지 않습니다!" << endl;
			}
			break;
		}
		case BANK_COM::WITHDRAWAL: {
			int ID = -1;
			int index = -1;
			int withdrawal_money = 0;
			cout << "[출 금]" << endl;
			cout << "계좌ID : ";
			cin >> ID;
			for (int i = 0; i < AccNum; ++i) {
				if (ID == AccPtr[i]->ReturnID()) {
					index = i;
					break;
				}
			}
			if (index != -1) {
				cout << "출금액 : ";
				cin >> withdrawal_money;
				AccPtr[index]->Withdrawal(withdrawal_money);
			}
			else {
				cout << "해당 ID 계좌는 존재하지 않습니다!" << endl;
			}
			break;
		}

		case BANK_COM::SHOWDATA:
			if (AccNum <= 0) {
				cout << "현재 개설된 계좌가 없습니다!" << endl;
			}
			else {
				for (int i = 0; i < AccNum; ++i) {
					AccPtr[i]->ShowData();
				}
			}

			break;

		case 5:
			for (int i = 0; i < AccNum; ++i) {
				delete AccPtr[i];
			}
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		}
	}

	return 0;
}