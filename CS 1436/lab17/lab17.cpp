/*
Samuel Song
CS 1436.015 Programming Fundamentals
Due 11/2/24
Completed 10/29/24
Submitted 10/29/24
*/

#include <iostream>
#include <iomanip>
using namespace std;

//Function Prototype to allow function to run
void paintjob(int, double, int);

//Declaring variables
int rooms;
double price;
int wall;
double painttotal;
double laborhours;
double paintprice;
double laborprice;
double totalcost;

int main()
{

    //Ask user the amount of rooms that need to be painted
    cout<<"How many rooms need to be painted?"<<endl;
    cin>>rooms;

    while (rooms<1) //validates input of rooms to be >=1
    {
        cout<<"Invalid number of rooms. Please enter a valid num. (>=1)"<<endl;
        cin>>rooms;
    }

    //Ask the user the price of paint per gallon
    cout<<"What is the price of paint per gallon?"<<endl;
    cin>>price;

    while (price<10.00) //validates price of paint to be at least 10 dollars
    {
        cout<<"Invalid price of paint per gallon, please enter a valid price. (>10.00)"<<endl;
        cin>>price;
    }

    //Asks user for the square feet of surface in each room
    cout<<"How many square feet of wall are there in each room?"<<endl;
    cin>>wall;

    while (wall<0)  //validates input to be a positive number
    {
        cout<<"Invalid square feet of wall, please enter a valid square footage. (>0)"<<endl;
        cin>>wall;
    }

    paintjob(rooms,price,wall); //calls for paintjob() function
}

void paintjob(int num1,double num2,int num3)
{
    painttotal=num3/115;    //Calculates the amount of gallons of paint
    cout<<"The number of gallons of paint required:"<<painttotal<<endl;

    laborhours=8*painttotal;    //Calculates the amount of labor by using labor hours
    cout<<"The hours of labor required:"<<laborhours<<endl;

    paintprice=num2*painttotal; //Paint price calculated by multiplying the user inputted price times the amount of gallons of paint
    cout<<"The cost of paint:$"<<fixed<<setprecision(2)<<paintprice<<endl;

    laborprice=18.00*laborhours;    //Calculates the price of labor by multiplying the labor hours by hourly rate of $18
    cout<<"The labor price:$"<<fixed<<setprecision(2)<<laborprice<<endl;

    totalcost=paintprice+laborprice;    //Total cost is the paint cost and labor price
    cout<<"The total cost of the paint job:$"<<fixed<<setprecision(2)<<totalcost<<endl;
}
