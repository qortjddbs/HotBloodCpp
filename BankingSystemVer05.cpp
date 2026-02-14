/*
* Banking System Ver 0.5
* 작성자 : 백성윤
* 내용 : 컨트롤 클래스 생성
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
		SHOWDATA = 4,
		EXIT = 5
	};
}

class Account {
private:
	int ID;
	char* name;
	int money;
public:
	Account(int ID, const char* name, int money) : ID(ID), money(money) {
		int len = strlen(name) + 1;
		this->name = new char[len];
		strcpy(this->name, name);
	}
	Account(const Account& copy) : ID(copy.ID), money(copy.money) {
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
	}
	int ReturnID() const {
		return this->ID;
	}
	int ReturnMoney() const {
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
	void ShowData() const {
		cout << "계좌ID: " << ID << endl;
		cout << "이 름: " << name << endl;
		cout << "잔 액: " << money << endl << endl;
	}
	~Account() {
		delete[] name;
	}
};

class AccountHandler {
private:
	Account* AccList[100];
	int AccNum;
public:
	AccountHandler() : AccNum(0) { }
	void AddAccount() {
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
		AccList[AccNum++] = new Account(ID, name, money);
		cout << "계좌가 성공적으로 개설되었습니다!" << endl;
	}
	void DepositMoney() {
		int ID = -1;
		int index = -1;
		int money = 0;
		cout << "[입 금]" << endl;
		cout << "계좌ID : ";
		cin >> ID;
		for (int i = 0; i < AccNum; ++i) {
			if (ID == AccList[i]->ReturnID()) {
				index = i;
				break;
			}
		}
		if (index != -1) {
			cout << "입금액 : ";
			cin >> money;
			AccList[index]->Deposit(money);
			cout << "입금완료" << endl;
			return;
		}
		else {
			cout << "해당 ID 계좌는 존재하지 않습니다!" << endl;
			return;
		}
	}
	void WithdrawalMoney() {
		int ID = -1;
		int index = -1;
		int withdrawal_money = 0;
		cout << "[출 금]" << endl;
		cout << "계좌ID : ";
		cin >> ID;
		for (int i = 0; i < AccNum; ++i) {
			if (ID == AccList[i]->ReturnID()) {
				index = i;
				break;
			}
		}
		if (index != -1) {
			cout << "출금액 : ";
			cin >> withdrawal_money;
			AccList[index]->Withdrawal(withdrawal_money);
			return;
		}
		else {
			cout << "해당 ID 계좌는 존재하지 않습니다!" << endl;
			return;
		}
	}
	void ShowData() const {
		if (AccNum <= 0) {
			cout << "현재 개설된 계좌가 없습니다!" << endl;
		}
		else {
			for (int i = 0; i < AccNum; ++i) {
				AccList[i]->ShowData();
			}
		}
	}
	void quit() {
		//for (int i = 0; i < AccNum; ++i) {
		//	delete AccList[i];
		//}
		cout << "프로그램을 종료합니다." << endl;
		return;
	}

	~AccountHandler() {
		for (int i = 0; i < AccNum; ++i) {
			delete AccList[i];
		}
	}
};

int main(void) {
	AccountHandler handler;
	int command = -1;

	while (1) {
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
			handler.AddAccount();
			break;
		case BANK_COM::DEPOSIT: {
			handler.DepositMoney();
			break;
		}
		case BANK_COM::WITHDRAWAL: {
			handler.WithdrawalMoney();
			break;
		}
		case BANK_COM::SHOWDATA:
			handler.ShowData();
			break;
		case BANK_COM::EXIT:
			handler.quit();
			return 0;
		}
	}
}