#include "Triangle.h"
#include <iostream>

void Triangle::setLength(double l) { length = l; }

void Triangle::setBreadth(double b) { breadth = b; }

void Triangle::calculateArea() {
    area = 0.5 * length * breadth;
}

void Triangle::printArea() {
    std::cout << "Area: " << area << std::endl;
}

std::string Triangle::getType() {
    return "Triangle";
}