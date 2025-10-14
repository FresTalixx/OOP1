#include <iostream>
#include <fstream>
#include <string>

#include "helpers.h"

using namespace std;

int calculateFileOffsetY(string filename) {
	string temp;
	int count = 0;
	ifstream file(filename);
	while (getline(file, temp)) {
		count++;
	}

	return count + 1; // for correct shifting
}

Shape* selectShapeType() {
    Shape* newShape = nullptr;
    int shapeType;
    cout << "Choose shape type:\n";
    cout << "1. Circle\n";
    cout << "2. Rectangle\n";
    cout << "3. Square\n";
    cout << "4. Triangle\n";
    cin >> shapeType;

    bool isIncorrect = true;

    while (isIncorrect)

        switch (shapeType) {
        case 1:
            newShape = new Circle();
            isIncorrect = false;
            break;
        case 2:
            newShape = new MyRectangle();
            isIncorrect = false;
            break;
        case 3:
            newShape = new Square();
            isIncorrect = false;
            break;
        case 4:
            newShape = new Triangle();
            isIncorrect = false;
            break;
        default:
            cout << "Invalid type!\n";
            continue;
        }

    return newShape;
}