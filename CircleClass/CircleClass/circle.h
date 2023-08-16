#pragma once
#ifndef circle
#define circle
class Circle {
public:
	//data
	double radius;
	const double PI = 22 / 7.0;
	//operation
	double getDig() {
		return 2 * radius;
	}
	double getArea() {
		return radius * radius * PI;
	}
	double getCirum() {
		return 2 * radius * PI;
	}

};
#endif 

