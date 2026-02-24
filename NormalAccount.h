#pragma once
/*
*  파일이름 : NormalAccount.h
*  작성자 : 백성윤
*  업데이트 정보 : [2026.02.24] 파일버전 0.7
*/

#include "Account.h"

class NormalAccount : public Account {
private:
	int interRate;	// 이자율 %단위
public:
	NormalAccount(int ID, int money, char* name, int rate) : Account(ID, money, name), interRate(rate) {
	}
	virtual void Deposit(int money) {
		Account::Deposit(money);
		Account::Deposit(money * (interRate / 100.0));
	}
};