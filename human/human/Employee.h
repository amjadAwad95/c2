#pragma once
#include"Person.h"
class Employee:public Person {
protected:
	int salary;
	int bankAccount;
	static int employeeCount;
public:
	Employee(int salary, int bankAccount) {
		this->salary = salary;
		this->bankAccount = bankAccount;
		employeeCount++;
	}
	Employee(string name, int id, int age, int salary, int bankAccount) :
		Person(name, id, age) {
		this->salary = salary;
		this->bankAccount = bankAccount;
		employeeCount++;
	}
	void setSalary(const int& salary) {
		this->salary = salary;
	}
	void setBankAccount(const int& bankAccount) {
		this->bankAccount = bankAccount;
	}
	int getSalary()const {
		return this->salary;
	}
	int getBankAccount()const {
		return this->bankAccount;
	}
	static int getEmployeeCount() {
		return employeeCount;
	}
};
int Employee::employeeCount = 0;