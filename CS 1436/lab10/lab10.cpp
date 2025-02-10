/*
Samuel Song
CS 1436.015 Programming Fundamentals
Due 10/7/24
Completed 10/3/24
Submitted 10/3/24
*/

#include <iostream>
using namespace std;

int main()
{
    //Declaring variables
    int speed;
    int hours;
 

    //Asks the user for the speed
    cout<<"What is the speed of the vehicle in mph?"<<endl;
    cin>>speed;
    
    while (speed<0) //validates speed to be a positive number
    {
        cout<<"Please input a valid positive number."<<endl;
        cin>>speed;
    }
    
    //Asks user for the hours traveled
    cout<<"How many hours has it traveled?"<<endl;
    cin>>hours;
    
    
    while (hours<1) //Validates hours to be at least 1
    {
        cout<<"Please input a valid time traveled. (time>1)"<<endl;
        cin>>hours;
    }
    
    //Header for the output of info
    cout<<"Hour Distance Traveled"<<endl;
    cout<<"----------------------"<<endl;
    
    
    int count=1;    //declaring count as 1 to start the loop
    while (count<=hours)    //loop of while count value is less than hours to repeat
    {
        cout<<count<<"\t\t"<<(count*speed)<<endl; //outputs the hour then calculates the distance traveled by multiplying speed by count
        count++;    //increments count
    }
    
    
}