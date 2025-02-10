#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> numbers{10,20,30,40,50};

    cout<<"Original Vector\n";
    cout<<"---------------\n";
    for (int val:numbers)
    {
        cout<<val<<endl;
    }

    numbers.push_back(60);
    cout<<"\nPush_back(60)"<<endl;
    cout<<"--------------\n";
    for (int val:numbers)
    {
        cout<<val<<endl;
    }
    
    numbers.pop_back();
    cout<<"\nPop_back()"<<endl;
    cout<<"-------------\n";
    for (int val:numbers)
    {
        cout<<val<<endl;
    }

    int size=numbers.size();
    cout<<"\nVector size"<<endl;
    cout<<"------------\n";
    cout<<"Size:"<<size<<endl;

    numbers.clear();
    cout<<"\nclear()"<<endl;
    cout<<"-----------\n";
    for (int val:numbers)
    {
        cout<<val<<endl;
    }

    bool empty=numbers.empty();
    cout<<"\nempty()"<<endl;
    cout<<"-------------\n";
    if (empty=1)
    {
        cout<<"True";
    }
    else 
    {
        cout<<"False";
    }

/*
    int num[10]={1,2,3,4,5,6,7,8,9,10};
    vector<int> num(numbers);
    cout<<"\nDeclare vector initialized to another vector"<<endl;
    cout<<"-----------\n";
    for (int val:numbers)
    {
        cout<<val<<endl;
    }
*/


}
