/*
Samuel Song
CS 1436.015 Programming Fundamentals
Due 9/18/24
Completed 9/12/24
Submitted 9/12/24
*/


#include <iostream> //required for cout/cin
#include <iomanip>  //required for setprecision
#include <ctime>    //required for time function
#include <cstdlib>  //needed for srand/rand
#include <cmath>    //needed to do math calculations
using namespace std;


int main()
{       
    //Declaring srand to have a different num each time from time function
   unsigned seed=time(0);
   srand(seed);
   
   
   //Declaring Variables
   double annualInterest;
   double monthlyInterest;
   double monthlyIntPercent;
   double monthlyPay;
   double numPayment;
   int loanAmount;
   double numerator;
   double denominator;
   double totalPaid;
   double interestPaid;
   
   
   //Random number generating, range of 8,000-15,000
   const int min=8000,max=15000;
   loanAmount=(rand()%(max-min+1)+min);
   
   
   //Asks user for their annual interest rate to store
   cout<<"What is the Annual Interest Rate?\n";
   cin>>annualInterest;
   cout<<"\n";
   
   
   //Calculates the Monthly Interest and converts to a percentage
   monthlyInterest=annualInterest/12;
   monthlyIntPercent=monthlyInterest*100;
   
   
   //Asks user for Payment Plan to store
   cout<<"What is the number of payments for the loan?\n";
   cin>>numPayment;
   cout<<"\n";
   
   
   //Used to calculate the Monthly Pay using monthly interest, payment plan, and loan amount
   numerator=monthlyInterest*(pow((1+monthlyInterest),numPayment));
   denominator=(pow((1+monthlyInterest),numPayment)-1);
   monthlyPay=(numerator/denominator)*loanAmount;
   
   
   //Total Paid Money with payment plan
   totalPaid=monthlyPay*numPayment;
   
   
   //Calculates the interest Paid from total paid
   interestPaid=totalPaid-loanAmount;
   
   
   //Cout all info calculated
   cout<<setprecision(2)<<fixed; //makes output have 2 decimals, and cleans up numbers
   cout<<"Loan Amount: $"<<loanAmount<<endl;
   cout<<"Monthly Interest Rate: "<<monthlyIntPercent<<"%"<<endl;
   cout<<"Number of Payments: "<<numPayment<<endl;
   cout<<"Monthly Payments: $"<<monthlyPay<<endl;
   cout<<"Total Amount Paid Back: $"<<totalPaid<<endl;
   cout<<"Interest Paid: $"<<interestPaid<<endl;
   

}