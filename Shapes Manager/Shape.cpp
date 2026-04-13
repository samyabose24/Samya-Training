#include "Shape.h"

Shape::Shape() : name("Unknown"), length(0), breadth(0) {}

void Shape::setName(std::string n) { name = n; }
std::string Shape::getName() { return name;}