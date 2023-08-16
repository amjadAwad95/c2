#include<iostream>
#include"Person.h"
#include"Student.h"

using namespace std;

int main() {
	Person p1;
	Student s1("amjad", 1242653, 19, 12217558, 95);
	cout << s1.toString() << endl;
	cout << Student::getStudentCount() << endl;
	cout << Person::getPersonCount() << endl;
}