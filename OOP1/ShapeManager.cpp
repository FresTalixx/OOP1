#include "Shape.h"
#include "ShapeManager.h"
#include <iostream>
#include <fstream>

#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"

using namespace std;

ShapeManager::ShapeManager() {
	shapes = nullptr;
	size = 0;
}

ShapeManager::ShapeManager(string filename) {
	loadFromFile(filename);
}

ShapeManager::~ShapeManager() {
	for (int i = 0; i < size; ++i) {
		delete[] shapes[i];
	}
	delete[] shapes;
}

void ShapeManager::addShape(Shape* newShape) {
	Shape** newShapes = new Shape * [size + 1];
	for (int i = 0; i < size; i++) {
		newShapes[i] = shapes[i];
	}
	newShapes[size] = newShape;
	delete[] shapes;
	shapes = newShapes;
	size++;
}


void ShapeManager::deleteShape(int number) {
	delete shapes[number];

	Shape** newShapes = new Shape * [size - 1];
	int j = 0;
	for (int i = 0; i < size; i++) {
		if (i == number) {
			j++;
			continue;
		}
		newShapes[i - j] = shapes[i];
	}

	delete[] shapes;
	shapes = newShapes;
	size--;
}

void ShapeManager::printShapeArray() const {
	for (int i = 0; i < size; i++) {
		cout << i + 1 << " ";
		shapes[i]->print();
		cout << "\n";
	}
}

Shape* ShapeManager::findShapeWithMinSquare() {
	float smallestSquare = shapes[0]->calculateSquare();
	Shape* smallestSquareShape = shapes[0];
	for (int i = 1; i < size; ++i) {
		if (shapes[i]->calculateSquare() < smallestSquare) {
			smallestSquareShape = shapes[i];
			smallestSquare = shapes[i]->calculateSquare();
		}
	}

	return smallestSquareShape;
}

Shape* ShapeManager::findShapeWithMaxSquare() {
	float biggestSquare = shapes[0]->calculateSquare();
	Shape* biggestSquareShape = shapes[0];
	for (int i = 0; i < size; ++i) {
		if (shapes[i]->calculateSquare() > biggestSquare) {
			biggestSquareShape = shapes[i];
			biggestSquare = shapes[i]->calculateSquare();
		}
	}

	return biggestSquareShape;
}

Shape* ShapeManager::findShapeWithMaxPerimeter() {
	float biggestPerimeter = shapes[0]->calculatePerimeter();
	Shape* biggestPerimeterShape = shapes[0];
	for (int i = 0; i < size; ++i) {
		if (shapes[i]->calculatePerimeter() > biggestPerimeter) {
			biggestPerimeterShape = shapes[i];
			biggestPerimeter = shapes[0]->calculatePerimeter();
		}
	}

	return biggestPerimeterShape;
}

void ShapeManager::writeToFile(string filename) {
	ofstream outFile(filename, ios::app);
	if (outFile.is_open()) {
		for (int i = 0; i < size; ++i) {
			shapes[i]->writeToFile(filename);
		}
	}

	outFile.close();
}

void ShapeManager::loadFromFile(string filename) {
	ifstream file(filename);
	if (!file.is_open()) {
		cerr << "Error: cannot open file for reading.\n";
		return;
	}

	// clear old data
	for (int i = 0; i < size; ++i)
		delete shapes[i];
	delete[] shapes;
	shapes = nullptr;
	size = 0;

	// write new shapes
	string type;
	while (file >> type) {
		Shape* shape = nullptr;

		if (type == "Circle") shape = Circle().loadFromFile(file);
		else if (type == "Rectangle") shape = MyRectangle().loadFromFile(file);
		else if (type == "Square") shape = Square().loadFromFile(file);
		else if (type == "Triangle") shape = Triangle().loadFromFile(file);

		if (shape) addShape(shape);
	}

	file.close();
}

