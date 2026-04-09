#ifndef SHAPE_H
#define SHAPE_H
#include <string>

class Shape {
protected:
    std::string name;
    double length;
    double width;

public:
    Shape();
    virtual ~Shape() {}

    virtual void setLength(double l) = 0;
    virtual void setWidth(double w) = 0;
    virtual void calculateArea() = 0;
    virtual void printArea() = 0;
    virtual std::string getType() = 0;

    void setName(std::string n);
    std::string getName();

};
#endif
