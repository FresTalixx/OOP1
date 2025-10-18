#pragma once
#include "Shape.h"
#include "Point.h"
#include <iostream>
class ShapeManager {
private:
	Shape** shapes;
	int size;
	static int totalShapesCreated;
	static int totalShapesDeleted;

public:
	static int getTotalShapesCreated() {
		return ShapeManager::totalShapesCreated;
	}

	ShapeManager();
	ShapeManager(string filename);

	void addShape(Shape* newShape);
	void deleteShape(int number);

	void printShapeArray() const;


	Shape* findShapeWithMaxSquare();
	Shape* findShapeWithMinSquare();
	Shape* findShapeWithMaxPerimeter();

	void writeToFile(string filename);
	void loadFromFile(string filename);

	~ShapeManager();
};

int ShapeManager::totalShapesCreated = 0;
int ShapeManager::totalShapesDeleted = 0;


