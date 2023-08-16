#pragma once
#include<iostream>
#include<string>

using namespace std;

class Person {
protected:
	string name;
	int id;
	int age;
	static int personCount;
public:
	Person(string name=" ",int id=0,int age=0) {
		this->name = name;
		this->age = age;
		this->id = id;
		personCount++;
	}
	void setName(const string& name) {
		this->name = name;
	}
	void setAge(const int& age) {
		this->age = age;
	}
	void setId(const int& id) {
		this->id = id;
	}
	void setAllInformation(const string& name,const int& id, const int& age) {
		this->name = name;
		this->age = age;
		this->id = id;
	}
	string getName()const {
		return this->name;
	}
	int getAge() const{
		return this->age;
	}
	int getId()const {
		return this->id;
	}
	static int getPersonCount() {
		return personCount;
	}
	string toString() const{
		string str;
		str += "My name is ";
		str += name;
		str += " and my age is ";
		str += to_string(age);
		str += " and my ID is ";
		str += to_string(id);
		return str;
	}
};
int Person::personCount = 0;