#pragma once

# define M_PI           3.14159265358979323846

#include "Point.h"
#include <iostream>

using namespace std;

// abstract or interface class
class Shape {
protected:
	Point fromConsole(const std::string& pointName) {
		float x, y;
		std::cout << "Enter " << pointName << " point (x y): ";
		std::cin >> x >> y;
		return Point(x, y);
	}
public:
	virtual void print() const = 0; 

	virtual float calculateSquare() = 0;

	virtual float calculatePerimeter() = 0;

	virtual void writeToFile(string filename) = 0;
	virtual Shape* loadFromFile(ifstream& file) = 0;

	virtual Shape* inputFromConsole() = 0;

	virtual string getType() const = 0;

	virtual Shape* clone() = 0;
};
