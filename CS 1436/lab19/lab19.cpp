/*
Samuel Song
CS 1436.015 Programming Fundamentals
Due 11/9/24
Completed 11/5/24
Submitted 11/5/24
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//function prototypes
void computerchoice(int num);
void game(int user, int computer);

int main() 
{
    //Declaration of variables
    int num;      
    int choice;   

    unsigned seed=time(0);
    srand(seed);

    const int MIN=1,MAX=3;

    do {
        // Generate a new computer's choice each loop
        num=(rand()%(MAX-MIN+1)+MIN);

        // Get users choice
        cout<<"What do you wish to play? Rock (1), Paper (2), or Scissors (3)?" << endl;
        cin>>choice;

        //validation
        while (choice<1 || choice>3) 
        {
            cout<<"Please choose a valid option. (1-3):";
            cin>>choice;
        }

        computerchoice(num);

        // calls the game
        game(choice, num);

    } while (choice==num);  // Continue looping if there's a tie
    return 0;
}

//Prints computers choice
void computerchoice(int val) 
{
    if (val==1) 
    {
        cout<<"The computer chose Rock." << endl;
    }
    else if (val==2) 
    {
        cout<<"The computer chose Paper." << endl;
    }
    else if (val==3) 
    {
        cout<<"The computer chose Scissors." << endl;
    }
}

//Function game to see if user won/loss or tied
void game(int user, int computer) 
{
    if (user==computer) 
    {
        cout<<"You tied. Both the computer and you chose the same option."<<endl;
    }
    else if (user==1 && computer==3 || user==3 && computer==2 || user==2 && computer==1) 
    {
        cout<<"You won!"<<endl;
    }
    else 
    {
        cout<<"You lost."<<endl;
    }
}