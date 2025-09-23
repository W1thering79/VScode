#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int score1,score2,score3;
    double average;
    
    cout<<"Get scores: \n";
    cin>>score1>>score2>>score3;
    
    average=(score1+score2+score3)/3.0;
    cout<<fixed<<showpoint<<setprecision(1);
    cout<<"Average is: "<<average<<endl;
    
    if (average>95)
        cout<<"congrats, thats a high score!";
    return 0;
}