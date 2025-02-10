#include <iostream>
using namespace std;

int main()
{
    string planets[]={"Mercury","Venus","Earth","Mars","Jupiter","Saturn","Uranus","Neptune","Pluto (Dwarf)"};

    cout<<"Here are the planets:\n";

    for (string temp:planets)
    {
        cout<<temp<<endl;
    }
    return 0;
}