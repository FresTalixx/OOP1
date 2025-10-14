#pragma once
#include "Shape.h"
#include <iostream>

using namespace std;

class Square : public Shape {
protected:
	float leftX;
	float leftY;
	float rightX;
	float rightY;

public:
	Square();

	Square(float leftX, float leftY, float rightX, float rightY);

	float calculatePerimeter();

	float calculateSquare();

	void print() const;

	Shape* inputFromConsole();


};
