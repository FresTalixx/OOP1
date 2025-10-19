#include "Square.h"

Square::Square() {
	left = Point(0, 0);
	right = Point(2, 3);
}

Square::Square(Point left, Point right) {
	this->left = left;
	this->right = right;
}

float Square::calculatePerimeter() {
	float side = right.getY() - left.getY();
	return 4 * side;
}

float Square::calculateSquare() {
	float side = right.getY() - left.getY();
	return side * side;
}

void Square::print(ostream& os) const {
	os << "Square: ";
	os << "Left Bottom: " << left.getX() << " " << left.getY() << " " << endl;
	os << "Left Top: " << left.getX() << " " << right.getY() << " " << endl;
	os << "Right Top: " << right.getX() << " " << right.getY() << " " << endl;
	os << "Right Bottom: " << right.getX() << " " << left.getY() << " " << endl;
}

Shape* Square::inputFromConsole() {
	float leftX, leftY, rightX, rightY;
	cout << "Enter left bottom point (x y): ";
	cin >> leftX >> leftY;
	cout << "Enter right top point (x y): ";
	cin >> rightX >> rightY;
	return new Square(Point(leftX, leftY), Point(rightX, rightY));
}

void Square::writeToFile(string filename) {
	ofstream file(filename, ios::app);
	if (file.is_open()) {
		file << "Square" << endl;
		file << left.getX() << " ";
		file << left.getY() << " ";
		file << right.getX() << " ";
		file << right.getY() << " ";
		file << "\n";

	}
}

Shape* Square::loadFromFile(ifstream& file) {
	float lx, ly, rx, ry;
	file >> lx >> ly >> rx >> ry;
	return new Square(Point(lx, ly), Point(rx, ry));

}