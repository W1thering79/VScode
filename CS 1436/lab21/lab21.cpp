/*
Samuel Song
CS 1436.015 Programming Fundamentals
Due 11/23/24
Completed 11/12/24
Submitted 11/12/24
*/

#include <iostream>
#include <iomanip>
using namespace std;

//declares numstudent and numtest as a constant
const int numstudents=5;
const int numtests=4;

//function prototypes
void studentscores (double scores[],int index); //array argument
double averagegrade (double scores[]);  //array argument
char lettergrade (double avg);

int main()
{
    //sets up arrays
    string name[numstudents];
    double scores[numtests];
    double gradeavg[numstudents];
    char grade[numstudents];

    int index=0;
    for (string &student:name)  //range-based for loop
    {
        cout<<"What is the name of student "<<(index+1)<<":\n";
        cin>>student;
        index++;
    }

    cout<<"\n";

    for (int index=0;index<numstudents;index++) //loops to get 4 test scores
    {
        cout<<"Enter the 4 test scores for student "<<(index+1)<<":\n"; 

        //Calls functions
        studentscores(scores,index);
        gradeavg[index]=averagegrade(scores);
        grade[index]=lettergrade(gradeavg[index]);
        cout<<"\n";

    }

    //outputs info and loops for each student
    cout<<fixed<<setprecision(2);
    for (int index=0;index<numstudents;index++) 
    {
        cout<<"\n";
        cout<<"Student:" << name[index] << "\n";
        cout<< "Average Score:" << gradeavg[index] << "\n";
        cout<< "Grade:" << grade[index] << "\n\n";
    }
    return 0;
}

//Function to calcualte student scores 
void studentscores(double scores[], int studentIndex) 
{
for (int index=0;index<numtests;index++) 
{
    do
    {
        cout<<"Score "<<(index+1)<<":"; //inputs scores
        cin>>scores[index];
        if (scores[index]<0||scores[index]>100) //if scores are invalid outputs error message
        {
            cout << "Invalid score. Please enter a value between 0 and 100.\n";
        }
        } while (scores[index]<0||scores[index]>100);   //validates scores to be in range 0-100
    }
}

//Function to calculate the average grade
double averagegrade(double scores[])
{
    double lowestgrade=scores[0];
    double sum=0;
    
    for (int index=0;index<numtests;index++)    //checks for lowest grade 
    {
        if (scores[index]<lowestgrade)
        {
            lowestgrade=scores[index];
        }
        sum+=lowestgrade;
    } 
    return (sum-lowestgrade)/(numtests-1);  //outputs average grade after subtracting lowest grade
}

//Function to output the letter grade based on the average grade
char lettergrade(double avg)
{
    if (avg>=90)
    {
        return 'A';
    }
    else if (avg>=80)
    {
        return 'B';
    }
    else if (avg>=70)
    {
        return 'C';
    }
    else if (avg>=60)
    {
        return 'D';
    }
    else
    {
        return 'F';
    }
}