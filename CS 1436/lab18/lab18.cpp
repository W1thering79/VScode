/*
Samuel Song
CS 1436.015 Programming Fundamentals
Due 11/4/24
Completed 11/3/24
Submitted 11/3/24
*/

#include <iostream>
#include <iomanip>
using namespace std;

double stockprofit(const int& ns, const double& pp, const double& pc, const double& sp, const double& sc);  //function prototype using a reference type

//declaration of variables
int shares;
double salesPrice;
double salesCommission;
double purchasePrice;
double purchaseCommission;

int main()
{

    //Asks user input for numerous variables
    cout<<"How many shares are there?\n";
    cin>>shares;

    cout<<"What was the purchase price per share?\n";
    cin>>purchasePrice;

    cout<<"What was the purchase commission paid?\n";
    cin>>purchaseCommission;

    cout<<"What was the sales price per share of the stock?\n";
    cin>>salesPrice;

    cout<<"What was the sales commission?\n";
    cin>>salesCommission;

    //inputs all of users value into function as arguments and calls
    //also sets variable stock equal to the function to check if stock was a loss or profit
    double stock=stockprofit(shares,purchasePrice,purchaseCommission,salesPrice,salesCommission);

    
    if (stock<0)    //checks if stock is negative, if true then the stock has a loss
    {
        cout<<"The stock has a loss of:$"<<stock<<fixed<<endl;
    } 
    else if (stock>0)   //checks if stock is positive, if true then the stock has a profit
    {
        cout<<"The stock has a profit of:$"<<stock<<fixed<<endl;
}
}
    

double stockprofit(const int& ns, const double& pp, const double& pc, const double& sp, const double& sc)
{
    return (((ns*sp)-sc)-((ns*pp)+pc)); //returns the calculation of stockprofit
}