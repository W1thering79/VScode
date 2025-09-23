#ifndef RECTANGLE_SHAPE_SUB_CLASS_H
#define RECTANGLE_SHAPE_SUB_CLASS_H

#include "BasicShapeClass.h"
#include "LineInfo.h"
#include <iostream>

using namespace std;

class RectangleShapeSubClass:public BasicShapeClass //class derived from basicshapeclass
{
    private:
    double width;
    double length;
    
    public:
    RectangleShapeSubClass(double w, double l):width(w),length(l) 
    {
        setArea(calculateArea());
    }
    double calculateArea()
    {
        return width*length;
    }
    void display()
    {
        cout<<"Shape is a Rectangle:"<<endl;
        cout<<"Width: "<<width<<endl;
        cout<<"Length: "<<length<<endl;
        cout<<"Area: "<<getArea()<<endl;
    }
};

#endif //RectangleShapeSubClass
