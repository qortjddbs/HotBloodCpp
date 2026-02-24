#pragma once
/*
	파일 이름 : Account.h
	작성자 : 백성윤
	업데이트 정보 : [2026.02.24] 파일버전 0.7
*/

class Account {
private:
	int accID;
	int balance;
	char* cusName;
public:
	Account(int ID, int money, char* name);
	Account(const Account& ref);

	int GetAccID() const;
	virtual void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo() const;
	~Account();
};