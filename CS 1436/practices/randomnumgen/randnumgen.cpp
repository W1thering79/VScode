/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    unsigned seed=time(0);
    srand(seed);
    int num1,num2,num3,x;
    const int min=0,max=100;
        
        
    num1=(rand()%(max-min+1)+min);
    num2=(rand()%(max-min+1)+min);
    num3=(rand()%(max-min+1)+min);
    
    cout<<num1<<"\t\t"<<num2<<"\t\t"<<num3;
    
}