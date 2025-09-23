/*
Samuel Song
CS 1436.015 Programming Fundamentals
Due 9/14/24
Completed 9/10/24
Submitted 9/10/24
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{   
    //delcaring all of the variables
    int adulttickets,childtickets,adultticketprice,childticketprice,adulttotal,childtotal,grossprofit;
    double netboxprofit,paiddistributor;
    const double boxprofit=0.2;
    string moviename;
    
    //Get user to input movie name
    cout<<"What is the name of the movie?\n";
    getline(cin,moviename); //getline in case the title has spaces 
    cout<<"\n";
    
    //get adult ticket amount
    cout<<"How many Adult Tickets do you need?\n";
    cin>>adulttickets;
    cout<<"\n";
    
    //get adult ticket price, range of 9-12
    cout<<"What was the price of the Adult Ticket? ($9-$12)\n";
    cin>>adultticketprice;
    cout<<"\n";
    
    //get child ticket amount
    cout<<"How many Child Tickets do you need?\n";
    cin>>childtickets;
    cout<<"\n";
    
    //get child ticket price, range of 3-6
    cout<<"What was the price of the Child Ticket? ($3-$6)\n";
    cin>>childticketprice;
    cout<<"\n";
    
    
    adulttotal=adulttickets*adultticketprice;   //calculates the adult total price
    childtotal=childtickets*childticketprice;   //calculates the child total price
    grossprofit=adulttotal+childtotal;  //Finds the gross profit by combining adult and child totals
    
    netboxprofit=grossprofit*boxprofit;   //Calculate the net box profit by finding 20% of gross
    
    paiddistributor=grossprofit-netboxprofit;   //Total amount distributor will get after 20% is taken
    
    //Cout user inputs and math
    cout<<"Movie Name:"<<moviename<<endl;
    cout<<"Adult Tickets sold:"<<adulttickets<<endl;
    cout<<"Child Tickets sold:"<<childtickets<<endl;
    cout<<"Gross Box Office Profit:$"<<grossprofit<<endl;
    cout<<"Net Box Office Profit:$"<<netboxprofit<<endl;
    cout<<"Amount paid to Distributor:$"<<paiddistributor<<endl;
    
    
}