#pragma once
#include"Person.h"

class Student :public Person {
protected:
	int mark;
	int studentId;
	static int studentCount;
public:
	Student(int mark = 0, int studentId = 0):Person("no name", 0, 0) {
		this->mark = mark;
		this->studentId = studentId;
		studentCount++;
	}
	Student(string name, int id, int age, int studentId) :
		Person(name, id, age) {
		this->mark = 0;
		this->studentId = studentId;
		studentCount++;
	}
	Student(string name, int id, int age, int studentId, int mark) :
		Person(name, id, age) {
		this->mark = mark;
		this->studentId = studentId;
		studentCount++;
	}
	void setMark(const int& mark) {
		this->mark = mark;
	}
	void setStudentId(const int& studentId) {
		this->studentId = studentId;
	}
	int getMark()const {
		return this->mark;
	}
	int getStudentId()const {
		return this->studentId;
	}
	static int getStudentCount() {
		return studentCount;
	}
	string toString()const {
		string str;
		str += "My name is ";
		str += name;
		str += " and my age is ";
		str += to_string(age);
		str += " and my ID is ";
		str += to_string(id);
		str += " and I`am student my student id is ";
		str += to_string(studentId);
		str += " and my mark is ";
		str += to_string(mark);
		return str;
	}
};
int Student::studentCount = 0;