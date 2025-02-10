/*
Samuel Song
CS 1436.015 Programming Fundamentals
Due 10/23/24
Completed 10/17/24
Submitted 10/17/24
*/

#include <iostream>
#include <fstream>  //required header for outputfile
using namespace std;

int main()
{
    //Declaration of variables
    int citypop;
    int astricks;  

    //Creates outputfile 
    ofstream outputfile;
    outputfile.open("Song.txt");    //names outputfile my last name

    for (int count=1;count<=10;count++) //for loop, 10 iterations for 10 populations
    {
        cout<<"What is the population of Texas city "<<count<<"?\n";
        cin>>citypop;
        astricks=citypop/1000;  //divide citypop by 1000 to get just the thousands
        outputfile<<"City "<<count<<":";
        for (int count2=1;count2<=astricks;count2++)    //for loop, iterates however many astricks is needed
        {
            outputfile<<"*";
        }
        outputfile<<endl;   //endl for formating
    }
    
    outputfile.close(); //Closes the output file
    cout<<"Done.";  
    return (0);
}