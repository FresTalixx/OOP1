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

	static int circlesDeleted;
	static int rectanglesDeleted;
	static int triangleDeleted;
	static int squaresDeleted;

public:

	static int getTotalShapesCreated() {
		return ShapeManager::totalShapesCreated;
	}

	static int getCirclesDeleted() {
		return ShapeManager::circlesDeleted;
	}
	static int getRectanglesDeleted() {
		return ShapeManager::rectanglesDeleted;
	}
	static int getTrianglesDeleted() {
		return ShapeManager::triangleDeleted;
	}
	static int getSquaresDeleted() {
		return ShapeManager::squaresDeleted;
	}

	ShapeManager();
	ShapeManager(string filename);
	ShapeManager(const ShapeManager& other);

	void addShape(Shape* newShape);
	void deleteShape(int number);

	void printShapeArray() const;

	static void getDeletedShapesStatistics(Shape* shape);

	Shape* findShapeWithMaxSquare();
	Shape* findShapeWithMinSquare();
	Shape* findShapeWithMaxPerimeter();

	void writeToFile(string filename);
	void loadFromFile(string filename);

	friend ostream& operator<<(ostream& os, const ShapeManager& manager) {
		for (int i = 0; i < manager.size; ++i) {
			os << (i + 1) << ". ";
			manager.shapes[i]->print(os);
			os << "\n";
		}
		return os;
	}

	~ShapeManager();
};




