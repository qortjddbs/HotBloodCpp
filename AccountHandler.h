#pragma once
/*
*  파일이름 : AccountHandler.h
*  작성자 : 백성윤
*  업데이트 정보 : [2026.02.24] 파일버전 0.7
*/

#include "Account.h"

class AccountHandler {
private:
	Account* accArr[100];
	int accNum;
public:
	AccountHandler();
	void ShowMenu(void) const;
	void MakeAccount(void);
	void DepositMoney(void);
	void WithdrawMoney(void);
	void ShowAllAccInfo(void) const;
	~AccountHandler();
protected:
	void MakeNormalAccount(void);
	void MakeHighCreditAccount(void);
};