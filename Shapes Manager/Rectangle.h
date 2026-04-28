#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

class Rectangle : public Shape {
private:
    double area;

public:
    void setLength(double l) override;
    void setBreadth(double b) override;
    void calculateArea() override;
    void printArea() override;
    std::string getType() override;
};

#endif