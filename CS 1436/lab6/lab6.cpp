/*
Samuel Song
CS 1436.015 Programming Fundamentals
Due 9/25/24
Completed 9/19/24
Submitted 9/19/24
*/


#include <iostream>
using namespace std;

int main() {
    int choice; //declares variable choice as an int
    int seconds;    //declares variable seconds as an int
    double speed;   //declares variable speed as double
    
    //Menu for the user to pick one of 4 gases
    cout<<"Please Select one of the 4 Gases"<<endl;
    cout<<"1) Carbon Dioxide"<<endl;
    cout<<"2) Air"<<endl;
    cout<<"3) Helium"<<endl;
    cout<<"4) Hydrogen"<<endl;
    cin>>choice;
    
    //Checks if the inputted choice by the user is valid
    if (choice<0 || choice>4)
    {
        cout<<"Please input a valid choice from the 4 gases.";
    }
    
    //Carbon Dioxide Choice:
    if (choice==1)
    {
        cout<<"How many seconds did it take for sound to travel from the source detected?"<<endl;
        cin>>seconds;
        if (seconds<0||seconds>30)  //checks to see if time inputted is valid
        {
            cout<<"Please enter a valid time. (0-30 seconds)";
        }
        else
        {
        speed=258.0*seconds;
        cout<<"The source of sound from the detected location was "<<speed<<" meters away.";
        }
    }
    
    //Air Choice
    else if (choice==2)
    {
        cout<<"How many seconds did it take for sound to travel from the source detected?"<<endl;
        cin>>seconds;
        if (seconds<0||seconds>30)  //checks to see if time inputted is valid
        {
            cout<<"Please enter a valid time. (0-30 seconds)";
        }
        else
        {
        speed=331.5*seconds;
        cout<<"The source of speed from the detected location was "<<speed<<" meters away.";
        }
    }
    
    //Helium Choice
    else if (choice==3)
    {
        cout<<"How many seconds did it take for sound to travel from the source detected?"<<endl;
        cin>>seconds;
        if (seconds<0||seconds>30)  //checks to see if time inputted is valid
        {
            cout<<"Please enter a valid time. (0-30 seconds)";
        }
        else
        {
        speed=972.0*seconds;
        cout<<"The source of speed from the detected location was "<<speed<<" meters away.";
        }
    }
    
    //Hydrogen Choice  
     else if (choice==4)
    {
        cout<<"How many seconds did it take for sound to travel from the source detected?"<<endl;
        cin>>seconds;
        if (seconds<0||seconds>30)  //checks to see if time inputted is valid
        {
            cout<<"Please enter a valid time. (0-30 seconds)";
        }
        else
        {
        speed=1270.0*seconds;
        cout<<"The source of speed from the detected location was "<<speed<<" meters away.";
        }
    }
}