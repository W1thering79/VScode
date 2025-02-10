#include <iostream>
using namespace std;

void anotherFunction();
int num=20; //Global Variable

int main()
{
    cout<<"In Main, num is "<<num<<endl;
    anotherFunction();
    cout<<"Back in main, num is "<<num<<endl;
    return 0;
}

void anotherFunction()
{
    cout<<"In anotherFunction, num is "<<num<<endl;
    int num=55;
    cout<<"But it is now changed to "<<num<<endl;
}