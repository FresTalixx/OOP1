#pragma once
#include "Shape.h"
#include <iostream>

using namespace std;

class MyRectangle : public Shape {
protected:
	float leftX;
	float rightX;
	float rightY;
	float leftY;


public:

	float getLeftX() const {
		return this->leftX;
	}

	float getLeftY() const {
		return this->leftY;
	}

	float getRightX() const {
		return this->rightX;
	}

	float getRightY() const {
		return this->rightY;
	}


	void setLeftX(float value) {
		this->leftX = value;
	}

	void setLeftY(float value) {
		this->leftY = value;
	}

	void getRightX(float value) {
		this->rightX = value;
	}

	void getRightY(float value) {
		this->rightY = value;
	}


	MyRectangle();

	MyRectangle(float leftX, float leftY, float rightX, float rightY);


	float calculatePerimeter();

	float calculateSquare();

	void print() const override;

	Shape* inputFromConsole();
};
