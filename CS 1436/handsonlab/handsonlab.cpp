/*
Samuel Song
CS 1436.015 Programming Fundamentals
Due 10/10/24
Completed 10/10/24
Submitted 10/10/24
*/

#include <iostream>
using namespace std;

int main()
{   
    //Declaring variables
    int days;
    double pay=0.01;    //assigns a starting value to pay as 0.01
    int count;
    double totalpay;

    //Asks the user for an input of days
    cout<<"For how many days will the pay double?\n";
    cin>>days;
    cout<<"\n";

    //Validates the input of days to be at least one and not greater than 365
    while (days<1 || days>365)
    {
        cout<<"Please enter a valid number of days (>1 and <365)\n";
        cin>>days;
    }

    //Outputs data
    cout<<"Day\tTotalPay\n";
    cout<<"-----------------\n";
    cout<<"1"<<"\t$"<<pay<<"\n";    //outputs the first line of information

    //For loop
    for (count=2;count<=days;count++)
    {
        pay=pay*2;  //each iteration, multiplies the pay by 2 and sets pay to the answer
        cout<<count<<"\t$"<<pay<<endl;  //outputs the info 
        totalpay+=pay;  //Adds the pay amount to the total
    }
    totalpay+=0.01; //Adds extra penny for first line of info
    cout<<"----------------\n";
    cout<<"Total\t$"<<totalpay; //Outputs total
 


}