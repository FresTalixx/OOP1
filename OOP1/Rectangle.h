#pragma once
#include "Shape.h"
#include <iostream>

using namespace std;

class MyRectangle : public Shape {
protected:
	Point left;
	Point right;


public:

	Point getRight() const {
		return right;
	}

	Point getLeft() const {
		return left;
	}


	void setLeft(float x, float y) {
		left.setX(x);
		left.setY(y);
	}

	void setRight(float x, float y) {
		right.setX(x);
		right.setY(y);
	}


	MyRectangle();

	MyRectangle(Point X, Point Y);


	float calculatePerimeter();

	float calculateSquare();

	void print() const override;

	Shape* inputFromConsole();

	virtual void writeToFile(string filename);
	virtual Shape* loadFromFile(ifstream& file);

	string getType() const {
		return "Rectangle";
	}

	Shape* clone() override {
		return new MyRectangle(*this);
	}
};
