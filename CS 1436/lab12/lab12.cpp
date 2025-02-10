/*
Samuel Song
CS 1436.015 Programming Fundamentals
Due 10/15/24
Completed 10/9/24
Submitted 10/10/24
*/

#include <iostream>
using namespace std;

int main()
{
    //Declaring Variables
    int floors;
    int rooms;
    int occupied;
    double totalrooms=0.0;
    double totaloccupied=0.0;
    double percentoccupied;
    int unoccupied;

    //Asks the user the amount of floors the hotel has
    cout<<"How many floors does the hotel have?\n";
    cin>>floors;
    cout<<"\n";
    
    //Validates the floors inputted by user as being at least 1.
    while (floors<1)
    {
        cout<<"Please input a valid number of floors. (>=1)\n";
        cin>>floors;
        cout<<"\n";
    }


    for (int count=1;count<=floors;count++)
    {
        //Asks user the amount of rooms the floor 'count' has. Count changes every loop by 1.
        cout<<"How many rooms does floor "<<count<<" in the hotel have?\n";
        cin>>rooms;
        cout<<"\n";
        totalrooms+=rooms;  //Adds the value of rooms to the total rooms variable

        //Validates the room input to be at least 10
        while (rooms<10)
        {
            cout<<"Please input a valid number of rooms. (>=10)\n";
            cin>>rooms;
            cout<<"\n";
        }
        
        //Asks users the amount of rooms that are occupied on the floor. 
        cout<<"How many of the "<<rooms<<" rooms on floor "<<floors<<" are occupied?\n";
        cin>>occupied;
        cout<<"\n";
        totaloccupied+=occupied;    //Adds the value of occupied roomms to the total occupied variable.
        
        //Validates the user input of occupied rooms to be at least 0 and less than the rooms variable.
        while (occupied<0 || occupied>rooms)
        {
            cout<<"Please enter a valid number of occupied rooms on the floor.\n";
            cin>>occupied;
            cout<<"\n";
        }
        
    }
    //Calculates the math for the unoccupied rooms and percent of rooms occupied.
    unoccupied=totalrooms-totaloccupied;
    percentoccupied=totaloccupied/totalrooms;

    //Outputs the final information
    cout<<"The hotel has a total of "<<totalrooms<<" rooms.\n";
    cout<<"Of those "<<totalrooms<<" rooms, "<<totaloccupied<<" rooms are occupied.\n";
    cout<<"Of the total "<<totalrooms<<" rooms, "<<unoccupied<<" rooms are unoccupied.\n";
    cout<<"Meaning "<<percentoccupied<<"% of the total rooms are occupied.\n";

}