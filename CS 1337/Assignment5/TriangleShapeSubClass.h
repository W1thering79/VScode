#ifndef TRIANGLE_SHAPE_SUB_CLASS_H
#define TRIANGLE_SHAPE_SUB_CLASS_H

#include "BasicShapeClass.h"
#include "LineInfo.h"
#include <iostream>

using namespace std;

class TriangleShapeSubClass:public BasicShapeClass  //class derived from basicshapeclass
{
    private:
    double height;
    double base;
    
    public:
    TriangleShapeSubClass(double h, double b):height(h),base(b) 
    {
        setArea(calculateArea());
    }
    double calculateArea()
    {
        return 0.5*(base*height);
    }
    void display()
    {
        cout<<"Shape is a Triangle:"<<endl;
        cout<<"Height: "<<height<<endl;
        cout<<"Base: "<<base<<endl;
        cout<<"Area: "<<getArea()<<endl;
    }
};

#endif //TriangleShapeSubClass
