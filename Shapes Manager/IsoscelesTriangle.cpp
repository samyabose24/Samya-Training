#include "IsoscelesTriangle.h"

void IsoscelesTriangle::calculateArea() {
    area = length * breadth / 2;
}

std::string IsoscelesTriangle::getType() {
    return "Isosceles Triangle";
}