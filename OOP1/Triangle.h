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

	void print(ostream& os) const;

	Shape* inputFromConsole();

	void writeToFile(string filename);
	Shape* loadFromFile(ifstream& file);

	string getType() const {
		return "Triangle";
	}

	Shape* clone() override {
		return new Triangle(*this);
	}
};
