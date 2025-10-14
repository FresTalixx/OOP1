#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


class Point {
protected:
	float pointX;
	float pointY;
public:
	float getX() const {
		return pointX;
	}
	void setX(const float pointX) {
		this->pointX = pointX;
	}

	float getY() const {
		return pointY;
	}
	void setY(const float pointY) {
		this->pointY = pointY;
	}


	// d = sqrt((x2 - x1)^2 + (y2 - y1)^2)
	virtual float findDistanceBetween2Points(Point point2);

	// Default constructor
	Point();
	Point(float x, float y);

	void writeInFile(string& filename);
	void readFromFile(string& filename, bool isPointLeft);

	virtual void print() const;
};
