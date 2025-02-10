/*
Samuel Song
CS 1436.015 Programming Fundamentals
Due 11/11/24
Completed 11/10/24
Submitted 11/10/24
*/

#include <iostream>
using namespace std;

int main()
{
    string salsa[5]={"Mild","Medium","Sweet","Hot","Zesty"};    //declaration of different salsa type in array
    
    //Sets up int array for number of jars
    const int amount=5;
    int jar[amount];

    //Variable declaration
    int jarnum;
    int totaljars=0;
    string highest;
    string lowest;
    int smallest=0;
    int largest=0;

    for (int index=0;index<amount;index++)  //loop to find how many jars of each salsa types
    {
        cout<<"How many "<<salsa[index]<<" jars are there?\n";
        cin>>jarnum;
        totaljars+=jarnum;  //adds the num of jars to the total amount of jars
        jar[index]=jarnum;  //sets the index value of int array depending on user input  
        cout<<"\n";

        while (jarnum<0)    //valids num of jar input to be positive
        {
            cout<<"Enter a valid number of jars. (>0)\n";
            cin>>jarnum;
        }
    }
    

    cout<<"Salsa per type:\n";
    cout<<"--------------------\n";
    for (int index=0;index<amount;index++)  //for loop to output the salsa amount per type
    {
        cout<<salsa[index]<<":"<<jar[index]<<"\n";
    }

    cout<<"Total Jars:"<<totaljars<<endl;   //outputs total amount of jars
    cout<<"--------------------\n";


    for (int index=1;index<amount;index++)  //forloop to find the smallest and largest jar of salsa type
    {
        if (jar[index]<jar[smallest]) 
        {
            smallest=index;
        }
        if (jar[index]>jar[largest]) 
        {
            largest=index;
        }
    }

   //outputs the lowest/highest selling salsa type
   cout<<"Lowest amount of salsa type sold: "<<salsa[smallest]<<endl;
   cout<<"Highest amount of salsa type sold: "<<salsa[largest]<<endl;
}