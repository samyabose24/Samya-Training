#ifndef SCALENETRIANGLE_H
#define SCALENETRIANGLE_H

#include "Triangle.h"

class ScaleneTriangle : public Triangle {
public:
    void calculateArea() override;
    std::string getType() override;
};

#endif