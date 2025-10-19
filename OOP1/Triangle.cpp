#include "Triangle.h"
#include <iostream>

using namespace std;

Triangle::Triangle() {
	point1 = Point(0, 0);
	point2 = Point(2, 2);
	point3 = Point(0, 4);
}

Triangle::Triangle(Point point1, Point point2, Point point3) {
	this->point1 = point1;
	this->point2 = point2;
	this->point3 = point3;
}

float Triangle::calculatePerimeter() {
	return point1.findDistanceBetween2Points(point2) +
		point2.findDistanceBetween2Points(point3) +
		point3.findDistanceBetween2Points(point1);
}

float Triangle::calculateSquare() {
	float a = point1.findDistanceBetween2Points(point2);
	float b = point2.findDistanceBetween2Points(point3);
	float c = point3.findDistanceBetween2Points(point1);
	float p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

void Triangle::print(ostream& os) const {
	os << "Triangle: " << endl;
	os << "Point 1: " << point1.getX() << " " << point1.getY() << " " << endl;
	os << "Point 2: " << point2.getX() << " " << point2.getY() << " " << endl;
	os << "Point 3: " << point3.getX() << " " << point3.getY() << " " << endl;
}

Shape* Triangle::inputFromConsole() {
	Point point1 = fromConsole("first");
	Point point2 = fromConsole("second");
	Point point3 = fromConsole("third");
	return new Triangle(point1, point2, point3);
}

void Triangle::writeToFile(string filename) {
	ofstream file(filename, ios::app);
	if (file.is_open()) {
		file << "Triangle" << endl;
		file << point1.getX() << " ";
		file << point1.getY() << " ";
		file << point2.getX() << " ";
		file << point2.getY() << " ";
		file << point3.getX() << " ";
		file << point3.getY() << " ";
		file << "\n";

	}
}
Shape* Triangle::loadFromFile(ifstream& file) {
	float p1x, p1y, p2x, p2y, p3x, p3y;
	file >> p1x >> p1y >> p2x >> p2y >> p3x >> p3y;
	return new Triangle(Point(p1x, p1y), Point(p2x, p2y), Point(p3x, p3y));
}