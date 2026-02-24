#pragma once
/*
*  파일이름 : HighCreditAccount.h
*  작성자 : 백성윤
*  업데이트 정보 : [2026.02.24] 파일버전 0.7
*/

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount {
private:
	int specialRate;
public:
	HighCreditAccount(int ID, int money, char* name, int rate, int special)
		: NormalAccount(ID, money, name, rate), specialRate(special) {
	}
	virtual void Deposit(int money) {
		NormalAccount::Deposit(money);
		Account::Deposit(money * (specialRate / 100.0));
	}
};