#pragma once
#include "Shape.h"
#include "Point.h"
#include <iostream>

using namespace std;

class Triangle : public Shape {
private:
	Point point1;
	Point point2;
	Point point3;

public:
	Triangle();

	Triangle(Point point1, Point point2, Point point3);

	float calculatePerimeter();

	float calculateSquare();

	void print() const;

	Shape* inputFromConsole();


};
