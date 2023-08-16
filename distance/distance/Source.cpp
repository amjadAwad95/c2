#include<iostream>

using namespace std;

class Distance {
private:
	int feet;//0-infinity
	int inch;//0-12
public:
	void setFeet(int feet) {
		if (feet >= 0) {
			this->feet = feet;
		}
		else {
			exit(1);
		}
	}
	void setInch(int inch) {
		if (inch >= 0 && inch <= 12) {
			this->inch = inch;
		}
		else if (inch > 12) {
			this->feet += inch / 12;
			this->inch = inch % 12;
		}
		else {
			exit(1);
		}
	}
	int getFeet()const {
		return feet;
	}
	int getInch()const {
		return inch;
	}
	char* toString()const {
		int in = inch;
		int inchCount = 0;
		while (in != 0) {
			inchCount++;
			in /= 10;
		}
		int f = feet;
		int feetCount = 0;
		while (f != 0) {
			feetCount++;
			f /= 10;
		}
		int totalLen = inchCount + feetCount + 2;
		char* str = new char[totalLen + 1] {NULL};
		f = feet;
		int* temp = new int[feetCount];
		for (int i = 0; f!=0; i++) {
			temp[i] = (f % 10) + '0';
			f /= 10;
		}
		int arrayIndx=0;
		for (int i = feetCount-1; i >= 0; i--, arrayIndx++) {
			str[arrayIndx] = char(temp[i]);
		}
		str[feetCount] = ',';
		arrayIndx++;
		delete[] temp;
		in = inch;
		temp = new int[feetCount];
		for (int i = 0; in != 0; i++) {
			temp[i] = (in % 10)+'0';
			in /= 10;
		}
		for (int i = (arrayIndx+inchCount)-1,j=0; i >= feetCount; i--,j++,arrayIndx++) {
			str[arrayIndx] =char( temp[j]);
		}
		str[arrayIndx - 1] = '\0';
		delete[] temp;
		return str;
	}
};

int main() {
	Distance d;
	d.setFeet(234);
	d.setInch(200);
	char* distanceString = d.toString();
	cout << distanceString << endl;
	delete[] distanceString;
}