#include<iostream>
#include"String.h"

using namespace std;

int main() {
	String name="amjad";
	cout << name<<endl;
	name ="omar";
	cout << name<<endl;
	cout << "Enter your name" << endl;
	cin>> name ;
	String cheak="ok";
	if (cheak == name) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}
	String newS = name + cheak;
	cout << newS << endl;
	cout << newS[3];
	String n;
	cin >> n;
	cout << n << endl;
	String n2222 = String("amjad");
	String n1();
}