/*
Samuel Song
CS 1436.015 Programming Fundamentals
Due 9/23/24
Completed 9/17/24
Submitted 9/17/24
*/

#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    //Declares the Variables
    double area;
    const double pi=3.14159;    //constant double pi for circle
    int radius;
    int length;
    int width;
    int base;
    int height;
    int choice;
    
    //Prints out the Geometry Calculator Screen
    cout<<"1. Calculate the Area of a Circle.\n";
    cout<<"2. Calculate the Area of a Rectangle.\n";
    cout<<"3. Calculate the Area of a Triangle.\n";
    cout<<"4. Quit.\n";
    cin>>choice;

    //Checks of the chosen option is valid
    if (choice<1 || choice >4)
    {
    cout<<"Invalid choice, Please input a valid option (1-4)";
    }
    
    //Calculates the Area of the circle
    else if (choice==1)
    {
        cout<<"What is the Radius of the Circle?\n";
        cin>>radius;
        if (radius<0)   //Checks if the radius inputted is valid (is a positive num)
        {
            cout<<"Invalid Radius, please input a valid positive number";
        }
        else
        {
        area=(pi*(pow(radius,2)));  //multiplies the constant pi with the radius squared to find the area of a circle.
        cout<<"The Area of the circle is: "<<area;
        }
    }
    
    //Calculates the Area of a Rectangle
    else if (choice==2)
    {
        cout<<"What is the Length of the Rectangle?\n";
        cin>>length;
        cout<<"What is the Width of the Rectangle?\n";
        cin>>width;
        if (length<0||width<0)  //Checks the user inputted length and width to see if valid (positive num or not)
        {
            cout<<"Invalid Length and or Width, please input a valid positive number";
        }
        else
        {
        area=length*width;  //multiplies user inputted length & width to find area of rectangle
        cout<<"The Area of the rectangle is: "<<area;
        }
    }
    
    //Calculates the Area of a Triangle
    else if (choice==3)
    {
        cout<<"What is the Base of the Triangle?\n";
        cin>>base;
        cout<<"What is the Height of the Traignle?\n";
        cin>>height;
        if (base<0||height<0)   //Checks the base and height inputted with an or logic operator
        {
            cout<<"Invalid Base and or Height, please input a valid positive number";
        }
        else
        {
        area=base*height*0.5;   //multiplies the base and height with 0.5 to find the area of a triangle. 
        cout<<"The Area of the triangle is: "<<area;
        }
    }
    
    //Choice to end the program
    else if (choice==4)
    {
        return (0); //ends program
    }
}