/*
Program Name: Assign Roll Bones Game
Date: 2/25/2025
Author: Samuel Song
Module Purpose: Randomly generate two dice values and determine whether or not the 
users stake and bet will result in a profit or loss.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>

using namespace std;

unsigned askForInititalStakeAmountFunc();
unsigned askForBetDonePlayingFunc(unsigned& stakeUns);
unsigned rollDemBonesFunc(unsigned& rollCountUns);
void  evaluateRollFunc(unsigned diceRollResultsUns, unsigned& rollCountUns, unsigned& stakeUns, unsigned betUns);
bool  pointRollDemBonesFunc(unsigned pointUns, unsigned& rollCountUns);

int main() 
{
  unsigned betUns, rollCountUns=0, diceRollResultsUns;
  
  
  unsigned stakeUns=askForInititalStakeAmountFunc();
  do 
  {
    betUns = askForBetDonePlayingFunc(stakeUns);
        if (betUns==0) 
        {
          break;  //exits loop
        }
        diceRollResultsUns=rollDemBonesFunc(rollCountUns);
        evaluateRollFunc(diceRollResultsUns, rollCountUns, stakeUns, betUns);
        cout<<"Current stake:"<<stakeUns<<"\n\n";
  } while (betUns!=0 && stakeUns!=0);


  if (betUns==0)
  {
    cout<<"Game over.\n";
    cout<<"You rolled "<<rollCountUns<<" times."<<endl;
    cout<<"You're final stake amount was "<<stakeUns<<endl;
    exit(EXIT_SUCCESS);
  }
  else
  {
    cout<<"You ran out of money."<<endl;
  }


  cout<<"You rolled "<<rollCountUns<<" times."<<endl;
  cout<<"You're final stake amount was "<<stakeUns<<endl;
  cout << "Press enter key once or twice to end... ";cin.ignore(); cin.get();


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

  int stakeUns;

  do 
  {
    cout<<"What is your stake amount?"<<endl;
    cin>>stakeUns;

    if (stakeUns>=0)
    {
      break;
    }
    else while (stakeUns<0)
    {
      cout<<"You must enter a 0 or positive amount of money to bet with. Try again!";
      cin>>stakeUns;
    }
  } 
  while (true); 

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

  unsigned bet=0;
  cout<<"Current Stake Amount:"<<stakeUns<<endl;
  cout<<"How much will you bet?\n";
  cin>>bet;
  
  //Validation statements
  while (bet>stakeUns)
  {
    cout << "Bet amount cannot be more than your current stake. Please try again.\n";
    cin>>bet;
  }

  while (bet<0)
  {
    cout<<"Bet amount must be greater than or equal to 0. Try again.\n";
    cin>>bet;
  }

  if (bet==0)
  {
    return(bet);
  }

  return(bet);
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

unsigned rollDemBonesFunc(unsigned& rollCountUns) 
{
  cout<<"Press enter key once or twice to throw the dice... ";cin.ignore();cin.get();

  rollCountUns++;

  srand(clock()); 

  int max=6;
  int min=1;

  unsigned die1=(rand()%(max-min+1)+min);
  unsigned die2=(rand()%(max-min+1)+min);
  unsigned sum=die1+die2;
  
  cout<<"You rolled a "<<die1<<" and a "<<die2<<" for a total of "<<sum<<".\n";
  return sum;
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

void evaluateRollFunc(unsigned diceRollResultsUns, unsigned& rollCountUns, unsigned& stakeUns, unsigned betUns) 
{
    if (diceRollResultsUns==2||diceRollResultsUns==3||diceRollResultsUns==12) 
    {
        cout<<"You Lose!\n";
        stakeUns-=betUns;
    } 
    else if (diceRollResultsUns==7||diceRollResultsUns==11) 
    {
        cout<<"You win!\n";
        stakeUns+=(betUns * 2);
    } 
    else 
    {
        unsigned point = diceRollResultsUns;
        cout<<"The point is: "<<point<<endl;
        cout<<"Throw em again and hope that luck is on your side!\n"<<endl;

        bool win=pointRollDemBonesFunc(point, rollCountUns);

        if (win) 
        {
            cout<<"You rolled the point! You win!\n";
            stakeUns+=(betUns * 2);
        } 
        else
        {
            cout<<"You rolled a 7. You lose!\n";
            stakeUns-=betUns;
        }
    }
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

bool pointRollDemBonesFunc(unsigned pointUns, unsigned& rollCountUns) 
{
  unsigned diceSum;

  while (true) 
  {
      diceSum = rollDemBonesFunc(rollCountUns);
      if (diceSum == pointUns) 
      {
          return true;
      }
      else if (diceSum == 7) 
      {
          return false;
      }
      else 
      {
          cout<<"The point is "<<pointUns<<"\n";
          cout<<"Throw em again and hope that luck is on your side!"<<"\n";
      }
  }
}