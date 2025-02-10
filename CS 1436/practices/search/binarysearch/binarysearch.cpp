#include <iostream>

using namespace std;

int binarySearch(int [],int, int);
const int SIZE=20;

int main()
{
    int tests[SIZE]={
                    101,142,147,189,199,207,222,
                    234,289,296,310,319,388,394, 
                    417,429,447,521,536,600
                    };
    int results;
    int empID;

    cout<<"Enter the employee ID you wish to search for:";
    cin>>empID;

    results=binarySearch(tests,SIZE,empID);

    if (results==-1)
    {
        cout<<"That number does not exist in the array.";
    }
    else
    {
        cout<<"That ID number is at index ";
        cout<<(results+1)<<endl;
    }
}

int binarySearch(int array[],int numelems, int value)
{
    int first=0;
    int last=numelems-1;
    int middle;
    int position=-1;
    bool found=false;
    int counter=0;

    while (!found&&first<=last)
    {
        counter++;
        middle=(first+last)/2;
        if (array[middle]==value)
        {
            found=true;
            position=middle;
        }
        else if (array[middle]>value)
        {
            last=middle-1;
        }
        else
        {
            first=middle+1;
        }
    }
    cout<<"\n"<<counter<<"\n";
    return position;
}