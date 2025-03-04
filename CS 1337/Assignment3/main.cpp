/*
Program Name: Assign Roll Bones Game
Date: 2/25/2025
Author: Samuel Song
Module Purpose: 
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>

using namespace std;

unsigned askForInititalStakeAmountFunc();
unsigned askForBetDonePlayingFunc(unsigned& stakeUns);
unsigned rollDemBonesFunc(unsigned& rollCountUns);
void     evaluateRollFunc(unsigned diceRollResultsUns, unsigned& rollCountUns, unsigned& stakeUns, unsigned betUns);
bool     pointRollDemBonesFunc(unsigned pointUns, unsigned& rollCountUns);

int main() {
  unsigned
    betUns,
    rollCountUns = 0,
    diceRollResultsUns;

    unsigned stakeUns=askForInititalStakeAmountFunc();

  do {
    betUns=askForBetDonePlayingFunc(stakeUns);
    if (betUns>0)
    {
      rollDemBonesFunc(rollCountUns);
    }
    //$ based on betUns determine wether or not to call rollDemBonesFunc(rollCountUns)
    //$ and then call evaluateRollFunc(diceRollResultsUns, rollCountUns, stakeUns, betUns);
  } while (betUns!=0 && stakeUns!=0); //$ execute loop as long as betUns != 0 and stakeUns != 0;

  if (betUns=0)
  {

  }
  //$   then display player ends game
  //$   else display player out of money

  //$ display a Roll Count message;
  //$ display a final stake amount messaqge

  cout << "Press enter key once or twice to end ... ";cin.ignore(); cin.get();

  exit(EXIT_SUCCESS);
}

/*
Name:              askForInitialStakeAmountFunc
Function Purpose : Retrieves the initial money from prompting the user
Function Design:   Checks if the input stake amount the player enters a proper amount:
                   stakeStartUns > 0
                   not a negative amount
Inputs:            None
Outputs:           By function name an unsigned integer that's the stake amount
*/

unsigned askForInititalStakeAmountFunc() 
{
  unsigned stakeUns;
  do {
    cout<<"What is your stake amount?"<<endl;
    cin>>stakeUns;

    if (stakeUns>0)
    {
      return stakeUns;
    }
    else
    {
      cout<<"You must enter a 0 or positive amount of money to bet with. Try again!";
      cin>>stakeUns;
    }
  } while (true); 

  return stakeUns;

}

/*
Name: askForBetDonePlayingFunc
Function Purpose : Asks for what the player will bet and checks for validity
Function Design:   Checks for valid entry
                   if not valid entry, staes the reason why
                   retry entry if not valid
Inputs:            stakeUns - The total stake amount
Outputs:           By function name an unsigned integer that's the bet amount
*/

unsigned askForBetDonePlayingFunc(unsigned& stakeUns) 
{

  unsigned betamount;
  cout<<"Current Stake Amount:"<<stakeUns<<endl;
  cout<<"How much will you bet?";
  cin>>betamount;

  if (betamount<0)
  {
    cout<<"You must enter a 0 or positive amount of money to bet with. Try again!";
    cin>>betamount;
  }

  if (betamount>stakeUns)
  {
    cout<<"You cannot bet higher than your stake amount:";
    cin>>betamount;
  }

  //Design a validation loop

     //$ display current stake amount
     //$ ask for a bet

     //$ check if input  amount more than stake amount
         //$ display error message
         //$ continue the loop

     //$ check if input bet amount is less than 0
         //$ display error message
         //$ continue the loop
     
     //$ set valid bet amount
         // leave the loop

   //$ return the valid inputted bet
  return(0);
}

/*
Name:             rollDemBonesFunc
Function Purpose: generates an independent random number for each die
                  calculates the roll sum
                  increments rollCountUns
Function Design:  Prompts the user to throw the dice
                  Using rand() generates 2 random variables from 1 to 6 and adds to simulate dice throw
Inputs/Outpuut:   &rollCountUns - Reference of total rolls count in game
Outputs:          By function name an unsigned integer that's the sum of the two rolled dice
*/

unsigned rollDemBonesFunc(unsigned& rollCountUns) {

  //$ display Press enter key once or twice to throw the dice
  //$ see assigment to use ignore() and get() to hold the screen

  //$ increment the roll count
  //$seed the random number generator
  

  //$execute the dice roll as two separet rolls

  //$ return the dice sum
  return(0);
}

/*
Name: evaluateRollFunc
Function Purpose: Check for a winning roll, a losing roll, or a point roll result
                  Adjust stakeUns using betUns for win or loss result
Function Design:  2, 3, 12      loses
                  7, 11         winner
                  anything else executes point rolls
Inputs:           diceRollResultsUns - The dice roll sum
                  betUns             - The placed bet
Input/Output:     &rollCountUns      - Reference to tally of total rolls
                  &stakeUns          - Reference to the total at stake
*/

void evaluateRollFunc(unsigned diceRollResultsUns, unsigned& rollCountUns, unsigned& stakeUns, unsigned betUns) {
//$ Code up this function as per game rules in assignment

}

/*
Name:             pointRollDemBonesFunc
Function Purpose: Executes the point rolls
Function Design:  Displays the point value.
                  Executes repeating rolls using rollDemBonesFunc until the point or 7 is the result
                  Each roll passes to rollDemBonesFunc() the rollCountUns and recives back the rollCountUns
Inputs:           pointUns      - The point set by the first roll
Inputs/Outputs    &rollCountUns - Reference to total roll count
Outputs:          After point rolls produces a return for a win (true) or a loss (false)
*/

bool pointRollDemBonesFunc(unsigned pointUns, unsigned& rollCountUns) {
  
  unsigned pointRollUns;

  //Executes until point  value  or 7 is rolled


  return(false);
}


