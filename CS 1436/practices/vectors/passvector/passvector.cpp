#include <iostream>
#include <vector>

using namespace std;

double avgVector(vector<int>);

int main()
{
    vector<int> values;
    int numValues;
    double average;

    cout<<"how many values do you wish to average?";
    cin>>numValues;

    for (int count=0; count<numValues; count++)
    {
        double tempValue;
        cout<<"Enter a value: ";
        cin>>tempValue;
        values.push_back(tempValue);
    }

    average=avgVector(values);
    cout<<"Average: "<<average<<endl;
    return 0;
}

double avgVector(vector<int> vect)
{
    int total=0;
    double avg;

    if (vect.empty())
    {
        cout<<"No values to average.\n";
        avg=0.0;
    }
    else
    {
    for (int count=0; count<vect.size(); count++)
    {
        total+=vect[count];
        avg=static_cast<double>(total)/vect.size();
        return avg;
    }
    }
}