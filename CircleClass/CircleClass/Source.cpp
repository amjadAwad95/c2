#include<iostream>
#include<fstream>
#include "circle.h"
using namespace std;

int main() {
	fstream circleFile;
	circleFile.open("Text.txt",ios::out);
	if (!circleFile.is_open()) {
		cout << "Error" << endl;
		return 1;
	}
	Circle c;
		cout << "Enter the radius" << endl;
		cin >> c.radius;
		circleFile << "The radius is " << c.radius << endl;
		circleFile << "The diagonal is " << c.getDig() << endl;
		circleFile << "The area is " << c.getArea() << endl;
		circleFile << "The cirum is " << c.getCirum() << endl;
		circleFile << "-------------------------------------" << endl;
	circleFile.close();
	circleFile.open("Text.txt",ios::in);
	if (!circleFile.is_open()) {
		cout << "Error" << endl;
		return 1;
	}
	string a;
	while(circleFile >> a)
		cout << a << endl;

}
