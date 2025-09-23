//Include headerfiles
#include "BasicShapeClass.h"
#include "CircleShapeSubClass.h"
#include "RectangleShapeSubClass.h"
#include "TriangleShapeSubClass.h"
#include "LineInfo.h"
#include <iostream>
#include <stdexcept>
#include <sstream>

using namespace std;

int main()
{
    try 
    {
    const int numofshapes=3;    //num of shape options
    BasicShapeClass*shapeArray[numofshapes];
    int shapeCount=0;

    cout<<"Choose 3 shapes and enter attributes,\n";
    cout<<"when all 3 shapes are entered the calculated results for all 3 shapes will display\n\n";
    while (shapeCount<numofshapes) 
    {
        //menu
        cout << "Choose your shape:\n\n"
                "1.Circle\n"
                "2.Rectangle\n"
                "3.Triangle\n\n"
                "Enter your choice:";
        int choice;
        cin>>choice;

        switch (choice) 
        {
            case 1: //circle case
            {
                double radius;
                cout<<"Enter the circles radius:";
                cin>>radius;
                if (radius<0)
                {
                    throw domain_error(LineInfo("Radius less than zero", __FILE__,__LINE__));
                }
                    shapeArray[shapeCount++]=new CircleShapeSubClass(radius);
                    break;
            }
            case 2: //rectangle case
            {
                double width, length;
                cout<<"Enter the rectangles width, length:";
                cin>>width>>length;
                if (width<0)
                {
                    throw domain_error(LineInfo("Width less than zero",__FILE__,__LINE__));
                }
                if (length<0)
                {
                    throw domain_error(LineInfo("Length less than zero",__FILE__,__LINE__));
                }
                    shapeArray[shapeCount++]=new RectangleShapeSubClass(width, length);
                    break;
            }
        
            case 3: //triangle case
            {
                double height, base;
                cout<<"Enter the triangles height, base:";
                cin>>height>>base;
                if (height<0)
                {
                    throw domain_error(LineInfo("Height less than zero",__FILE__,__LINE__));
                }
                if (base<0)
                {
                    throw domain_error(LineInfo("Base less than zero",__FILE__,__LINE__));
                }
                    shapeArray[shapeCount++]=new TriangleShapeSubClass(height, base);
                    break;
            }
            default:    //default if user inputted num is invalid
                cout<<"Wrong menu value: "<<choice<<endl;
                cout<<"Please try again....\n\n";
        }
    }

    cout<<endl;
    for (int i=0; i<numofshapes; ++i) 
    {
        shapeArray[i]->display();
        cout<<endl;
    }
} 

catch (exception& e)
{
    cout<<e.what()<<endl;
    cout<<endl<<"Press the enter key once or twice to leave..."<<endl;
    cin.ignore();
    cin.get();
    exit(EXIT_FAILURE);
}
return 0;
}