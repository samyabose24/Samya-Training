#include <iostream>
#include <vector>
#include "Rectangle.h"
#include "Triangle.h"
#include "EquilateralTriangle.h"
#include "IsoscelesTriangle.h"
#include "ScaleneTriangle.h"

using namespace std;

int main() {

    vector<Shape*> myShapes;

    // Create the shapes
    myShapes.push_back(new Rectangle());
    myShapes.push_back(new Triangle());
    myShapes.push_back(new EquilateralTriangle());
    myShapes.push_back(new IsoscelesTriangle());
    myShapes.push_back(new ScaleneTriangle());

    // Names of the shapes
    string names[] = {"Box", "Doritos", "Pyramid", "Cheese", "Slide"};

    // Set initial values (Length = 5, Breadth = 10)
    for(int i = 0; i < myShapes.size(); i++) {
        myShapes[i]->setName(names[i]);
        myShapes[i]->setLength(5);
        myShapes[i]->setBreadth(10);
    }

    // First output
    cout << "Length = 5 and Breadth = 10" << endl;
    cout << "List of Shapes: " << endl;

    for (Shape* s : myShapes) {
        s->calculateArea();
        cout << "Name: " << s->getName() << " | Type: " << s->getType() << " | ";
        s->printArea();
    }

    // Change the length to 20 and recalculate the area
    cout << "\nChanging Length to 20 and recalculating the area of the shapes...\n";
    cout << "Length = 20 and Breadth = 10" << endl;
    cout << "List of Shapes: " << endl;

    for (Shape* s : myShapes) {
        s->setLength(20);
        s->calculateArea();
        cout << "Name: " << s->getName() << " | Type: " << s->getType() << " | ";
        s->printArea();
    }

    // Free memory
    for (Shape* s : myShapes) delete s;

    return 0;
}