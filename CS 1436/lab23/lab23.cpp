/*
Samuel Song
CS 1436.015 Programming Fundamentals
Due 11/23/24
Completed 11/19/24
Submitted 11/19/24
*/

#include <iostream>
#include <vector>   //required headerfile for vectors
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    //random number generation
    unsigned seed=time(0);
    srand(seed);
    const int min=0, max=9;

    int num=5;
    int usernum;

    //vector declaration
    vector<int> lottery;   
    vector<int> user;

    //forloop to generation random nums for lottery vector
    for (int count=0;count<num;count++)
    {
        int rannum=(rand()%(max-min+1))+min;
        lottery.push_back(rannum);  //inputs random num into vector
    }

    //forloop user input for user vector
    cout<<"\nPlease enter 5 numbers"<<endl;
    for (int count=0;count<num;count++)
    {
        cout<<"Num "<<(count+1)<<":\n";
        cin>>usernum;

        while (usernum<0 || usernum>9)  //validation of input
        {
            cout<<"Enter a valid num. (0-9):";
            cin>>usernum;
        }

        user.push_back(usernum);    //inputs user num into vector
    }

    int match=0;
    for (int count=0;count<num;count++) //forloop to check matching nums
    {
        if (lottery.at(count)==user.at(count))  //checks if values of vectors at index count are equal to each other
        {
            match+=1;   //adds 1 to match if found
        }
    }


    //outputs lottery vector
    cout<<"Lottery Vector:\n";
    for (int val:lottery)
    {
        cout<<val<<"\t";
    }
    cout<<"\n\n";
    
    if (match==5)
    {
        cout<<"CONGRATS! You won the GRAND prize!!"<<endl;  //grand prize if 5 matches
    }
    else 
    {
        cout<<"You had "<<match<<" matching digit(s) with the lottery."<<endl;  //outputs amount of matching nums
    }
}