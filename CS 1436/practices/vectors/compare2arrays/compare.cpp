#include <iostream>
using namespace std;

bool testPIN(const int[],const int[],int);

int main()
{
    const int num_digits=7;
    int pin1[num_digits]={2,4,1,8,7,9,0};
    int pin2[num_digits]={2,4,6,8,7,9,0};
    int pin3[num_digits]={1,2,3,4,5,6,7};

    if (testPIN(pin1,pin2,num_digits))
    {
        cout<<"Error: pin1 and pin2 report to be the same.\n";
    }
    else
    {
        cout<<"Success:pin1 and pin2 are different.\n";
    }
    if 
}


bool testPIN(const int custPIN[],const int databasePIN[],int size)
{
    for (int index=0; index<size; index++)
    {
        if (custPIN[index])
    }
}