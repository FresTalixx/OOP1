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
		"Delete shape",
		"Print shapes",
		"Look for shape with the biggest square",
		"Look for shape with the biggest perimeter",
		"Look for shape with the smallest square",
		"Save to file",
		"Load from file",
		"Exit"
	};

	Shape* newShape = nullptr;
	Shape* maxSquareShape = manager.findShapeWithMaxSquare();
	Shape* minSquareShape = manager.findShapeWithMinSquare();
	Shape* maxPerimeterShape = manager.findShapeWithMaxPerimeter();

	while (true) {
		system("cls");
		int choice = menuControl(menu, menuSize);

		SetCursorPosition(0, 11);

		
		int deleteIndex;

		switch (choice) {
		case 1:
			

			ShowConsoleCursor(true);
			newShape = selectShapeType();
			newShape = newShape->inputFromConsole();
			ShowConsoleCursor(false);
			manager.setShapes(manager.addShape(newShape));

			break;
		case 2:
			manager.printShapeArray();

			SetCursorPosition(15, 11 + manager.getShapesSize() + 2); // valid offset
			ShowConsoleCursor(true);
			cout << "Enter an index of shape to delete"; cin >> deleteIndex;
			ShowConsoleCursor(false);

			manager.setShapes(manager.deleteShape(deleteIndex - 1)); // proper offset
			break;
		case 3:
			manager.printShapeArray();

			ShowConsoleCursor(true);
			cin.get();
			ShowConsoleCursor(false);
			break;
		case 4:
			maxSquareShape->print();

			ShowConsoleCursor(true);
			cin.get();
			ShowConsoleCursor(false);
			break;
		case 5:
			maxPerimeterShape->print();

			ShowConsoleCursor(true);
			cin.get();
			ShowConsoleCursor(false);
			break;

		case 6:
			minSquareShape->print();

			ShowConsoleCursor(true);
			cin.get();
			ShowConsoleCursor(false);
			break;
		}
		
	}

	

	for (int i = 0; i < shapeSize; ++i) {
		delete[] shapes[i];
	}
	
		


}