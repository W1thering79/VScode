#include <iostream>
using namespace std;

bool isEven(int);

int main()
{
    int val;
    cout<<"Enter an int and I will tell you ";
    cout<<"if it is even or odd: "<<endl;
    cin>>val;

    if (isEven(val))
    {
        cout<<val<<" is even.\n";
    }
    else
    {
        cout<<val<<" is odd.\n";
        return 0;
    }
}

bool isEven(int number)
{
    bool status;
    if (number%2==0)
    {
        status=true;
        return status;
    }
    else
    {
        status=false;
        return status;
    }
    
}