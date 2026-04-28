#include "Shape.h"

// The initializer sets the name as Unknown and the breadth and length as 0
Shape::Shape() : name("Unknown"), length(0), breadth(0) {}

void Shape::setName(std::string n) { name = n; }

std::string Shape::getName() { return name; }