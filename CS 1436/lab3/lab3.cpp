/*
Samuel Song
CS 1436.015 Programming Fundamentals
Due 9/7/24
Completed 9/5/24
Submitted 9/5/24
*/

#include <iostream> //required for cout/cin
using namespace std;    //requires namespace std for cout

int main()
{
    double payAmount,annualPay;    //declaring variables as double
    const int payPeriods=26;  //initialization of constant payPeriods as 26
    
    cout<<"Please provide the amount of you are paid each pay period.\n";
    cin>>payAmount; //Gets user input from keyboard of payamount per pay period
    
    annualPay=payAmount*payPeriods; //multiplies the payamount by payperiods to find the annualpay of employee
    cout<<"\nYou are paid $"<<annualPay<<" a year.\n";

    return 0;
}