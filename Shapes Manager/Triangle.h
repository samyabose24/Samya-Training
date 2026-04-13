#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"

class Triangle: public Shape {
private:
    double area;
public:
    void setLength(double l) override;
    void setBreadth(double b) override;
    void calculateArea() override;
    void printArea() override;
    std::string getType() override;
};

// Sub Classes of Triangle
class EquilateralTriangle : public Triangle {
public:
    std::string getType() override;
};

class IsoscelesTriangle : public Triangle {
public:
    std::string getType() override;
};

class ScaleneTriangle : public Triangle {
    std::string getType() override;
};
#endif