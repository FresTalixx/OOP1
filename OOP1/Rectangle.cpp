#include <iostream>
#include "Rectangle.h"

using namespace std;

MyRectangle::MyRectangle() {
	leftX = 0;
	leftY = 0;
	rightX = 3;
	rightY = 2;
}

MyRectangle::MyRectangle(float leftX, float leftY, float rightX, float rightY) {
	this->leftX = leftX;
	this->leftY = leftY;
	this->rightX = rightX;
	this->rightY = rightY;
}

float MyRectangle::calculateSquare() {
	return (rightY - leftY) * (rightX - leftX);
}

float MyRectangle::calculatePerimeter() {
	return 2 * (rightY - leftY + rightX - leftX);
}

void MyRectangle::print() const {
	cout << "Rectangle: " << endl;
	cout << "Left Bottom: " << leftX << " " << leftY << " " << endl;
	cout << "Left Top: " << leftX << " " << rightY << " " << endl;
	cout << "Right Top: " << rightX << " " << rightY << " " << endl;
	cout << "Right Bottom: " << rightX << " " << leftY << " " << endl;

}

Shape* MyRectangle::inputFromConsole() {
	float leftX, leftY, rightX, rightY;
	cout << "Enter left bottom point (x y): ";
	cin >> leftX >> leftY;
	cout << "Enter right top point (x y): ";
	cin >> rightX >> rightY;
	return new MyRectangle(leftX, leftY, rightX, rightY);
}