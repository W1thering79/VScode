#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream myoutputFile;
    int number1,number2,number3;

    myoutputFile.open("Numbers.txt");

    cout<<"Enter a number: ";
    cin>>number1;
    myoutputFile<<number1<<endl;

    cout<<"Enter another number: ";
    cin>>number2;
    myoutputFile<<number2<<endl;

    cout<<"Enter the last number: ";
    cin>>number3;
    myoutputFile<<number3<<endl;

    cout<<"The num were saved to the file";

    myoutputFile.close();
    cout<<"Done.\n";
    return(0);
}