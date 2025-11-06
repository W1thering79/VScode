import java.util.Scanner;   //import needed for scanners

public class Activity3 
{
    public static void main(String[] args) 
    {
        Scanner input=new Scanner(System.in);
        
        System.out.println("Have you taken either 2336 or 2337? (0 for no, 1 for yes)");
        int choice=input.nextInt();

        //If else statement to validate if user has taken a course
        if (choice==0)
        {
            System.out.println("You are not elligible to take 3345.");  //no statement
        }
        else if (choice==1)
        {
            System.out.println("Have you taken 2305? (0 for no, 1 for yes)");   //yes statement, goes to next question
            choice=input.nextInt();

            if (choice==0)
            {
            System.out.println("you are not elligible to take 3345.");  //no statement
        }
        else if (choice==1)
        {
            System.out.println("Are you currently enrolled in 3377? (0 for no, 1 for yes)");    //yes statement, goes to next question
            choice=input.nextInt();

            if (choice==0)
            {
                System.out.println("You are not elligible to take 3345.");  //no statement
            }
            else if (choice==1)
            {
                System.out.println("You are elligible to take 3345. Congrats.");    //yes statement, elligible to take course.
            }
            
        }

        }

    }    
}
