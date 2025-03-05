// main.cpp : Defines the entry point for the console application.

#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

unsigned askForInititalStakeAmountFunc();
unsigned askForBetDonePlayingFunc(unsigned& stakeUns);
unsigned rollDemBonesFunc(unsigned& rollCountUns);
void     evaluateRollFunc(unsigned diceRollResultsUns, unsigned& rollCountUns, unsigned& stakeUns, unsigned betUns);
bool     pointRollDemBonesFunc(unsigned pointUns, unsigned& rollCountUns);

int main() {
    // Seed the random number generator once at the start
    srand(clock());

    unsigned betUns, rollCountUns = 0, diceRollResultsUns;
    
    // $ assign stakeUns result from askForInititalStakeAmountFunc();
    unsigned stakeUns = askForInititalStakeAmountFunc();

    do {
        // $ assign betUns result from askForBetDonePlayingFunc(stakeUns);
        betUns = askForBetDonePlayingFunc(stakeUns);

        // $ based on betUns determine whether or not to call rollDemBonesFunc(rollCountUns)
        // $ and then call evaluateRollFunc(diceRollResultsUns, rollCountUns, stakeUns, betUns);
        if(betUns == 0) {
            break;
        }
        diceRollResultsUns = rollDemBonesFunc(rollCountUns);
        evaluateRollFunc(diceRollResultsUns, rollCountUns, stakeUns, betUns);
        
        // Display current stake after each round
        cout << "Current Stake Amount : " << stakeUns << "\n\n";
    } while (betUns != 0 && stakeUns != 0);
    
    // $ Out of loop
    // $ Check if betUns is 0 
    // $   then display player ends game
    // $   else display player out of money
    if (betUns == 0)
        cout << "Player ends Game" << "\n";
    else
        cout << "You ran out of money.\t" << "\n";
    
    // $ display a Roll Count message;
    cout << "Roll Count : " << rollCountUns << "\n";
    // $ display a final stake amount message
    cout << "Final Stake Amount : " << stakeUns << "\n";

    // $ Hold the screen before exiting
    cout << "Press enter key once or twice to end... "; 
    cin.ignore(); 
    cin.get();
    
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
unsigned askForInititalStakeAmountFunc() {
    int stake;
    do {
        // $ ask for stake amount
        cout << "What is your stake amount? ";
        cin >> stake;
        // $ if stake amount > 0) leave check loop
        if (stake > 0)
            break;
        // $ else display error message and continue loop
        cout << "You must enter a 0 or positive amount of money to bet with. Try again!" << "\n";
    } while (true);
    
    // $ return stake start amount
    return stake;
}

/*
Name: askForBetDonePlayingFunc
Function Purpose : Asks for what the player will bet and checks for validity
Function Design:   Checks for valid entry
                   if not valid entry, states the reason why
                   retry entry if not valid
Inputs:            stakeUns - The total stake amount
Outputs:           By function name an unsigned integer that's the bet amount
*/
unsigned askForBetDonePlayingFunc(unsigned& stakeUns) {
    unsigned bet;
    // $ display current stake amount and ask for a bet
    do {
        cout << "Current Stake Amount : " << stakeUns << "\n";
        cout << "What will you bet? ";
        cin >> bet;
        
        // $ check if input amount more than stake amount
        if (bet > stakeUns) {
            cout << "Bet amount cannot be more than your current stake. Please try again.\n";
            continue;
        }
        // (Since bet is unsigned, bet < 0 check is unnecessary)
        break;
    } while (true);
    
    // $ return the valid inputted bet
    return bet;
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
    // $ display Press enter key once or twice to throw the dice
    cout << "Press enter key once or twice to throw the dice... ";
    cin.ignore();
    cin.get();
    
    // $ increment the roll count
    rollCountUns++;
    
    // $ execute the dice roll as two separate rolls
    unsigned die1 = (rand() % 6) + 1;
    unsigned die2 = (rand() % 6) + 1;
    unsigned sum = die1 + die2;
    
    cout << "Die 01 is " << die1 << "\n";
    cout << "Die 02 is " << die2 << "\n";
    cout << "The dice throw results : " << sum << " !" << "\n";
    
    // $ return the dice sum
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
void evaluateRollFunc(unsigned diceRollResultsUns, unsigned& rollCountUns, unsigned& stakeUns, unsigned betUns) {
    // Instant loss if 2,3, or 12
    if (diceRollResultsUns == 2 || diceRollResultsUns == 3 || diceRollResultsUns == 12) {
        cout << "Sorry, you lose." << "\n";
        stakeUns -= betUns;
    }
    // Instant win if 7 or 11
    else if (diceRollResultsUns == 7 || diceRollResultsUns == 11) {
        cout << "We've got ourselves a winner!" << "\n";
        stakeUns += (betUns * 2);
    }
    // Point roll phase
    else {
        unsigned point = diceRollResultsUns;
        cout << "The point is " << point << "\n";
        cout << "Throw em again and hope that luck is on your side!" << "\n";
        
        bool pointWin = pointRollDemBonesFunc(point, rollCountUns);
        if (pointWin) {
            cout << "We've got ourselves a winner!" << "\n";
            stakeUns += (betUns * 2);
        }
        else {
            cout << "Sorry, you lose." << "\n";
            stakeUns -= betUns;
        }
    }
}

/*
Name:             pointRollDemBonesFunc
Function Purpose: Executes the point rolls
Function Design:  Displays the point value.
                  Executes repeating rolls using rollDemBonesFunc until the point or 7 is the result
                  Each roll passes to rollDemBonesFunc() the rollCountUns and receives back the rollCountUns
Inputs:           pointUns      - The point set by the first roll
Inputs/Outputs    &rollCountUns - Reference to total roll count
Outputs:          After point rolls produces a return for a win (true) or a loss (false)
*/
bool pointRollDemBonesFunc(unsigned pointUns, unsigned& rollCountUns) {
    unsigned diceSum;
    // Executes until the point value or 7 is rolled
    while (true) {
        diceSum = rollDemBonesFunc(rollCountUns);
        if (diceSum == pointUns) {
            return true;  // Win: rolled the point
        }
        else if (diceSum == 7) {
            return false; // Loss: rolled a 7
        }
        else {
            cout << "The point is " << pointUns << "\n";
            cout << "Throw em again and hope that luck is on your side!" << "\n";
        }
    }
}
