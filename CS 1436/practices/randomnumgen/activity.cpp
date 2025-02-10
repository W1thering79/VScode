#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    unsigned seed=time(0);
    srand(seed);
    
    const int MIN=1, MAX=75;
    int num;

    for(int row=1;row<=5;row++)
    {
        for(int col=1;col<=6;col++)
        {
            num=(rand()%(MAX-MIN+1)+MIN);
            cout<<num<<"\t";
        }
    }
    cout<<endl;
}