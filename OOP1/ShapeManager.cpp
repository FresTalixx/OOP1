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

Shape* ShapeManager::findShapeWithMixSquare() {
	float smallestSquare = 0;
	Shape* smallestSquareShape = shapes[0];
	for (int i = 0; i < size; ++i) {
		if (shapes[i]->calculateSquare() < smallestSquare) {
			smallestSquareShape = shapes[i];
		}
	}

	return smallestSquareShape;
}

Shape* ShapeManager::findShapeWithMaxSquare() {
	float biggestSquare = 0;
	Shape* biggestSquareShape = shapes[0];
	for (int i = 0; i < size; ++i) {
		if (shapes[i]->calculateSquare() > biggestSquare) {
			biggestSquareShape = shapes[i];
		}
	}

	return biggestSquareShape;
}

Shape* ShapeManager::findShapeWithMaxPerimeter() {
	float biggestPerimeter = 0;
	Shape* biggestPerimeterShape = shapes[0];
	for (int i = 0; i < size; ++i) {
		if (shapes[i]->calculateSquare() > biggestPerimeter) {
			biggestPerimeterShape = shapes[i];
		}
	}

	return biggestPerimeterShape;
}