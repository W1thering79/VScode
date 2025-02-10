#include <iostream>
using namespace std;

int main()
{
    int row, col;
    
    for (row=1;row<=5;row++)
    {
        for (col=10;col<=15;col++)
        {
            if (col==11)
            continue;   //skips col 11
            
            cout<<"Row:"<<row<<" Col:"<<col<<"\t";
        }
    }
}