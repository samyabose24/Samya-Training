#include "ScaleneTriangle.h"

void ScaleneTriangle::calculateArea() {
    area = length * breadth * 0.5;
}

std::string ScaleneTriangle::getType() {
    return "Scalene Triangle";
}