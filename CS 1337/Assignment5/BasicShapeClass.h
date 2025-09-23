#ifndef BASIC_SHAPE_CLASS_H
#define BASIC_SHAPE_CLASS_H

using namespace std;

class BasicShapeClass
{
    private:
    double area;
    
    public:
    double getArea() const {return area;}
    void setArea(double a) {area=a;}
    virtual double calculateArea()=0;
    virtual void display()=0;
};

#endif //BASIC_SHAPE_CLASS_H
