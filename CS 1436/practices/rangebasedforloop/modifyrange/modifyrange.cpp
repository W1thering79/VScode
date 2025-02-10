#include <iostream>
using namespace std;

int main()
{
    const int SIZE=5;
    int numbers[5];

    for (int &val:numbers)
    {
        cout<<"Enter an Integar value:";
        cin>>val;
    }

    cout<<"Here are the values you entered:\n";
        for (int val:numbers)
        {
            cout<<val<<endl;
        }
}