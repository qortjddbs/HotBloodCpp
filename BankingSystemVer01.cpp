/*
* Banking System Ver 0.1
* 작성자 : 백성윤
* 내용 : OOP 단계별 프로젝트의 기본 틀 구성
*/

#include <iostream>
#include <vector>
using namespace std;

struct Account {
	int ID;
	char name[100];
	int money;
};

vector<Account> account;

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
		case 1:
			Account a;
			cout << "[계좌개설]" << endl;
			cout << "계좌ID : ";
			cin >> a.ID;
			cout << "이 름 : ";
			cin >> a.name;
			cout << "입금액 : ";
			cin >> a.money;
			account.push_back(a);
			cout << "계좌가 성공적으로 개설되었습니다!" << endl;
			break;

		case 2: {
			int ID = -1;
			int index = -1;
			int deposit = 0;
			cout << "[입 금]" << endl;
			cout << "계좌ID : ";
			cin >> ID;
			for (int i = 0; i < account.size(); ++i) {
				if (ID == account[i].ID) {
					index = i;
					break;
				}
			}
			if (index != -1) {
				cout << "입금액 : ";
				cin >> deposit;
				account[index].money += deposit;
				cout << "입금완료" << endl;
			}
			else {
				cout << "해당 ID 계좌는 존재하지 않습니다!" << endl;
			}
			break;
		}

		case 3: {
			int ID = -1;
			int index = -1;
			int withdrawal = 0;
			cout << "[출 금]" << endl;
			cout << "계좌ID : ";
			cin >> ID;
			for (int i = 0; i < account.size(); ++i) {
				if (ID == account[i].ID) {
					index = i;
					break;
				}
			}
			if (index != -1) {
				cout << "출금액 : ";
				cin >> withdrawal;
				if (account[index].money >= withdrawal) {
					account[index].money -= withdrawal;
					cout << "출금완료" << endl;
				}
				else {
					cout << "ID : " << account[index].ID << "의 출금 가능 금액은 최대 " << account[index].money << "원 입니다." << endl;
				}
			} else {
				cout << "해당 ID 계좌는 존재하지 않습니다!" << endl;
			}
			break;
		}

		case 4:
			if (account.size() <= 0) {
				cout << "현재 개설된 계좌가 없습니다!" << endl;
			}
			else {
				for (int i = 0; i < account.size(); ++i) {
					cout << "계좌ID : " << account[i].ID << endl;
					cout << "이 름 : " << account[i].name << endl;
					cout << "잔 액 : " << account[i].money << endl;
					cout << endl;
				}
			}

			break;

		case 5:
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		}
	}

	return 0;
}