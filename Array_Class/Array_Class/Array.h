#pragma once
#include<iostream>

using namespace std;

class Array {
private:
	int size;
public:
	Array() {size = 1;}
	Array(int size) {this->size = size;}
	Array(const Array& a) { this->size = a.size; }
	void setSize(int size) { this->size = size; }
	int getSize() const { return this->size; }
	char* toString(int* array);
	friend ostream& operator<<(ostream& out, int* array);

};
Array arr;