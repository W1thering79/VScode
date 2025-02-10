#include <iostream>
using namespace std;

void anotherFunction();

int main()
{
    int num=1;  //Local Variable
    cout<<"In Main, num is "<<num<<endl;
    anotherFunction();
    cout<<"Back in main, num is "<<num<<endl;
    return 0;
}

void anotherFunction()
{
    int num=20; //Local Variable
    cout<<"In anotherFunction, num is "<<num<<endl;
}