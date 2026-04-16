#include "Triangle.h"
#include <iostream>

void Triangle::setLength(double l) { length = l; }
void Triangle::setBreadth(double b) { breadth = b; }
void Triangle::calculateArea() { area = length * breadth * 0.5; }
void Triangle::printArea() { std::cout << "Area: " << area << std::endl; }
std::string Triangle::getType() { return "Triangle"; }

// Additional work
std::string EquilateralTriangle::getType() { return "Equilateral Triangle"; }
std::string IsoscelesTriangle::getType() { return "Isosceles Triangle"; }
std::string ScaleneTriangle::getType() { return "Scalene Triangle"; }