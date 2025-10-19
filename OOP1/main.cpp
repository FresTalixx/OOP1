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
#define FILENAME2 "shapes2.txt"

using namespace std;

int main()
{
	//int shapeSize = 0;
	//Shape** shapes =  nullptr;
	const int menuSize = 11;

	ShapeManager manager;
	ShapeManager manager2;

	manager2 = manager;
	/*manager.setShapes(shapes);
	manager.setShapesSize(shapeSize);*/

	const char* menu[menuSize]{
		"Add shape",
		"Delete shape",
		"Print shapes",
		"Look for shape with the biggest square",
		"Look for shape with the biggest perimeter",
		"Look for shape with the smallest square",
		"Save to file",
		"Load from file",
		"Shapes info",
		"Switch manager",
		"Exit"
	};

	Shape* newShape = nullptr;
	Shape* maxSquareShape;
	Shape* minSquareShape;
	Shape* maxPerimeterShape;

	bool running = true;
	int activeManager = 1;

	while (running) {
		system("cls");
		if (activeManager == 1) {
			cout << "Active manager: 1" << endl;
		}
		else if (activeManager == 2) {
			cout << "Active manager: 2" << endl;
		}
		int choice = menuControl(menu, menuSize, 0, 1);

		SetCursorPosition(0, 13);
		
		int deleteIndex;

		switch (choice) {
		case 1:
			ShowConsoleCursor(true);
			newShape = selectShapeType();
			newShape = newShape->inputFromConsole();
			ShowConsoleCursor(false);

			if ((activeManager == 1)) {
				manager.addShape(newShape);
			}
			else if ((activeManager == 2)) {
				manager2.addShape(newShape);
			}

			break;
		case 2:
			SetCursorPosition(15, 16); // valid offset
			ShowConsoleCursor(true);
			cout << "Enter an index of shape to delete: "; cin >> deleteIndex;
			ShowConsoleCursor(false);

			if ((activeManager == 1)) {
				manager.printShapeArray();
				manager.deleteShape(deleteIndex - 1); // proper offset
			}
			else if ((activeManager == 2)) {
				manager2.printShapeArray();
				manager2.deleteShape(deleteIndex - 1); // proper offset
			}
			break;
		case 3:
			if ((activeManager == 1))
				manager.printShapeArray();
			else if ((activeManager == 2))
				manager2.printShapeArray();

			ShowConsoleCursor(true);
			cin.get();
			ShowConsoleCursor(false);
			break;
		case 4:
			if ((activeManager == 1)) {
				maxSquareShape = manager.findShapeWithMaxSquare();
				maxSquareShape->print();
			}
			else  if (activeManager == 2){
				maxSquareShape = manager2.findShapeWithMaxSquare();
				maxSquareShape->print();
			}
			
			ShowConsoleCursor(true);
			cin.get();
			ShowConsoleCursor(false);
			break;
		case 5:
			if ((activeManager == 1)) {
				maxPerimeterShape = manager.findShapeWithMaxPerimeter();
				maxPerimeterShape->print();
			}
			else if ((activeManager == 2)){
				maxPerimeterShape = manager2.findShapeWithMaxPerimeter();
				maxPerimeterShape->print();
			}
			
			ShowConsoleCursor(true);
			cin.get();
			ShowConsoleCursor(false);
			break;

		case 6:
			if ((activeManager == 1)) {
				minSquareShape = manager.findShapeWithMinSquare();
				minSquareShape->print();
			}
			else if (activeManager == 2) {
				minSquareShape = manager2.findShapeWithMinSquare();
				minSquareShape->print();
			}
			
			ShowConsoleCursor(true);
			cin.get();
			ShowConsoleCursor(false);
			break;
		case 7:
			if ((activeManager == 1)) {
				manager.writeToFile(FILENAME);
			}
			else if (activeManager == 2) {
				manager2.writeToFile(FILENAME2);
			}
			break;
		case 8:
			if ((activeManager == 1)) {
				manager.loadFromFile(FILENAME);
			}
			else if (activeManager == 2) {
				manager.loadFromFile(FILENAME2);
			}
			break;
		case 9:
			if ((activeManager == 1)) {
				cout << "Active manager: 1" << endl;
			}
			else if (activeManager == 2) {
				cout << "Active manager: 2" << endl;
			}
			cout << "Total shapes created: " << ShapeManager::getTotalShapesCreated() << endl;
			cout << "Deleted circle: " << ShapeManager::getCirclesDeleted() << endl;
			cout << "Deleted rectangles: " << ShapeManager::getRectanglesDeleted() << endl;
			cout << "Deleted squares: " << ShapeManager::getSquaresDeleted() << endl;
			cout << "Deleted triangles: " << ShapeManager::getTrianglesDeleted() << endl;
			ShowConsoleCursor(true);
			cin.get();
			ShowConsoleCursor(false);
			break;
		case 10:
			if (activeManager == 1) activeManager = 2;
			else if (activeManager == 2) activeManager = 1;

			break;
		case 11:
			running = false;
			break;
		}
		

		
		
		
	}


	
		


}