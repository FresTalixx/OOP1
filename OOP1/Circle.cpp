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

void Circle::print(ostream& os) const {
	os << "Circle: " << endl;
	os << "Center Point: " << centerPoint.getX() << " " << centerPoint.getY() << endl;
	os << "Circle Point: " << circlePoint.getX() << " " << circlePoint.getY() << endl;
}

Shape* Circle::inputFromConsole() {
	Point centerPoint = fromConsole("center");
	Point circlePoint = fromConsole("circle");
	return new Circle(centerPoint, circlePoint);
}


void Circle::writeToFile(string filename) {
	ofstream file(filename, ios::app);
	if (file.is_open()) {
		file << "Circle" << endl;
		file << centerPoint.getX() << " ";
		file << centerPoint.getY() << " ";
		file << circlePoint.getX() << " ";
		file << circlePoint.getY() << " ";
		file << "\n";

	}
}
Shape* Circle::loadFromFile(ifstream& file) {
	float centerX, centerY, circleX, circleY;
	file >> centerX >> centerY >> circleX >> circleY;
	return new Circle(Point(centerX, centerY), Point(circleX, circleY));
}