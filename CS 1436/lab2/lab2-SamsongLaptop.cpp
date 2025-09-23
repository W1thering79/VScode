/*
Samuel Song
CS 1436.015 Programming Fundamentals
Due 9/3/24
Completed 9/3/24
Submitted 9/3/24
*/

#include <iostream> //need iostream for cout
using namespace std;    //requires namespace std for cout

int main()
{
    int totalcustomers; //declares the totalcustomer
    double purchaseenergy,likescitrus;    //declares the drinksenergy,likescitrus,energydrink,citrusflavor
    double percentenergydrink=0.18; //declaring the percentage of energy drinkers
    double percentcitrusflavor=0.56;    //declares the percentage of people who like citrus flavor that drink energy
    totalcustomers=95400;   //assigns 95400 customers to variable totalcustomers
    
    purchaseenergy=totalcustomers*percentenergydrink; //multiplies the total customers to the percentage of people who like energy drinks
    cout<<"Out of the total surveyed customers of "<<totalcustomers<<","<<endl<<purchaseenergy<<" purchase one or more energy drinks.\n\n";
    
    
    likescitrus=purchaseenergy*percentcitrusflavor;    //multiplies the amount of people who purcahse energy drinks to the percentage of people who like the citrus flavor  
    cout<<"Of those who purchase one or more energy drinks per week, "<<endl<<likescitrus<<" prefer the citrus-flavored energy drinks.";
 
    
    
    
}