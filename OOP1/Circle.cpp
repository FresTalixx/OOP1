#include "Circle.h"

Circle::Circle() {
	centerPoint = Point(1, 1);
	circlePoint = Point(0, 0);
}

Circle::Circle(Point centerPoint, Point circlePoint) {
	this->centerPoint = centerPoint;
	this->circlePoint = circlePoint;
}

float Circle::calculatePerimeter() {
	return M_PI * 2 * radius;
}

float Circle::calculateSquare() {
	return M_PI * radius * radius;
}

void Circle::print() const {
	cout << "Circle: " << endl;
	cout << "Center Point: " << centerPoint.getX() << " " << centerPoint.getY() << endl;
	cout << "Circle Point: " << circlePoint.getX() << " " << circlePoint.getY() << endl;
}

Shape* Circle::inputFromConsole() {
	Point centerPoint = fromConsole("center");
	Point circlePoint = fromConsole("circle");
	return new Circle(centerPoint, circlePoint);
}

