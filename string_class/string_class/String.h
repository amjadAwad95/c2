#pragma once
#include<iostream>
using namespace std;
class String {
private:
	char* str;
	int lenth(const char* s);
	void copyCharToMyString(char* s1, const char* s2);
	void catCharToMyString(char* s1, const char* s2);
public:
	String();
	String(const char* s);
	String(const String& sour);
	String operator =(const String& s);
	friend ostream& operator <<(ostream& out, const String& s);
	friend istream& operator >>(istream& in, String& s);
	friend bool operator ==(const String& s1, const String& s2);
	String operator +(const String& sur);
	char operator[](int number);
	void setString(const char* s);
	char* getString() const;
	int lenth() const;
	~String();
};
