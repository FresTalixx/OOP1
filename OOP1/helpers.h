#pragma once
#include <iostream>
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"
#include "Circle.h"

using namespace std;

int calculateFileOffsetY(string filename);

Shape* selectShapeType();

