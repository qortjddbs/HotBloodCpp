#include <iostream>
using namespace std;

class Calculator {
private:
	int addNum;
	int subNum;
	int mulNum;
	int divNum;
public:
	void Init();
	float Add(float num1, float num2);
	float Sub(float num1, float num2);
	float Mul(float num1, float num2);
	float Div(float num1, float num2);
	void ShowOpCount();
};

void Calculator::Init() {
	addNum = 0;
	subNum = 0;
	mulNum = 0;
	divNum = 0;
}

float Calculator::Add(float num1, float num2) {
	addNum++;
	return num1 + num2;
}

float Calculator::Sub(float num1, float num2) {
	subNum++;
	return num1 - num2;
}

float Calculator::Mul(float num1, float num2) {
	mulNum++;
	return num1 * num2;
}

float Calculator::Div(float num1, float num2) {
	divNum++;
	return num1 / num2;
}

void Calculator::ShowOpCount() {
	cout << "µ¡¼À : " << addNum << " »¬¼À : " << subNum << " °ö¼À : " << mulNum << " ³ª´°¼À : " << divNum << endl;
}

int main(void) {
	Calculator cal;
	cal.Init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "2.2 - 1.5 = " << cal.Sub(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
	cal.ShowOpCount();
	return 0;
}