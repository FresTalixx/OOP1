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


	void writeToFile(string filename);
	Shape* loadFromFile(ifstream& file);

	string getType() const {
		return "Circle";
	}

	Shape* clone() override {
		return new Circle(*this);
	}
};

