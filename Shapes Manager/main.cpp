#include <iostream>
#include <vector>
#include "Rectangle.h"
#include "Triangle.h"

using namespace std;

int main() {
    // Vector of base class pointers to store different subclasses
    vector<Shape*> myShapes;

    // Creating one of each required type of shape
    myShapes.push_back(new Rectangle());
    myShapes.push_back(new Triangle());
    myShapes.push_back(new EquilateralTriangle());
    myShapes.push_back(new IsoscelesTriangle());
    myShapes.push_back(new ScaleneTriangle());

    // Creating names and setting initial values
    string names[] = {"Box", "Doritos", "Pyramid", "Cheese", "Slide"};
    for(int i = 0; i < myShapes.size(); i++) {
        myShapes[i]->setName(names[i]);
        myShapes[i]->setLength(10 + i);
        myShapes[i]->setBreadth(5 + i);
    }

    // Print the name, type and area of the shapes
    cout << "List of the Shapes" << endl;
    cout << "Length: 10 and Breadth: 5" << endl;
    for (Shape* s : myShapes) {
        s->calculateArea();
        cout << "Name: " << s->getName() << " | Type: " << s->getType() << " | ";
        s->printArea();
    }

    // Changing the length to 20 and recalculating the area of the shapes
    cout << "\nChanging the Length to 20 and recalculating the area of the shapes....." << endl;
    for (Shape* s : myShapes) {
        s-> setLength(20);
        s->calculateArea();
        cout << "Name: " << s->getName() << " | Type: " << s->getType() << " | ";
        s-> printArea();
    }

    // Cleaning up memory
    for (Shape* s : myShapes) delete s;

    return 0;
}