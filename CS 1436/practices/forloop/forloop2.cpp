#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const int min_number=1;
    const int max_number=10;

    int num;
    cout<<"number number squared\n";
    cout<<"-----------------------\n";

    for (num=min_number;num<=max_number;num++)
    cout<<num<<"\t\t"<<pow(num,2.0)<<endl;
}