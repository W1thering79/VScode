#include <iostream>
using namespace std;

int main()
{
    const int size=5;

    int firstArray[size]={5,20,15,20,25};
    int secondArray[size]={5,20,15,20,25};

    bool arraysEqual=true;
    int index=0;

    while (arraysEqual && index<size)
    {
        if (firstArray[index]!=secondArray[index])
        {
            arraysEqual=false;
            index++;
        }

        if (arraysEqual)
        {
            cout<<"The arrays are equal.\n";
        }
        else
        {
            cout<<"The arrays are not equal.\n";
        }
        return 0;
    }
}