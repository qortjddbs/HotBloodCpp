#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
// #include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(void) {
	//char str1[100] = "I am strong!";
	//char str2[30];

	//strcpy(str2, str1);
	//int len = strlen(str1);
	//cout << "str1 : " << str1 << endl;
	//cout << "str2 : " << str2 << endl;
	//cout << "str1의 길이 : "<< len << endl;
	//if (strcmp(str1, str2) == 0) cout << "두 문장은 일치합니다!" << endl;
	//else if (strcmp(str1, str2) < 0) cout << "str1이 더 기네요! 하하" << endl;
	//else cout << "str2가 더 길었습니다~" << endl;
	//strcat(str1, str2);
	//cout << "str1 : " << str1 << endl;
	//if (strcmp(str1, str2) == 0) cout << "두 문장은 일치합니다!" << endl;
	//else if (strcmp(str1, str2) > 0) cout << "str1이 더 기네요! 하하" << endl;
	//else cout << "str2가 더 길었습니다~" << endl;
	int num[5];
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 5; ++i) {
		num[i] = rand() % 100;
		cout << num[i] << endl;
	}

	return 0;
}