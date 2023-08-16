#include<iostream>

using namespace std;

class MyString {
private:
	char* str;
	//int len; number of char not attribute
public:
	MyString() {//defult constructor
		str = NULL;
		//no return 
	}
	MyString(const char * s) {
		str = NULL;
		setString(s);
	}
	MyString(const MyString& obj) {
		if (obj.str == NULL) {
			str = NULL;  
			return;
		}
		this->str = new char[length(obj.str)+1];
		copy(this->str, obj.str);
	}
	void operator=(MyString obj) {
		cout << "Hello" << endl;
	}
	void setString(const char* s) {
		//str = s;//shallow copy problem
		//deep copy 
		if (str)
			delete[] str;
		str = new char[length(s) + 1];
		

		copy(str, s);
	}
	int length(const char* s) const{
		int len;
		for (len = 0; s[len]; len++);
		return len;
	}
	int length() const{
		int len;
		for (len = 0; str[len]; len++);
		return len;
	}
	void copy(char* s1, const char* s2) {
		while (*s1++ = *s2++);
	}
};

int main() {
	MyString s2("is");
	MyString s3(s2);//copy constructor is called
	MyString a;//defult constructor
	MyString b;//defult constructor
	a = b;//= operator
	MyString c = a;//copy 
}