#ifndef CIRCLE_SHAPE_SUB_CLASS_H
#define CIRCLE_SHAPE_SUB_CLASS_H

#include "BasicShapeClass.h"
#include "LineInfo.h"
#include <iostream>

using namespace std;

class CircleShapeSubClass:public BasicShapeClass    //class derived from basicshapeclass
{
    private:
    const double Pi;
    double radius;
    
    public:
    CircleShapeSubClass(double r):Pi(3.14159),radius(r) 
    {
        setArea(calculateArea());
    }
    double calculateArea()
    {
        return Pi*radius*radius;
    }
    void display()
    {
        cout<<"Shape is a Circle:"<<endl;
        cout<<"Radius: "<<radius<<endl;
        cout<<"Area: "<<getArea()<<endl;
    }
};

#endif //CircleShapeSubClass
