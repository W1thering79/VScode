/*
Samuel Song
CS 1436.015 Programming Fundamentals
Due 10/28/24
Completed 10/22/24
Submitted 10/22/24
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>  //required library for outputfile
using namespace std;

int main()
{
    //Declaring variables and assigns nums to start
    int smallest=2000;
    int largest=0;
    int count=0;
    int totalvalue;
    double avg;
    int rannum;
    
    //Random number generating using time
    unsigned seed=time(0);
    srand(seed);
    
    //Random num generating the min value
    int r1;
    const int MIN=1, MAX=100;
    r1=(rand()%(MAX-MIN+1)+MIN);

    //Random num generating the max value
    int r2;
    const int MIN2=500, MAX2=5000;
    r2=(rand()%(MAX2-MIN2+1)+MIN2);

    //Random num generating using the random min and max to determine loop iteration amount
    int programNumber;
    const int MIN3=r1, MAX3=r2;
    programNumber=(rand()%(MAX3-MIN3+1)+MIN3);

    //Creating outputfile
    ofstream outputfile;
    outputfile.open("random.txt");
    
    
    for (count;count<=programNumber;count++)    //forloop, repeats depending on the random number generation
    {
        //randomly generates numbers for list
        const int MIN4=100, MAX4=2000;
        rannum=(rand()%(MAX4-MIN4+1)+MIN4);
        if (rannum<smallest)    //Checks for smallest number to replace variable
        {
            smallest=rannum;
        }
        else if (rannum>largest)    //Checks for largest number to replace variable
        {
            largest=rannum;
        }
        
        totalvalue+=rannum; //running total of randomly generated numbers
        outputfile<<rannum; //inputs random num into list
        outputfile<<endl;
    }
    avg=totalvalue/count;   //calculates the average value
    
    //Outputs all the information
    cout<<"\n\n";
    cout<<"Count:"<<count<<endl;
    cout<<"Largest num:"<<largest<<endl;
    cout<<"Smallest num:"<<smallest<<endl;
    cout<<"Sum of all nums:"<<totalvalue<<endl;
    cout<<"Average of numbers:"<<avg<<endl;
    
    //closes the outputfile
    outputfile.close();
    
}   