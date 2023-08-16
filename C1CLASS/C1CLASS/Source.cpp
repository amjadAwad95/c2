#include<iostream>

using namespace std;

class C1 {
public:
	int numberOfDigit(int number) {
		int temp = number;
		int digitCounter = 0;
		while (temp != 0) {
			digitCounter++;
			temp /= 10;
		}
		return digitCounter;
	}
	int fact(int number) {
		if (number < 0) {
			return 0;
		}
		int f = 1;
		for (int i = 1; i <= number; i++) {
			f *= i;
		}
		return f;
	}
	//overloading 1 pow
	int pow(int number, int p) {
		int powSum = 1;
		for (int i = 0; i < p; i++) {
			powSum *= number;
		}
		return powSum;
	}
	//overloading 2 pow
	double pow(double number, double p) {
		double powSum = 1;
		for (int i = 0; i < p; i++) {
			powSum *= number;
		}
		return powSum;
	}
	//overloading 3 pow
	float pow(float number, float p) {
		float powSum = 1;
		for (int i = 0; i < p; i++) {
			powSum *= number;
		}
		return powSum;
	}
	//overloading 4 pow
	short pow(short number, short p) {
		short powSum = 1;
		for (int i = 0; i < p; i++) {
			powSum *= number;
		}
		return powSum;
	}
	bool cheakArmStrongNumber(int number) {
		int n = number;
		int sum = 0;
		int numberDigit = numberOfDigit(number);
		while (n != 0) {
			sum += pow(n % 10, numberDigit);
			n /= 10;
		}
		if (sum == number) {
			return true;
		}
		return false;
	}
	bool cheakStrongNumber(int number) {
		int n = number;
		int sum = 0;
		while (n != 0) {
			sum += fact(n % 10);
			n /= 10;
		}
		if (sum == number) {
			return true;
		}
		return false;
	}
	//overloading 1 exChange
	void exChange(int &n1, int &n2) {
		int temp = n1;
		n1 = n2;
		n2 = temp;
	}
	//overloading 2 exChange
	void exChange(double &n1, double &n2) {
		double temp = n1;
		n1 = n2;
		n2 = temp;
	}
	//overloading 3 exChange
	void exChange(float &n1, float &n2) {
		float temp = n1;
		n1 = n2;
		n2 = temp;
	}
	//overloading 4 exChange
	void exChange(short &n1, short &n2) {
		short temp = n1;
		n1 = n2;
		n2 = temp;
	}
	int stringLenth(const char* s1) {
		int lenth = 0;
		for (lenth = 0; s1[lenth]; lenth++);
		return lenth;
	}
	void copyStringToString(char* s1, const char* s2) {
		if (!s1) {
			s1 = new char[stringLenth(s2) + 1];
		}
		while (*s1++ = *s2++);
	}
	
};

int main() {
	C1 test;
	int n1= 1;
	int n2 = 2;
	char* name=NULL;
	char n[20] = "amjad";
	test.copyStringToString(name, n);
	cout << name;
}