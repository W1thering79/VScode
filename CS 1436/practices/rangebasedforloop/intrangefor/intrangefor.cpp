#include <iostream>
using namespace std;

int main()
{
    const int value=5;
    int numbers[value]={10,20,30,40,50};

    for (int val:numbers)
    {
        cout<<val<<endl;
    }
    return 0;
}