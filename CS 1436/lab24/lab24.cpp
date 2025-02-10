/*
Samuel Song
CS 1436.015 Programming Fundamentals
Due 12/2/24
Completed 11/21/24
Submitted 11/21/24
*/

#include <iostream>
using namespace std;

const int valid=18; //sets array to have 18 values
int validnum[valid]={5658845,4520125,7895122,8777541,8451277,1302850,
                    8080152,4562555,5552012,5050552,7825877,1250255,
                    1005231,6545231,3852085,7576651,7881200,4581002};
int accnum;


int main()
{
    cout<<"Input a charge account number.\n";
    cin>>accnum;
    bool isValid=false; //validation of user inputted num being in 'validnum' array
    for (int count=0;count<valid;count++)
    {
        if (accnum==validnum[count])
        {
            isValid=true;   //sets bool to true if finds a number that are equal
            break;  //stops loop
        }
    }

    //outputs if inputted num is valid or not using bool 'isValid'
    if (isValid==true)  
    {
        cout<<"The number you inputted is valid.";
    }
    else 
    {
        cout<<"The number you inputted is invalid";
    }
}