#include <iostream>
#include <string>
#include "Rectangle.h"

using namespace std;

MyRectangle::MyRectangle() {
	left = Point(0, 0);
	right = Point(2, 3);
}

MyRectangle::MyRectangle(Point left, Point right) {
	this->left = left;
	this->right = right;
}

float MyRectangle::calculateSquare() {
	return (right.getY() - left.getY()) * (right.getX() - left.getX());
}

float MyRectangle::calculatePerimeter() {
	return 2 * (right.getY() - left.getY() + right.getX() - left.getX());
}

void MyRectangle::print() const {
	cout << "Rectangle: " << endl;
	cout << "Left Bottom: " << left.getX() << " " << left.getY() << " " << endl;
	cout << "Left Top: " << left.getX() << " " << right.getY() << " " << endl;
	cout << "Right Top: " << right.getX() << " " << right.getY() << " " << endl;
	cout << "Right Bottom: " << right.getX() << " " << left.getY() << " " << endl;

}

Shape* MyRectangle::inputFromConsole() {
	float leftX, leftY, rightX, rightY;
	cout << "Enter left bottom point (x y): ";
	cin >> leftX >> leftY;
	cout << "Enter right top point (x y): ";
	cin >> rightX >> rightY;
	return new MyRectangle(Point(leftX, leftY), Point(rightX, rightY));
}

void MyRectangle::writeToFile(string filename) {
	ofstream file(filename, ios::app); 
	if (file.is_open()) {
		file << "Rectangle" << endl;
		file << left.getX() << " ";
		file << left.getY() << " ";
		file << right.getX() << " ";
		file << right.getY() << " ";
		file << "\n";

	}
}
Shape* MyRectangle::loadFromFile(ifstream& file) {
	float lx, ly, rx, ry;
	file >> lx >> ly >> rx >> ry;
	return new MyRectangle(Point(lx, ly), Point(rx, ry));

}