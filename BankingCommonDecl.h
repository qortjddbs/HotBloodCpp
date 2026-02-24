#pragma once
/*
*  파일이름 : BankingSystemMain.cpp
*  작성자 : 백성윤
*  업데이트 정보 : [2026.02.24] 파일버전 0.7
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

// 프로그램 사용자의 선택 메뉴
enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

// 신용등급
enum {LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2};

// 계좌의 종류
enum {NORMAL = 1, CREDIT = 2};