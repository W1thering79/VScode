#include <iostream>
using namespace std;

void doubleNum(int &);

int main()
{
    int value=4;

    cout<<"In main, value is "<<value<<endl;
    cout<<"Now calling doubleNum..."<<endl;
    doubleNum(value);
    cout<<"Now back in main. Value is "<<value<<endl;
    return 0;
}

void doubleNum (int &refVar)
{
    refVar*=2;
}