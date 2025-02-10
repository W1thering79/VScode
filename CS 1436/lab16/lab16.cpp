/*
Samuel Song
CS 1436.015 Programming Fundamentals
Due 10/30/24
Completed 10/24/24
Submitted 10/24/24
*/

#include <iostream>
#include <iomanip>
using namespace std;

//Declaring variables
double wholeprice;
double markup;
double markuppercent;
double retailprice;
double retailtotal;

void calculateRetail(double, double);   //Function Prototype (needed to input num into function)

int main()
{
    cout<<"What is the item's Wholesale Price and Markup Percentage?\n";    //asks user for wholesale price and markup percent
    cout<<"Wholesale Price:";
    cin>>wholeprice;

    while (wholeprice<0)    //checks for valid wholesale price (>0)
    {
        cout<<"Please enter a valid Wholesale Price(>0)\n";
        cout<<"Wholesale Price:";
        cin>>wholeprice;
    }

    cout<<"Markup Percentage:";
    cin>>markup;

    while (markup<0)    //checks for valid markup (>0)
    {
        cout<<"Please enter a valid Markup Percentage. (>0)\n";
        cout<<"Markup Percentage:";
        cin>>markup;
    }

    markuppercent=markup/100;   //divides the markup variable by 100 to get percent in decimal form.
    calculateRetail(wholeprice,markuppercent);  //Uses wholeprice and markuppercent as arguments for function
}

void calculateRetail(double num1,double num2)   //assigns wholeprice to num1, markuppercent to num2
{
    retailprice=num1*num2;  //multiplies num1 & num2 to get the retail price
    retailtotal=retailprice+num1;   //Adds retailpriced to original wholeprice to get the retail total
    cout<<"The Retail Price of item is:"<<fixed<<setprecision(2)<<retailtotal;  //ourpurs retail total with 2 decimals via setprecision
}