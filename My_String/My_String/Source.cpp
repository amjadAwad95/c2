#include<iostream>
#include<string.h>

using namespace std;

class String {
private:
	char* str;
public:
	String() {
		str = NULL;
	}
	String(const char* s) {
		int charLen = strlen(s);
		str = new char[charLen + 1];
		strcpy_s(str, charLen + 1, s);
	}
	String(const String& s) {
		int charLen = strlen(s.str);
		str = new char[charLen + 1];
		strcpy_s(str, charLen + 1, s.str);
	}
	~String() {
		if (str) {
			delete[] str;
		}
		str = NULL;
	}
	String operator =(const String& s) {
		if (str && s.str ) {
			delete[] str;
		}
		int charLen = strlen(s.str);
		str = new char[charLen + 1];
		strcpy_s(str, charLen + 1, s.str);
		return *this;
	}
	bool operator==(const String& s) {
		if (strcmp(str, s.str) == 0) {
			return true;
		}
		return false;
	}
	bool operator!=(const String& s) {
		if (strcmp(str, s.str) != 0) {
			return true;
		}
		return false;
	}
	char operator[](int number) {
		int charLen = strlen(this->str);
		if (number<0 || number>charLen ) {
			exit(1);
		}
		return this->str[number];
	}
	String operator +(const String& s) {
		String temp;
		int lenth = strlen(this->str) + strlen(s.str) + 1;
		temp.str = new char[lenth];
		strcpy_s(temp.str, lenth, this->str);
		strcat_s(temp.str, lenth, s.str);
		return temp;
	}
	String& operator+=(const String& s) {
		*this = *this + s;
		return *this;
	}
	String operator-(const char c) {
		int counter = 0;
		for (int i = 0; this->str[i]; i++) {
			if (this->str[i] == c) {
				counter++;
			}
		}
		char* temp = new char[(strlen(this->str) - counter) + 1];
		int k = 0;
		for (int i = 0; this->str[i]; i++) {
			if (this->str[i] != c) {
				temp[k] = this->str[i];
				k++;
			}
		}
		temp[k] = '\0';
		return temp;
	}
	String operator -(const String& s) {
		int counter = 0;
		for (int i = 0; this->str[i]; i++) {
			if (this->str[i] == s.str[0]) {
				int j=1;
				for (int k=i+1; s.str[j]; j++,k++) {
					if (this->str[k] != s.str[j]) {
						break;
					}
				}
				if (j == strlen(s.str)) {
					counter++;
				}
			}
		}
		int sLen = strlen(s.str)*counter;
		char* temp = new char[(strlen(this->str) - sLen) + 1];
		int c = 0;
		for (int i = 0; this->str[i]; i++) {
			if (this->str[i] == s.str[0]) {
				i++;
				for (int j = 1, k = i + 1; s.str[j]; j++, k++) {
					if (this->str[k-1] != s.str[j]) {
						i--;
						break;
					}
					else {
						i++;
					}
				}
			}
			temp[c] = this->str[i];
			c++;
		}
		temp[c] = '\0';
		return temp;
	}
	String& operator -=(const char& c) {
		*this = *this - c;
		return *this;
	}
	String& operator -=(const String & s) {
		*this = *this - s;
		return *this;
	}
	friend ostream& operator <<(ostream& out, const String& s) {
		out << s.str;
		return out;
	}
	friend istream& operator>>(istream& in, String& s) {
		if (s.str) {
			delete[] s.str;
		}
		char temp[100000];
		in >> temp;
		s.str = new char[strlen(temp) + 1];
		strcpy_s(s.str, strlen(temp) + 1, temp);
		return in;
	}
	int length() {
		if (this->str) {
			return strlen(this->str);
		}
		return 0;
	}

};

int main() {
	String name = "amjad";
	String n = "awad";
	String fullName = "amjad awad";
	fullName -= "am";
	cout << fullName << endl;
	name -= 'd';
	cout << name << endl;
	cout << fullName.length() << endl;
	String nb;
	cout << nb.length() << endl;
}