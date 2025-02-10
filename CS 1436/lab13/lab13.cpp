/*
Samuel Song
CS 1436.015 Programming Fundamentals
Due 10/21/24
Completed 10/15/24
Submitted 10/15/24
*/

#include <iostream>
using namespace std;

int main()
{
    //Declaring Variables
    int num;
    int smallest;    
    int largest;    

    //Sets initial values for smallest and largest value
    cout<<"Please enter your first number."<<endl;
    cin>>num;
    smallest=num;
    largest=num;

    //Validates initial value to be in range of 0-9999
    while (num<0 || num>9999)   
    {
        cout<<"Please enter a valid num (num>0 and num<9999)"<<endl;
        cin>>num;
    }

//Do while loop
do
{
    //Gets users input, repeats until user enters "77"
    cout<<"Please enter a number."<<endl;
    cin>>num;

    //Validation of num to be in range 0-9999
    while (num<0 || num>9999)
    {
        cout<<"Please enter a valid num (num>0 and num<9999)"<<endl;
        cin>>num;
    }

    //Checks if the num is grader than the previous largest num, if true, replaces largest value with num
    if (num>largest)
    {
        largest=num;
    }

    //Checks if the num is less than the previous smallest num, if true, replaces smallest value with num
    if (num<smallest)
    {
        smallest=num;
    }
} while (num!=77);  //runs the do-while when num is not equal to 77

//Outputs smallest/largest nums
cout<<"\n\n";
cout<<"Smallest num inputted:"<<smallest<<endl;
cout<<"Largest num inputted:"<<largest<<endl;
}