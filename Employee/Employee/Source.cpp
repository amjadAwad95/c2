#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class Employee {
private:
    string name;
    int ID;
    float salary;
public:
    Employee() {
        name = "";
        ID = 0;
        salary = 0;
    }
    Employee(string name, int id, float salary) {
        this->name = name;
        this->ID = id;
        this->salary = salary;
    }
    void setName(string name) {
        this->name = name;
    }
    void setId(int id) {
        this->ID = id;
    }
    void setSalary(float salary) {
        this->salary = salary;
    }
    void setEmployee(string name, int id, float salary) {
        this->name = name;
        this->ID = id;
        this->salary = salary;
    }
    string getName() const {
        return this->name;
    }
    float getSalary()const {
        return this->salary;
    }
    int getId()const {
        return this->ID;
    }
    float getAnnoSalary() const {
        return this->salary * 12;
    }
    string toString() const {
        stringstream ss;
        ss << "Employee{name=" << name << ", ID=" << ID << ", salary=" << salary << "}";
        return ss.str();
    }
};

int main() {
    Employee e("amjad", 12217558, 5000.545);
    string str = e.toString();
    cout << str << endl;
}