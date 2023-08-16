#include"Array.h"


char* Array:: toString(int* array) {
		int digitNumber = 0;
		for (int i = 0; i < size; i++) {
			int n = array[i];
			while (n) {
				digitNumber++;
				n /= 10;
			}
		}
		int stringLen = (digitNumber + size - 1) + 3;
		char* str = new char[stringLen] {'\0'};
		str[0] = '[';
		str[stringLen - 2] = ']';
		str[stringLen - 1] = '\0';
		int arrayIndex = 1;
		for (int i = 0; i < size; i++) {
			int n = array[i];
			int number = 0;
			while (n) {
				number++;
				n /= 10;
			}
			int* temp = new int[number];
			n = array[i];
			for (int i = 0; n; i++) {
				temp[i] = (n % 10) + '0';
				n /= 10;
			}
			for (int i = number - 1; i >= 0; i--) {
				str[arrayIndex] = temp[i];
				arrayIndex++;

			}
			if (arrayIndex != stringLen - 2) {
				str[arrayIndex] = ',';
				arrayIndex++;
			}
			delete[] temp;
		}
		return str;
	}

ostream& operator<<(ostream& out, int* arr1) {

	out << arr.toString(arr1);
	out << endl;
	return out;
}