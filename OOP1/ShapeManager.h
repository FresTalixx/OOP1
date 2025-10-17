#pragma once
#include "Shape.h"
#include "Point.h"
#include <iostream>
class ShapeManager {
private:
	Shape** shapes;
	int size;

public:
	Shape** getShapes() const {
		return shapes;
	}

	int getShapesSize() const {
		return size;
	}

	void setShapes(Shape** shapes) {
		this->shapes = shapes;
	}

	void setShapesSize(int size) {
		this->size = size;
	}


	ShapeManager();
	ShapeManager(string filename);

	Shape** addShape(Shape* newShape);
	Shape** deleteShape(int number);

	void printShapeArray() const;


	Shape* findShapeWithMaxSquare();
	Shape* findShapeWithMinSquare();
	Shape* findShapeWithMaxPerimeter();

	

	~ShapeManager();
};


