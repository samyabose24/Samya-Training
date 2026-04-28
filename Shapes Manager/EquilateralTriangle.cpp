#include "EquilateralTriangle.h"
#include <cmath>

void EquilateralTriangle::calculateArea() {
    area = (sqrt(3) / 4) * length * length;
}

std::string EquilateralTriangle::getType() {
    return "Equilateral Triangle";
}