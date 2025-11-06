import java.util.Scanner;
public class Activity6 
{
    public static void main(String[] args) 
    {
        System.out.println("Calculator");
        System.out.println("1. Addition");
        System.out.println("2. Subtraction");
        System.out.println("3. Multiplication");
        System.out.println("4. Division");
        System.out.println("5. Modulo/Remainder");

        System.out.println("Which operand do you wish to do?");
        Scanner input=new Scanner(System.in);

        int choice=input.nextInt();

        if (choice==1)
        {
            Addition();
            System.exit(0);
        }
        else if (choice==2)
        {
            Subtraction();
            System.exit(0);
        }
        else if (choice==3)
        {
            Multiplication();
            System.exit(0);
        }
        else if (choice==4)
        {
            Division();
            System.exit(0);
        }
        else if(choice==5)
        {
            Modulo();
            System.exit(0);
        }


    }   
    static void Addition()
    {
        Scanner input=new Scanner(System.in);
        System.out.println("Give me two values to add together.");
        System.out.print("Num1:");
        int num1=input.nextInt();
        System.out.print("Num2:");
        int num2=input.nextInt();

        int sum=num1+num2;
        System.out.println("The sum of the two values you provided is "+sum);
    }

    static void Subtraction()
    {
        Scanner input=new Scanner(System.in);
        System.out.println("Give me two values to Subtract together.");
        System.out.print("Num1:");
        int num1=input.nextInt();
        System.out.print("Num2:");
        int num2=input.nextInt();

        int subtract=num1-num2;
        System.out.println("The result of the two values you provided is "+subtract);
    }

    static void Multiplication()
    {
        Scanner input=new Scanner(System.in);
        System.out.println("Give me two values to multiply together.");
        System.out.print("Num1:");
        int num1=input.nextInt();
        System.out.print("Num2:");
        int num2=input.nextInt();

        int multiply=num1*num2;
        System.out.println("The result of the two values you provided is "+multiply);
    }

    static void Division()
    {
        Scanner input=new Scanner(System.in);
        System.out.println("Give me two values to divide together.");
        System.out.print("Num1:");
        int num1=input.nextInt();
        System.out.print("Num2:");
        int num2=input.nextInt();

        int divide=num1/num2;
        System.out.println("The result of the two values you provided is "+divide);
    }

    static void Modulo()
    {
        Scanner input=new Scanner(System.in);
        System.out.println("Give me two values to find the remainder of.");
        System.out.print("Num1:");
        int num1=input.nextInt();
        System.out.print("Num2:");
        int num2=input.nextInt();

        int modulo=num1%num2;
        System.out.println("The remainder of the two values you provided is "+modulo);
    }
}
