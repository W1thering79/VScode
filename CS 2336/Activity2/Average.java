import java.util.Scanner;

public class Average {
    public static void main (String[] args) 
    {

        double num1;
        double num2;
        double num3;
        double sum;
        double average;

        Scanner input=new Scanner(System.in);

        System.out.println("What is number 1?");
        num1=input.nextDouble();
        
        System.out.println("What is number 2?");
        num2=input.nextDouble();

        System.out.println("What is number 3?");
        num3=input.nextDouble();

        input.close();

        sum=(num1+num2+num3);
        average=sum/3;

        System.out.println("The average of the three values is "+average+".");

    }
}
