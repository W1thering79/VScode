// main.cpp : Defines the entry point for the console application.

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

unsigned askForInititalStakeAmountFunc();
unsigned askForBetDonePlayingFunc(unsigned& stakeUns);
unsigned rollDemBonesFunc(unsigned& rollCountUns);
void     evaluateRollFunc(unsigned diceRollResultsUns, unsigned& rollCountUns, unsigned& stakeUns, unsigned betUns);
bool     pointRollDemBonesFunc(unsigned pointUns, unsigned& rollCountUns);

int main() {
    // Seed the random number generator once at program start
    srand(static_cast<unsigned>(time(0)));

    unsigned stakeUns = askForInititalStakeAmountFunc();
    unsigned betUns = 0;
    unsigned rollCountUns = 0;
    unsigned diceRollResultsUns = 0;

    // Game loop: continue as long as player has money and hasn't chosen to quit (bet = 0)
    do {
        betUns = askForBetDonePlayingFunc(stakeUns);
        if (betUns == 0) {
            break; // Player chooses to end the game
        }
        // Roll the dice
        diceRollResultsUns = rollDemBonesFunc(rollCountUns);
        // Evaluate the roll result, update stake and possibly process point mode
        evaluateRollFunc(diceRollResultsUns, rollCountUns, stakeUns, betUns);
        cout << "Current stake: $" << stakeUns << "\n\n";
    } while (betUns != 0 && stakeUns != 0);

    // Out of loop: determine reason for exit
    if (betUns == 0) {
        cout << "\nYou have chosen to end the game. Thanks for playing!\n";
    } else {
        cout << "\nYou are out of money. Game over.\n";
    }

    // Display game statistics
    cout << "Total number of dice rolls: " << rollCountUns << "\n";
    cout << "Final stake amount: $" << stakeUns << "\n";

    // Hold the screen before exiting
    cout << "Press Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    exit(EXIT_SUCCESS);
}

/*
Name:              askForInitialStakeAmountFunc
Function Purpose : Retrieves the initial money from prompting the user
Function Design:   Checks if the input stake amount the player enters a proper amount:
                   stakeStartUns > 0
Inputs:            None
Outputs:           An unsigned integer representing the stake amount
*/
unsigned askForInititalStakeAmountFunc() {
    unsigned stakeStartUns = 0;
    while (true) {
        cout << "Enter your initial stake amount (must be > 0): ";
        cin >> stakeStartUns;

        if (cin.fail() || stakeStartUns <= 0) {
            cout << "You have to enter a positive amount of money to bet with. Try again!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear rest of line
        break;
    }
    return stakeStartUns;
}

/*
Name: askForBetDonePlayingFunc
Function Purpose : Asks for what the player will bet and checks for validity
Function Design:   Checks for valid entry against the current stake amount.
Inputs:            stakeUns - The total stake amount available to bet
Outputs:           An unsigned integer representing the bet amount
*/
unsigned askForBetDonePlayingFunc(unsigned& stakeUns) {
    unsigned bet = 0;
    while (true) {
        cout << "Your current stake is $" << stakeUns << ".\n";
        cout << "Enter your bet amount (enter 0 to quit): ";
        cin >> bet;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a valid number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (bet > stakeUns) {
            cout << "Bet amount cannot be more than your current stake. Please try again.\n";
            continue;
        }
        if (bet < 0) { // this check is redundant with unsigned, but kept for clarity
            cout << "Bet amount must be positive. Please try again.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;
    }
    return bet;
}

/*
Name:             rollDemBonesFunc
Function Purpose: Generates an independent random number for each die,
                  calculates the roll sum, and increments the roll counter.
Inputs/Outputs:   &rollCountUns - Reference to the total roll count in the game
Outputs:          The sum of the two rolled dice
*/
unsigned rollDemBonesFunc(unsigned& rollCountUns) {
    cout << "\nPress Enter to roll the dice...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // Increment the roll count
    rollCountUns++;

    // Generate two random numbers from 1 to 6
    unsigned die1 = (rand() % 6) + 1;
    unsigned die2 = (rand() % 6) + 1;
    unsigned sum = die1 + die2;

    cout << "You rolled a " << die1 << " and a " << die2 << " for a total of " << sum << ".\n";
    return sum;
}

/*
Name: evaluateRollFunc
Function Purpose: Check for a winning roll, a losing roll, or a point roll result.
                  Adjust stakeUns using betUns for win or loss result.
Inputs:           diceRollResultsUns - The dice roll sum
                  betUns             - The placed bet
Inputs/Outputs:   &rollCountUns      - Reference to tally of total rolls
                  &stakeUns          - Reference to the total money at stake
*/
void evaluateRollFunc(unsigned diceRollResultsUns, unsigned& rollCountUns, unsigned& stakeUns, unsigned betUns) {
    // Immediate loss conditions: 2, 3, or 12
    if (diceRollResultsUns == 2 || diceRollResultsUns == 3 || diceRollResultsUns == 12) {
        cout << "Craps! You lose your bet of $" << betUns << ".\n";
        stakeUns -= betUns;
    }
    // Immediate win conditions: 7 or 11
    else if (diceRollResultsUns == 7 || diceRollResultsUns == 11) {
        cout << "Congratulations! You win $" << betUns << "!\n";
        stakeUns += betUns;
    }
    // Point roll: any other result becomes the 'point'
    else {
        unsigned point = diceRollResultsUns;
        cout << "Your point is now set to " << point << ". Keep rolling until you hit your point again (win) or roll a 7 (lose).\n";
        bool winPoint = pointRollDemBonesFunc(point, rollCountUns);
        if (winPoint) {
            cout << "You hit your point! You win $" << betUns << "!\n";
            stakeUns += betUns;
        } else {
            cout << "You rolled a 7 before hitting your point. You lose $" << betUns << ".\n";
            stakeUns -= betUns;
        }
    }
}

/*
Name:             pointRollDemBonesFunc
Function Purpose: Executes the point rolls.
                  Continues rolling until the point or a 7 is rolled.
Inputs:           pointUns      - The point set by the first roll
Inputs/Outputs:   &rollCountUns - Reference to the total roll count
Outputs:          Returns true if the point is hit again (win), false if a 7 is rolled (loss)
*/
bool pointRollDemBonesFunc(unsigned pointUns, unsigned& rollCountUns) {
    unsigned pointRollUns = 0;
    while (true) {
        pointRollUns = rollDemBonesFunc(rollCountUns);
        if (pointRollUns == pointUns) {
            return true;  // Player wins by rolling the point again
        } else if (pointRollUns == 7) {
            return false; // Player loses by rolling a 7
        }
        // Otherwise, continue rolling
    }
}
