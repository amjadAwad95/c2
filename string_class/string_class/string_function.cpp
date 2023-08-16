#include"String.h"
#include<string.h>
//get the lenth of char
int String:: lenth(const char* s) {
	int len;
	for (len = 0; s[len]; len++);
	return len;
}
//copy char2 to char1
void String::copyCharToMyString(char* s1, const char* s2) {
	while (*s1++ = *s2++);
}
//defult constructor
String::String() {
		str = NULL;
	}
//constructor with parameter
String::String(const char* s) {
		str = NULL;
		setString(s);
	}
//copy constructor
String::String(const String& sour) {
	setString(sour.str);
	}
//= operator
	String String:: operator =(const String& s) {
		//copyCharToMyString(this->str, s.str);
		if (str) {
			delete[] str;
		}
		str = new char[strlen(s.str) + 1];
		strcpy_s(this->str, strlen(s.str) + 1, s.str);
		return *this;
	}
//cout operator
	ostream&  operator << (ostream& out, const String& s) {
		out << s.str;
		return out;
	}
//cin operator
	istream& operator >>(istream& in, String& s) {
		if (s.str) {
			delete[] s.str;
		}
		char* buff = new char[10000];
		in >> buff;
		s.str = new char[strlen(s.str) + 1];
		strcpy_s(s.str, strlen(s.str) + 1, buff);
		delete buff;
		return in;
	}
//== operator
	bool operator ==(const String& s1, const String& s2) {
		int s1Len = s1.lenth();
		int s2Len = s2.lenth();
		if (s1Len != s2Len) {
			return false;
		}
		int counter=0;
		for (counter = 0; s1.str[counter] == s2.str[counter] && s1.str[counter]; counter++);
		if (counter == s1Len) {
			return true;
		}
		return false;
	}
	//operator +
	String String:: operator +(const String& sur) {
		int len = lenth(this->str) + lenth(sur.str);
		char* newString = new char[len + 1] {'\0'};
		copyCharToMyString(newString, this->str);
		catCharToMyString(newString, sur.str);
		if (this->str) {
			delete[] this->str;
		}
		this->str = newString;
		return *this;
	}
	//operator []
	char String:: operator[](int number){
		int stringLen = lenth(this->str);
		if (number > stringLen || number < 0) {
			exit(1);
		}
		return this->str[number];
	}
//set  string get char* and put it in my str
	void String::setString(const char* s) {
		if (str) {
			delete[]str;
		}
5		str = new char[strlen(s) + 1];
		copyCharToMyString(str, s);
	}
//get my str
	char* String::getString() const {
		return str;
	}
//lenth function
	int String:: lenth() const {
		int len=0;
		for (len = 0; str[len]; len++);
		return len;
	}
//destructor
	String::~String() {
		if(str)
		delete[] str;
		str = NULL;
	}

	void copy(char* s1, const char* s2) {
		while (*s1++ = *s2++);
	}
	void String:: catCharToMyString(char* s1, const char* s2) {
		while (*s1) {
			s1++;
		}
		while (*s1++ = *s2++);
	}