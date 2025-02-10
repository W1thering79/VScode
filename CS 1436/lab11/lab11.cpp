/*
Samuel Song
CS 1436.015 Programming Fundamentals
Due 10/15/24
Completed 10/8/24
Submitted 10/8/24
*/

#include <iostream>
using namespace std;

int main()
{  
    //Declares variables
    int startpop;
    double avgdaily;
    double percentavgdaily;
    int days;
    double popsize;
    
    //Asks user for the starting population and inputs into variable
    cout<<"What is the starting population of the organism?\n";
    cin>>startpop;

    //validates startpop to be greater than 2
    while (startpop<2)
    {
        cout<<"Please enter a valid starting population (>2)\n";
        cin>>startpop;
    }

    //Asks user of the average daily population increase
    cout<<"What is the average daily population increase?\n";
    cin>>avgdaily;
    
    //Validates avgdaily to be greater than 0 (makes sure num is a positive value)
    while (avgdaily<0)
    {
        cout<<"Please enter a valid average daily population increase (>0)";
        cin>>avgdaily;
    }
    
    //Asks users for the amount of days that the population grew
    cout<<"How many days did the population grow?\n";
    cin>>days;
    
    //Validates that the days are at least 1 day long
    while(days<1)
    {
        cout<<"Please enter a valid number of days the population grew. (>1)";
        cin>>days;
    }
    
    //Outpout Information
    cout<<"Population Growth\n";
    cout<<"------------------\n";
    cout<<"Day\tPopulation\n";
    percentavgdaily=avgdaily/100;   //changes the avgdaily from int to a decimal percent
    popsize=startpop;   //Sets the value of Day 0 as the starting population
    cout<<"0\t"<<startpop<<endl;    //Prints Day 0 population before loop begins
    for (int count=1;count<=days;count++)   
    {
        popsize+=(popsize*percentavgdaily); //popsize increased by the percentavgdaily * popsize
        cout<<count<<"\t"<<popsize<<endl;   //outputs data
    }
}