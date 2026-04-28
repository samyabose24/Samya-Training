#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"

class Triangle : public Shape {
protected:
    double area;

public:
    void setLength(double l) override;
    void setBreadth(double b) override;
    virtual void calculateArea() override;
    void printArea() override;
    std::string getType() override;
};

#endif