#include <iostream>
#include <vector>

using namespace std;

void calc(vector<int>);

int main()
{
    vector<int> val (5);

    for (int &temp:val)
    {
        cin>>temp;
    }

    calc(val);
}

void calc(vector<int> num)
{
    for (int i=0;i<num.size();i++)
    {
        cout<<num[i]<<"\t";
    }
    return;
}