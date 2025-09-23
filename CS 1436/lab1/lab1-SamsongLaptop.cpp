/*
Samuel Song
CS 1436.015 Programming Fundamentals
Due 8/29/24
Completed 8/29/24
Submitted 8/29/24

*/
//This program shows three variables defined on the same line.
#include <iostream> //requires iostream for cout
using namespace std;    //requires std namespace for cout

int main() //start of function main 
{   //open bracket for block of code
    int floors,rooms,suites;    //declares variables as int
    
    floors=15;  //declares a value for floors
    rooms=300;  //declares a value for rooms
    suites=30;  //declares a value for suits
    cout<<"The Grande Hotel has "<<floors<<" floors\n"; //cout the amount of floors
    cout<<"with "<<rooms<<" rooms and "<<suites;    //cout the amount of rooms and suites
    cout<<" suites.\n"; //finishes the sentence of the number of suites 
    return 0;   //ends program
}   //end bracket for block of code 