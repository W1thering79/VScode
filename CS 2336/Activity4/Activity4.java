import java.util.Scanner;

public class Activity4 
{
    public static void main (String[] args)
    {

        Scanner input=new Scanner(System.in);

        System.out.println("Please input a number to determine if it is an ASCII code: ");
        int num=input.nextInt();

        if (num<1 || num>122)
        {
            System.out.println("Error, Invalid number. Must be in the range of 1-122. Try again.");
            num=input.nextInt();
            
        }

        if (num<48 && num!=0)
        {
            System.out.println("The number you inputted is not an alphanumerical.");
        }
        else if (num>=48 && num<=57)
        {
            System.out.println("The number you inputted is an ASCII code for a number.");
        }
        else if (num>=65 && num<=90)
        {
            System.out.println("The number you inputted is an ASCII code for capital letters.");
        }
        else if (num>=97 && num<=122)
        {
            System.out.println("The number you inputted is an ASCII code for lowercase letters.");
        }

        input.close();
    }    
}
