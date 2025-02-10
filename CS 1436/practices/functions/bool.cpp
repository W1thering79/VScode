#include <iostream>
using namespace std;

bool showSum(int,int,int);

int main()
{
    int mysum;
    int value1, value2, value3;
    bool select;

    cout<<"enter 3 int and I will display ";
    cout<<"their sum: ";
    cin>>value1>>value2>>value3;

    mysum=showSum(value1,value2,value3);
    if (mysum>50)
    {
        select=true;
    }
    else 
    {
        select=false;
    }


    if (select==true)
    {
        cout<<mysum;
    }
    else
    {
        cout<<"lost the game";
        return 0;
    }
}
    
bool showSum(int num1,int num2, int num3)
{
    int sum;
    bool val;

    sum=(num1+num2+num3);

    if (sum>=50)
    {
        return true;
    }
    else
    {
        return false;
    }
}