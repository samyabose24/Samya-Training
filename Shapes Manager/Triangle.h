#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"


class Triangle: public Shape {
private:
    double area;
public:
    void setLength(double l) override;
    void setWidth(double w) override;
    void calculateArea() override;
    void printArea() override;
    std::string getType() override;
};
#endif