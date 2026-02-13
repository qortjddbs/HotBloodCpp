#include <iostream>
using namespace std;

class Car {		// 기본 연료 자동차
private:
	int gasolineGauge;
public:
	Car() : gasolineGauge(100) {

	}
	int GetGasGauge() {
		return gasolineGauge;
	}
};

class HybridCar : public Car {	// 하이브리드 자동차
private:
	int electricGauge;
public:
	HybridCar(int elec) : electricGauge(elec) {

	}
	HybridCar() : electricGauge(70) {}
	int GetElecGauge() {
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar {	// 하이브리드 워터카
private:
	int waterGauge;
public:
	HybridWaterCar() : waterGauge(50) {}
	void ShowCurrentGauge() {
		cout << "잔여 가솔린: " << GetGasGauge() << endl;
		cout << "잔여 전기량: " << GetElecGauge() << endl;
		cout << "잔여 워터량: " << waterGauge << endl;
	}
};

int main(void) {
	HybridWaterCar wCar(79, 65, 35);

	return 0;
}