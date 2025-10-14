#include "Point.h"
#include "helpers.h"



void Point::print() const { // virtual allows us to change the behaviour in the function on which it is used
	cout << "X: " << pointX << " Y: " << pointY;
}

// d = sqrt((x2 - x1)^2 + (y2 - y1)^2)

float Point::findDistanceBetween2Points(Point point2) {
	float distance = sqrt(pow((point2.pointX - pointX), 2) + pow((point2.pointY - pointY), 2));

	return distance;
}

void Point::writeInFile(string& filename) {
	int offsetY = calculateFileOffsetY(filename);

	if (offsetY >= 5) {
		ofstream ofs;
		ofs.open(filename, ofstream::out | ofstream::trunc);
		ofs.close();
	}

	ofstream fileIn(filename, fstream::app);

	if (fileIn.is_open()) {
		fileIn << pointX << endl;
		fileIn << pointY << endl;
	}
}

void Point::readFromFile(string& filename, bool isPointLeft = true) {
	ifstream file(filename);
	int temp;

	if (file.is_open()) {

		if (isPointLeft) {
			file >> pointX;
			file >> pointY;
		}
		else {
			// read unused values
			file >> temp;
			file >> temp;

			file >> pointX;
			file >> pointY;

		}
	}
}

Point::Point() {
	pointX = 0;
	pointY = 0;
}

Point::Point(float x, float y) {
	this->pointX = x;
	this->pointY = y;
}

