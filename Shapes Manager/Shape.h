#ifndef SHAPE_H
#define SHAPE_H
#include <string>

class Shape {
protected: // Protected class - Members are accessible only within the class and by any subclasses that inherit from it.
    std::string name;
    double length;
    double breadth;

public: // The methods
    Shape();
    virtual ~Shape() {}

    virtual void setLength(double l) = 0;
    virtual void setBreadth(double b) = 0;
    virtual void calculateArea() = 0;
    virtual void printArea() = 0;
    virtual std::string getType() = 0;

    void setName(std::string n);
    std::string getName();
};

#endif