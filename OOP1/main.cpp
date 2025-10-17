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

#define FILENAME "shapes.txt"

using namespace std;



int main()
{
	int shapeSize = 0;
	Shape** shapes =  nullptr;
	const int menuSize = 9;

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
	Shape* maxSquareShape;
	Shape* minSquareShape;
	Shape* maxPerimeterShape;

	bool running = true;

	while (running) {
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
			manager.addShape(newShape);

			break;
		case 2:
			manager.printShapeArray();

			SetCursorPosition(15, 11 + manager.getShapesSize() + 2); // valid offset
			ShowConsoleCursor(true);
			cout << "Enter an index of shape to delete"; cin >> deleteIndex;
			ShowConsoleCursor(false);

			manager.deleteShape(deleteIndex - 1); // proper offset
			break;
		case 3:
			manager.printShapeArray();

			ShowConsoleCursor(true);
			cin.get();
			ShowConsoleCursor(false);
			break;
		case 4:
			maxSquareShape = manager.findShapeWithMaxSquare();
			maxSquareShape->print();

			ShowConsoleCursor(true);
			cin.get();
			ShowConsoleCursor(false);
			break;
		case 5:
			maxPerimeterShape = manager.findShapeWithMaxPerimeter();
			maxPerimeterShape->print();

			ShowConsoleCursor(true);
			cin.get();
			ShowConsoleCursor(false);
			break;

		case 6:
			minSquareShape = manager.findShapeWithMinSquare();
			minSquareShape->print();

			ShowConsoleCursor(true);
			cin.get();
			ShowConsoleCursor(false);
			break;
		case 7:
			manager.writeToFile(FILENAME);
			break;
		case 8:
			manager.loadFromFile(FILENAME);
			break;
		case 9:
			running = false;
			break;
		}
		

		
		
		
	}


	
		


}