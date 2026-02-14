#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Book {
private:
	char* title;
	char* isbn;		// 국제표준도서번호
	int price;
public:
	Book(const char* tit, const char* isb, int pri) : price(pri) {
		title = new char[strlen(tit) + 1];
		strcpy(title, tit);
		isbn = new char[strlen(isb) + 1];
		strcpy(isbn, isb);
	}
	void ShowBookInfo() {
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}
	~Book() {
		delete[] title;
		delete[] isbn;
	}
};

class EBook : public Book {
private:
	char* DRMKey;		// 보안관련 키
public:
	EBook(const char* tit, const char* isb, int price, const char* key) : Book(tit, isb, price) {
		DRMKey = new char[strlen(key) + 1];
		strcpy(DRMKey, key);
	}
	void ShowEBookInfo() {
		ShowBookInfo();
		cout << "인증키: " << DRMKey << endl;
	}
	~EBook() {
		delete[] DRMKey;
	}
};

int main(void) {
	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();
	return 0;
}