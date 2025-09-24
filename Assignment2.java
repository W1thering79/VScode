import java.util.Scanner;

public class Assignment2 
{
    public static void main(String[] args) 
    {
        Scanner input=new Scanner(System.in);

        int [][] gameboard=new int [3][3];

        PrintGameboard(gameboard);      
        Game(gameboard);

        input.close();


    }    



    static void PrintGameboard(int gameboard[][])
    {
        System.out.println("Game Board:");
        for (int row=0;row<3;row++)
        {
            for (int column=0;column<3;column++)
            {
                System.out.print(gameboard[row][column]+" ");
            }
            System.out.println();
        }
        System.out.println("\n");
    }
    static void Game(int[][] gameboard)
    {
        Player1(gameboard);
    }



    static void Player1(int gameboard[][])
    {
        Scanner input=new Scanner (System.in);
        System.out.println("Player 1, your move");
        System.out.print("Row:");
        int row=input.nextInt();

        System.out.print("Column:");
        int column=input.nextInt();

        System.out.println("\n");
        
        if (row<0||column<0||row>2||column>2)
        {
            System.out.println("Invalid choice, outside of game board bounds");
            Player1(gameboard);
        }

        boolean spaceAvailable=CheckSpace(gameboard,row,column);

        if (!spaceAvailable)
        {
            Player1(gameboard);
        }
        else
        {
            gameboard[row][column]=1;
        }

        boolean win=CheckWin(gameboard);
        boolean draw=CheckDraw(gameboard);

        if (!draw && !win)
        {
            PrintGameboard(gameboard);
            Player2(gameboard);
        }
        else
        {
            System.exit(0);
        }

    }



    static void Player2(int gameboard[][])
    {
        Scanner input=new Scanner (System.in);
        System.out.println("Player 2, your move");
        System.out.print("Row:");
        int row=input.nextInt();

        System.out.print("Column:");
        int column=input.nextInt();

        System.out.println("\n");

        if (row<0||column<0||row>2||column>2)
        {
            System.out.println("Invalid choice, outside of game board bounds");
            Player2(gameboard);
        }

        boolean spaceAvailable = CheckSpace(gameboard,row,column);

        if (!spaceAvailable)
        {
            Player2(gameboard);
        }
        else
        {
            gameboard[row][column]=2;
        }

        boolean win=CheckWin(gameboard);
        boolean draw=CheckDraw(gameboard);

        if (!draw && !win)
        {
            PrintGameboard(gameboard);
            Player1(gameboard);
        }

    }



    static boolean CheckSpace(int gameboard[][],int row,int column)
    {
        if (gameboard[row][column]!=0) 
        {
            PrintGameboard(gameboard);
            System.out.println("The space you selected is already occupied. Try again.");
            return false;
        }
        return true;
    }



    static boolean CheckWin(int gameboard[][])
    {
        // Check rows and columns for a win
        for (int rows=0;rows<3;rows++) 
        {
            if (gameboard[rows][0]==gameboard[rows][1] && gameboard[rows][1]==gameboard[rows][2] && gameboard[rows][0]!=0) 
            {
                System.out.println("Player "+gameboard[rows][0]+" wins!");
                PrintGameboard(gameboard);
                System.exit(0);
            }
            if (gameboard[0][rows]==gameboard[1][rows] && gameboard[1][rows]==gameboard[2][rows] && gameboard[0][rows]!=0) 
            {
                System.out.println("Player "+gameboard[0][rows]+" wins!");
                PrintGameboard(gameboard);
                System.exit(0);
            }
        }

        // Check diagonals for a win
        if (gameboard[0][0]==gameboard[1][1] && gameboard[1][1]==gameboard[2][2] && gameboard[0][0]!=0) 
        {
            System.out.println("Player "+gameboard[0][0]+" wins!");
            PrintGameboard(gameboard);
            System.exit(0);
        }
        if (gameboard[0][2]==gameboard[1][1] && gameboard[1][1]==gameboard[2][0] && gameboard[0][2]!=0)
        {
            System.out.println("Player "+gameboard[0][2]+" wins!");
            PrintGameboard(gameboard);
            System.exit(0);
        }
        return false;
    }



    static boolean CheckDraw(int gameboard[][])
    {
        // Check for a tie
        boolean tie=true;
        for (int row=0;row<3;row++) 
        {
            for (int col=0;col<3;col++) 
            {
                if (gameboard[row][col]==0) 
                {
                    tie=false;
                }
            }
        }
        if (tie) 
        {
            PrintGameboard(gameboard);
            System.out.println("The game is a tie!");
            System.exit(0);
        }   
        return tie;
    }
}
