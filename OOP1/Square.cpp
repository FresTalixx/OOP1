#include "Square.h"

Square::Square() {
	leftX = 0;
	leftY = 0;
	rightX = 2;
	rightY = 2;
}

Square::Square(float leftX, float leftY, float rightX, float rightY) {
	this->leftX = leftX;
	this->leftY = leftY;
	this->rightX = rightX;
	this->rightY = rightY;
}

float Square::calculatePerimeter() {
	float side = rightY - leftY;
	return 4 * side;
}

float Square::calculateSquare() {
	float side = rightY - leftY;
	return side * side;
}

void Square::print() const {
	cout << "Square: ";
	cout << "Left Bottom: " << leftX << " " << leftY << " ";
	cout << "Left Top: " << leftX << " " << rightY << " " << endl;
	cout << "Right Top: " << rightX << " " << rightY << " ";
	cout << "Right Bottom: " << rightX << " " << leftY << " " << endl;
}

Shape* Square::inputFromConsole() {
	float leftX, leftY, rightX, rightY;
	cout << "Enter left bottom point (x y): ";
	cin >> leftX >> leftY;
	cout << "Enter right top point (x y): ";
	cin >> rightX >> rightY;
	return new Square(leftX, leftY, rightX, rightY);
}