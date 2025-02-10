/*
Samuel Song
CS 1436.015 Programming Fundamentals
Due 10/4/24
Completed 9/26/24
Submitted 9/26/24
*/


#include <iostream>
using namespace std;

int main()
{
    //Declaring variables
   int calories;
   int fatgrams;
   double fatcalories;
   double calpercent;
   double fatcontent;
    
    //Asks user input for the amount of calories in the food
   cout<<"How many calories are in the food?"<<endl;
   cin>>calories;
   
   //Validating to make sure calories is greater than 0
   if (calories<=0)
   {
       cout<<"Please input a valid number of Calories (greater than 0)";
   }
   
   else
   {
   cout<<"How many fat grams are in the food?"<<endl;   //Asks for user input of fat grams in food
   cin>>fatgrams;
   }
    
    //Validating the fat grams to be greater than 0
   if (fatgrams<=0)
   {
       cout<<"Please input a valid number of Fat Grams (greater than 0)";
   }
   
   else
   {
   fatcalories=fatgrams*9;  //Calculates the calories from fat 
   }
   
   //Validates that the fat clories is less than the total calories
   if (fatcalories>calories)
   {
       cout<<"Error, Calories and or Fat Grams were inputted incorrectly.";
   }
   else
   {
       calpercent=(fatcalories/calories)*100;   //Calculates the percent of  calories from fat
;
    
       if (calpercent<30)   //Checks if the percent of calories from fat is less than 30% of total calories
       {
           cout<<"Food item is low in fat.";
       }
       else
       {
           //Outputs the Percent of Calories
           cout<<"Percentage of Calories from the Fat is:"<<calpercent<<"%";
       }
   }
   
   
}