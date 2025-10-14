#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

#include "Point.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"
#include "Triangle.h"

#include "ShapeManager.h"
#include "keyboardMenuControll.h"
#include "helpers.h"

using namespace std;



int main()
{
	int shapeSize = 3;
	Shape** shapes =  new Shape*[shapeSize];
	const int menuSize = 9;

	shapes[0] = new MyRectangle();
	shapes[1] = new Circle();
	shapes[2] = new Triangle();

	ShapeManager manager;
	manager.setShapes(shapes);
	manager.setShapesSize(shapeSize);

	const char* menu[menuSize]{
		"Add shape",
		"Delete",
		"Print shapes",
		"Look for shape with the biggest square",
		"Look for shape with the biggest perimeter",
		"Look for shape with the smallest square",
		"Save to file",
		"Load from file",
		"Exit"
	};

	while (true) {
		system("cls");
		int choice = menuControl(menu, menuSize);

		SetCursorPosition(0, 11);

		Shape* newShape = nullptr;

		switch (choice) {
		case 1:
			newShape = selectShapeType();

			newShape = newShape->inputFromConsole();

			manager.setShapes(manager.addShape(newShape));
			break;
		case 3:
			manager.printShapeArray();
			cin.get();
			break;
		}
	}
	
		


}