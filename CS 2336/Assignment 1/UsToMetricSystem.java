import java.util.Scanner;   //Import needed to use Scanner


public class UsToMetricSystem 
{
    public static void main(String[] args)
    {

        Menu(); //Call Menu Method

    } 

         static void Menu()
        {
            Scanner input=new Scanner(System.in);

            //Menu
            System.out.println("1. Convert Fahrenheit to Celsius.");
            System.out.println("2. Convert Gallons to Liter.");
            System.out.println("3. Convert Pounds to Kilograms.");
            System.out.println("4. Convert Miles to Kilometers.");
            System.out.println("5. Convert Inch to Centimeters.");
            System.out.println("6. Convert Yards to Meters.");
            System.out.println("7. Exit Program.\n");

            System.out.println("Please pick an option:");
            
            //Get User Integar input 
            int Choice=input.nextInt();

            //Check if User Inputted Value is Valid (in range 1-7)
            if (Choice>7 || Choice<1)
            {
                System.out.println("Please pick a valid number. Number must be in the Range 1-7.\n");
                Menu();
            }

            MenuChoice(Choice);     //Call MenuChoice Method with User Inputted Variable as a parameter 

            input.close();  //Close Scanner to prevent leaks

        }

    //Menu Choice Method with parameter integar x
    static void MenuChoice(int x)
    {
        Scanner input=new Scanner(System.in);

        switch (x)  //Switch statement, used instead of If Else for readability. Uses user inputted integar as a parameter to determine which case to output
        {
            case 1:
                System.out.println("Please input the Fahrenheit degrees you wish to convert to Celsius.");
                double FDegree=input.nextDouble();
                double Celsius=(((double) 5/9)*(FDegree-32));
                System.out.format("Your inputted "+FDegree+" degree Fahrenheit is approximately %.2f degrees Celsius.\n\n",Celsius);    //Used static method .format for two decimal places when outputting result
                Menu(); //Calls Menu Method again to create a Loop
                break;  //stops switch statement

            case 2:
                System.out.println("Please input the amount of Gallons you wish to convert to Liters.");
                double Gallons=input.nextDouble();

                //Check to make sure User Inputted Value is Valid and not negative.
                if (Gallons<0)  
                {
                    System.out.println("You cannot have negative Gallons. Please try again with a valid number.\n");
                    MenuChoice(2);  //Calls MenuChoice case 2 again so user can enter a new number
                }   
                
                double Liters=(Gallons*3.785412);
                System.out.format("Your inputted "+Gallons+" Gallons is approximately %.2f Liters.\n\n",Liters);
                Menu(); //Calls Menu Method again to create a Loop
                break;  //stops switch statement

            case 3:
                System.out.println("Please input the amount of Pounds you wish to convert into Kilograms.");
                double Pounds=input.nextDouble();
                
                //Check to make sure User Inputted Value is Valid and not negative.
                if (Pounds<0)
                {
                    System.out.println("You cannot have negative pounds. Please try again with a valid number.\n");
                    MenuChoice(3);  //Calls MenuChoice case 3 again so user can enter a new number
                }   
                
                double Kilograms=(Pounds*0.45359237);
                System.out.format("Your inputted "+Pounds+" Pounds is approximately %.2f Kilograms.\n\n",Kilograms);
                Menu(); //Calls Menu Method again to create a Loop
                break;  //stops switch statement

            case 4:
                System.out.println("Please input the number of Miles you wish to convert to Kilometers.");
                double Miles=input.nextDouble();

                //Check to make sure User Inputted Value is Valid and not negative.
                if (Miles<0)
                {
                    System.out.println("You cannot have negative Miles. Please try again with a valid number.\n");
                    MenuChoice(4);  //Calls MenuChoice case 4 again so user can enter a new number
                }   
                
                double Kilometers=(Miles*1.60934);
                System.out.format("Your inputted "+Miles+" Miles is approximately %.2f Kilometers.\n\n",Kilometers);
                Menu(); //Calls Menu Method again to create a Loop
                break;  //stops switch statement

            case 5:
                System.out.println("Please input the number of Inches you wish to convert to Centimeters.");
                double Inches=input.nextDouble();

                //Check to make sure User Inputted Value is Valid and not negative.
                if (Inches<0)
                {
                    System.out.println("You cannot have negative Inches. Please try again with a valid number.\n");
                    MenuChoice(5);  //Calls MenuChoice case 5 again so user can enter a new number
                }   
                
                double Centimeters=(Inches*2.54);
                System.out.format("Your inputted "+Inches+" Inches is approximately %.2f Centimeters.\n\n",Centimeters);
                Menu(); //Calls Menu Method again to create a Loop
                break;  //stops switch statement

            case 6:
                System.out.println("Please input the number of Yards you wish to convert to Meters.");
                double Yards=input.nextDouble();

                //Check to make sure User Inputted Value is Valid and not negative.
                if (Yards<0)
                {
                    System.out.println("You cannot have negative Yards. Please try again with a valid number.\n");
                    MenuChoice(6);  //Calls MenuChoice case 6 again so user can enter a new number
                }   
                
                double Meters=(Yards*0.9144);
                System.out.format("Your inputted "+Yards+" Yards is approximately %.2f Meters.\n\n",Meters);
                Menu(); //Calls Menu Method again to create a Loop
                break;  //stops switch statement

            case 7:
                System.out.println("Ending Program.");
                System.exit(0); //Exits Program

            default:
                break;
        }

        input.close();
    }
}
