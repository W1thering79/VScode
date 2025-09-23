/*
Samuel Song
CS 1436.015 Programming Fundamentals
Due 8/29/24
Completed 8/29/24
Submitted 8/29/24

*/
//This program calculates the user's pay.
#include <iostream> //requires iostream for cout
using namespace std;    //requires std namespace for cout

int main()  //start of main function
{   //open bracket for block of code
    double hours, rate, pay;    //declares variables as double
    
    
    cout<<"How many hours did you work? ";//Get the number of hours worked.
    cin>>hours; //user input of hours worked
    

    cout<<"How much do you get paid per hour? ";//Get the hourly pay rate.
    cin>>rate;  //user input of hourly pay
    
   
    pay=hours*rate; //Calculate the pay.
    

    cout<<"You have earned $"<<pay<<endl;//Display the pay.
    return 0;   //ends program
}   //end bracket for block of code