#include <iostream>
using namespace std;

int main()
{
    const int NUM_EMPLOYEES=6;
    int hours [NUM_EMPLOYEES];

for (int index=0; index<NUM_EMPLOYEES;index++)
{
    cout<<"Enter the hours woked by employee "<<(index+1)<<": ";
    cin>>hours[index];
}

cout<<"the hours you entered are:";
for (int index=0; index<NUM_EMPLOYEES;index++)
{
    cout<<" "<<hours[index];
    cout<<endl;
}
return 0;

}