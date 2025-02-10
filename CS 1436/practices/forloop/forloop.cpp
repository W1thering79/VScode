#include <iostream>
using namespace std;

int main()
{
    int count=1;
    for ( /*you can initialize the count variable before the loop, semicolon is still required*/;count<=5;/*you can update later as long as its somewhere in loop*/)
    {
        cout<<"hello\t"<<count++<<endl;
    }
}