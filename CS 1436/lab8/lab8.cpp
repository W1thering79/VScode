/*
Samuel Song
CS 1436.015 Programming Fundamentals
Due 9/27/24
Completed 9/24/24
Submitted 9/24/24
*/

#include <iostream>
using namespace std;

int main()
{

//Declaring Variables needed for code
char choice; 
int hours;
double monthlyfee;

    //Asks user which Internet Service Package they purchased
    cout<<"Which Internet Service Package did you Purchase? (A,B, or C)"<<endl;
    cin>>choice;
    cout<<"How many hours were used?"<<endl;
    cin>>hours;
    
    //Validates the Hours inputted to be less than 744 hours
    if (hours>744)
    {
       cout<<"Invalid Hours. Cannot exceed 744 hours."; 
    }
    else
    {
        switch(choice)  //switch statement
    {
        //Case A, first choice
        case 'A':   
        if (hours>10)   //checks if hours goes beyond provided hours and needs additional fees
        {
            monthlyfee=9.95+hours*2;    //calculates the additional hours fee
            cout<<"Your monthly fee is: $"<<monthlyfee; //outputs fee after calculating additonal hour fee
        }
        else
        {
            cout<<"Your monthly fee is $9.95";  //outputs monthly fee if no additional fee is needed.
        }
            break;

        //Case B, second choice    
        case 'B': 
        if (hours>20)   //checks if hours goes beyond provided hours and needs additional fees
        {
            monthlyfee=14.95+hours*1;    //calculates the additional hours fee
            cout<<"Your monthly fee is: $"<<monthlyfee; //outputs fee after calculating additonal hour fee
        }
        else
        {
            cout<<"Your monthly fee is $14.95"; //outputs monthly fee if no additional fee is needed.
        }
            break;
        
        //Case C, last choice
        case 'C': cout<<"Your monthly fee is $29.95";   //outputs monthly fee (No additional fee is charged for this package)
            break;
            
        default: cout<<"Invalid Package. Please choose a valid Package (A,B,C)";    //default to validate users input of package.
        break;
    }
    return 0;
    }
}