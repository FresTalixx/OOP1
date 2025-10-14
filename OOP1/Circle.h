#pragma once
#include "Shape.h"
#include "Point.h"

class Circle : public Shape {
private:
	Point centerPoint;
	Point circlePoint;
	float radius = centerPoint.findDistanceBetween2Points(circlePoint);

public:
	Circle();

	Circle(Point centerPoint, Point circlePoint);


	float calculatePerimeter();

	float calculateSquare();

	void print() const;

	Shape* inputFromConsole();
};
