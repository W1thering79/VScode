/*
Samuel Song
CS 1436.015 Programming Fundamentals
Due 11/18/24
Completed 11/18/24
Submitted 11/18/24
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;

const int cols=10;
const int rows=10;
int bonus;

int main()
{
    int bonuspoints[rows][cols];    

    //Random number generator
    unsigned seed=time(0);
    srand(seed);
    const int min=50, max=1200;

    //function prototypes
    int getTotal(int bonuspoints[rows][cols]);
    double getAverage(int bonuspoints[rows][cols]);
    int getRowTotal(int bonuspoints[][cols], int row);
    int getColumnTotal(int bonuspoints[rows][cols], int col);
    int getHighestInRow(int bonuspoints[][cols], int row);
    int getLowestInRow(int bonuspoints[][cols], int row);


    //opens textfile
    ofstream outputfile;
    outputfile.open("bonuspoints.txt");
    
    //creates random numbers
    for (int count=0;count<rows;count++) {
        for (int count2=0;count2<cols;count2++) {
            int randomNumber=(rand()%(max-min+1))+min;  
            outputfile<<randomNumber<<" ";
        }
        outputfile<<endl; 
    }
    outputfile.close();  //closes file


    //opens file again as inputfile
    ifstream inputfile;
    inputfile.open("bonuspoints.txt");

    for (int rowcount=0;rowcount<rows;rowcount++)
    {
        for (int colcount=0;colcount<cols;colcount++)
        {
            inputfile>>bonuspoints[rowcount][colcount]; //inputs numbers into 10x10 grid
        }
    }
    inputfile.close();  //closes inputfile

    int row;
    int column;

    //ask user for what row and column they want information over
    cout<<"What row would you like to get the total of and the highest/lowest value?"<<endl;
    cin>>row;

    while (row<1||row>10)   //validation (num>1 but num<10)
    {
        cout<<"Enter valid row (1-10)"<<endl;
        cin>>row;   
    }

    cout<<"What column would you like to get the total of?"<<endl;
    cin>>column;

    while (column<1||column>10) //validation (num>1 but num<10)
    {
        cout<<"Enter valid column (1-10)"<<endl;
        cin>>column;
    }


    //Calls functions and outputs
    cout<<"--------------------------------------"<<endl;
    cout<<"Total:"<<getTotal(bonuspoints)<<endl;
    cout<<"Average:"<<getAverage(bonuspoints)<<endl;
    cout<<"Total of row "<<row<<":"<<getRowTotal(bonuspoints,(row-1))<<endl;
    cout<<"Total of column "<<column<<":"<<getColumnTotal(bonuspoints,(column-1))<<endl;
    cout<<"Highest value of row "<<row<<":"<<getHighestInRow(bonuspoints,(row-1))<<endl;
    cout<<"Lowest value of row "<<row<<":"<<getLowestInRow(bonuspoints,(row-1))<<endl;
}



int getTotal(int bonuspoints[][cols])
{
    int total=0;
    for (int rowcount=0;rowcount<rows;rowcount++)
    {
        for (int colcount=0;colcount<cols;colcount++)
        {
            total+=bonuspoints[rowcount][colcount]; //iterates for every row and column and adds to total
        }
    }
    return total;
}

double getAverage(int bonuspoints[rows][cols])
{
    cout<<fixed<<setprecision(2);
    double avg=getTotal(bonuspoints)/100.0; //divides the total points by 100 for average
    return avg;
}


int getRowTotal(int bonuspoints[rows][cols],int row)
{
    int totalrow=0;
    for (int colcount=0;colcount<cols;colcount++) 
    {
        totalrow+=bonuspoints[row][colcount];   //iterates for each column in user picked row and adds to variable "totalrow"
    }
    return totalrow;
}


int getColumnTotal(int bonuspoints[rows][cols],int cols)
{
    int totalcol=0;
    for (int rowcount=0;rowcount<rows;rowcount++)   
    {
        totalcol+=bonuspoints[rowcount][cols]; //iterates for each row in user picked col and adds to variable "totalcol"
    }
    return totalcol;
}


int getHighestInRow(int bonuspoints[rows][cols],int row)
{
    int highest=bonuspoints[row][0];    //defauts highest to user picked row, column 0
    for (int colcount=1;colcount<cols;colcount++) 
    {
        if (bonuspoints[row][colcount]>highest) 
        {
            highest=bonuspoints[row][colcount]; //iterates for each column and checks if the value in x column is greater than the previous highest
        }
    }
    return highest;
}


int getLowestInRow(int bonuspoints[rows][cols],int row)
{
    int lowest=bonuspoints[row][0]; //defaults lowest to user picked row, column 0
    for (int colcount=1;colcount<cols;colcount++) 
    {
        if (bonuspoints[row][colcount]<lowest) 
        {
            lowest=bonuspoints[row][colcount];  //iterates for each column and checks if the value in x column is less than the previous lowest
        }
    }
    return lowest;
}