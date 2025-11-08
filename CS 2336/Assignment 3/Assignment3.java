import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Scanner;

public class Assignment3
{
    private static Triangle[] triangles=new Triangle[100];
    private static int triangleCount=0;
    private static Scanner input=new Scanner(System.in);
    private static SimpleDateFormat dateFormat=new SimpleDateFormat("M/d/yyyy - h:mm a");

    public static void main(String[] args)
    {
        int choice;
        do
        {
            choice = displayMenu();
            switch(choice)
            {
                case 1:
                    createTriangle();
                    break;
                case 2:
                    printSortedTriangles();
                    break;
                case 3:
                    printByColor();
                    break;
                case 4:
                    System.out.println("Exiting program. Goodbye!");
                    break;
            }
            System.out.println(); 
        } while(choice != 4); 
        input.close();
    }

    private static int displayMenu()
    {
        System.out.println("--- Triangle Menu ---");
        System.out.println("1. Enter data for a new triangle"); 
        System.out.println("2. Print all triangles sorted by area"); 
        System.out.println("3. Show triangles with a specific color"); 
        System.out.println("4. Exit the program"); 
        
        int choice;
        while(true)
        {
            choice=getValidInt("Enter your choice (1-4): ");
            if(choice>=1 && choice<=4)
            {
                break; 
            } 
            else
            {
                System.out.println("Error: Value must be between 1 and 4. Please try again.");
            }
        }
        return choice;
    }

    private static void createTriangle()
    {
        if(triangleCount>=100)
        { 
            System.out.println("Error: Array is full. Cannot add more triangles.");
            return;
        }

        System.out.println("Enter three sides (enter 0's for a default 1,1,1 triangle):");
        double s1=getValidDouble("Enter side 1: ");
        double s2=getValidDouble("Enter side 2: ");
        double s3=getValidDouble("Enter side 3: ");

        System.out.println("Enter a color (1-7):");
        int color=getValidInt("Enter color: ");

        try
        {
            if(s1==0 || s2==0 || s3==0)
            {
                triangles[triangleCount] = new Triangle(); 
                System.out.println("Default triangle (1,1,1) created.");
            } else
            {
                triangles[triangleCount] = new Triangle(s1, s2, s3, color); 
                System.out.println("New triangle created.");
            }
            triangleCount++; 
        } catch(IllegalArgumentException e)
        {
            System.out.println("Error creating triangle " + e.getMessage());
            System.out.println("Triangle was not added. Please try again.");
        }
    }

    private static void printSortedTriangles()
    {
        if(triangleCount==0)
        {
            System.out.println("No triangles to display.");
            return;
        }

        Triangle[] actualTriangles=new Triangle[triangleCount];
        System.arraycopy(triangles,0,actualTriangles,0,triangleCount); 
        Arrays.sort(actualTriangles);

        System.out.println("\nTriangles Sorted by Area (Smallest to Largest):");
        printHeader();
        for(Triangle t:actualTriangles)
        {
            printTriangle(t);
        }
    }

    private static void printByColor()
    {
        if(triangleCount==0)
        {
            System.out.println("No triangles to display.");
            return;
        }

        int color;
        while(true)
        {
            color = getValidInt("Enter a color to filter by (1-7): ");
            if(color >= 1 && color <= 7)
            {
                break; 
            } else
            {
                System.out.println("Error: Value must be between 1 and 7. Please try again.");
            }
        }

        boolean found = false;
        printHeader();
        for(int i = 0; i < triangleCount; i++)
        {
            if(triangles[i].getColor() == color)
            {
                printTriangle(triangles[i]);
                found = true;
            }
        }

        if(!found)
        {
            System.out.println("No triangles found with color " + color + ".");
        }
    }

    private static void printHeader()
    {
        System.out.printf("%-8s %-8s %-8s %-10s %-6s %-12s %-20s%n",
                "Side1", "Side2", "Side3", "Area", "Color", "Type", "Date Created");
        System.out.printf("%-8s %-8s %-8s %-10s %-6s %-12s %-20s%n",
                "-----", "-----", "-----", "----", "-----", "----", "------------");
    }

    private static void printTriangle(Triangle t)
    {
        System.out.printf("%-8.2f %-8.2f %-8.2f %-10.2f %-6d %-12s %-20s%n",
                t.getSide1(),
                t.getSide2(),
                t.getSide3(),
                t.getArea(),
                t.getColor(),
                t.getType(),
                dateFormat.format(t.getDateCreated())); 
    }

    private static double getValidDouble(String prompt)
    {
        double value;
        while(true)
        {
            System.out.print(prompt);
            if(input.hasNextDouble())
            {
                value = input.nextDouble();
                break; 
            } else
            {
                System.out.println("Error: Invalid input. Please enter a number.");
                input.next(); 
            }
        }
        return value;
    }

    private static int getValidInt(String prompt)
    {
        int value;
        while(true)
        {
            System.out.print(prompt);
            if(input.hasNextInt())
            {
                value = input.nextInt();
                break; 
            } else
            {
                System.out.println("Error: Invalid input. Please enter a whole number.");
                input.next(); 
            }
        }
        return value;
    }
}