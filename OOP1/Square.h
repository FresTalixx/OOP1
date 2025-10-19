#pragma once
#include "Shape.h"
#include <iostream>

using namespace std;

class Square : public Shape {
protected:
	Point left;
	Point right;

public:
	Square();

	Square(Point left, Point right);

	float calculatePerimeter();

	float calculateSquare();

	void print(ostream& os) const;

	Shape* inputFromConsole();

	void writeToFile(string filename);
	Shape* loadFromFile(ifstream& file);

	string getType() const {
		return "Square";
	}

	Shape* clone() override {
		return new Square(*this);
	}
};
