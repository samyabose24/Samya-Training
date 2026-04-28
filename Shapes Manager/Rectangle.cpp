#include "Rectangle.h"
#include <iostream>

void Rectangle::setLength(double l) { length = l; }

void Rectangle::setBreadth(double b) { breadth = b; }

void Rectangle::calculateArea() {
    area = length * breadth;
}

void Rectangle::printArea() {
    std::cout << "Area: " << area << std::endl;
}

std::string Rectangle::getType() {
    return "Rectangle";
}