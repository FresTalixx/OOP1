#include "Shape.h"
#include "ShapeManager.h"
#include <iostream>
#include <fstream>

using namespace std;

ShapeManager::ShapeManager() {
	shapes = nullptr;
	size = 0;
}

ShapeManager::ShapeManager(string filename) {
	//loadFromFile();
}

ShapeManager::~ShapeManager() {
	for (int i = 0; i < size; ++i) {
		delete[] shapes[i];
	}
	delete[] shapes;
}

Shape** ShapeManager::addShape(Shape* newShape) {
	Shape** newShapes = new Shape * [size + 1];
	for (int i = 0; i < size; i++) {
		newShapes[i] = shapes[i];
	}
	newShapes[size] = newShape;
	size++;
	delete[] shapes;
	return newShapes;
}

Shape** ShapeManager::deleteShape(int number) {
	Shape** newShapes = new Shape * [size - 1];
	int j = 0;
	for (int i = 0; i < size; i++) {
		if (i == number) {
			j++;
			continue;
		}
		newShapes[i - j] = shapes[i];
	}

	size--;
	delete[] shapes;
	return newShapes;
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
		if (shapes[i]->calculateSquare() > biggestPerimeter) {
			biggestPerimeterShape = shapes[i];
			biggestPerimeter = shapes[0]->calculatePerimeter();
		}
	}

	return biggestPerimeterShape;
}

void ShapeManager::writeToFile(string filename) {
	ofstream file(filename);
	if (file.is_open()) {

	}
}