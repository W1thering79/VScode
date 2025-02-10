#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream outputFile;
    outputFile.open("demofile.txt");

    cout<<"Now writing data to the file. \n";

    outputFile<<"Bach\n";
    outputFile<<"Beethoven\n";
    outputFile<<"Mozart\n";
    outputFile<<"Schubet\n";

    outputFile.close();
    cout<<"Done.\n";
    return 0;
}
