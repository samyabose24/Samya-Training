#ifndef SHAPE_H
#define SHAPE_H
#include <string>

class Shape {
protected: // Protected class - Members are accessible only within the class and by any subclasses that inherit from it.
    std::string name;
    double length;
    double breadth;

public: // The methods (Each object has its own) (Virtual functions allows the code to decide which function to call based on the object type)
    Shape();
    virtual ~Shape() {}

    virtual void setLength(double l) = 0;
    virtual void setBreadth(double b) = 0;
    virtual void calculateArea() = 0; // Every class must define its own
    virtual void printArea() = 0;
    virtual std::string getType() = 0; // No void as it returns a value, void is used when there is nothing to return

    void setName(std::string n); // No need to override, same for all the shapes (Virtual is only needed when different classes need different behavior)
    std::string getName();
};

#endif