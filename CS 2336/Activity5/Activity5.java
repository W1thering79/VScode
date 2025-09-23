import java.util.Scanner;

public class Activity5 
{
    public static void main(String[] args) 
    {
        Scanner input=new Scanner(System.in);
        int randomnum=(int)(100+Math.random()*900);


        
        System.out.println(randomnum);

        int i=0;
        while (i<8)
        {
            System.out.println("Guess the number the random number generated. (100-999)");
            int guess=input.nextInt();

            if (guess<100 || guess>999)
            {
                System.out.println("Error: Invalid number. Not in range (100-999)");
            }


            if (guess==randomnum)
            {
                System.out.println("Congrats! You guessed the number!");
                i=9;
            }

            else if (guess!=randomnum)
            {
                System.out.println("Sorry. Try again.\n");
                i++;
            }
        }
    }
    
}
