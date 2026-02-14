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

};

class EBook : public Book {
private:
	char* DRMKey;		// 보안관련 키
public:

};

int main(void) {
	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();
	return 0;
}