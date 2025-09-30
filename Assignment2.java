import java.util.Scanner;

public class Assignment2 
{
    public static void main(String[] args) 
    {
        Scanner input=new Scanner(System.in);

        int [][] gameboard=new int [3][3];  //initialized matrix as a 3x3 array

        PrintGameboard(gameboard);  //calls the PrintGameboard method to display the empty game board
        Game(gameboard);    //calls the Game method to start the game

        input.close();


    }    



    static void PrintGameboard(int gameboard[][])   //uses gameboard array as parameter
    {
        System.out.println("Game Board:");

        //for loop to print each row and column of the game board
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

    //starts the game with Player 1, gameboard as parameter to keep track of moves
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
        
        //checks if the input is within the bounds of the game board
        if (row<0||column<0||row>2||column>2)
        {
            System.out.println("Invalid choice, outside of game board bounds");
            Player1(gameboard);
        }

        //boolean check if the selected space is available
        boolean spaceAvailable=CheckSpace(gameboard,row,column);

        /*if else statement for if the space is available and prompts user to either choose again 
        (calls player1 method again) or place their marker*/
        if (!spaceAvailable)
        {
            Player1(gameboard);
        }
        else
        {
            gameboard[row][column]=1;
        }

        //boolean checks for win or draw
        boolean win=CheckWin(gameboard);
        boolean draw=CheckDraw(gameboard);

        //if no win or draw, prints game board and calls Player2 method for next turn
        if (!draw && !win)
        {
            PrintGameboard(gameboard);
            Player2(gameboard);
        }
        else //ends the game if there is a win or draw
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

        //checks if the input is within the bounds of the game board
        if (row<0||column<0||row>2||column>2)
        {
            System.out.println("Invalid choice, outside of game board bounds");
            Player2(gameboard);
        }

        //boolean check if the selected space is available
        boolean spaceAvailable = CheckSpace(gameboard,row,column);

        /*if else statement for if the space is available and prompts user to either choose again
        (calls player2 method again) or place their marker*/
        if (!spaceAvailable)
        {
            Player2(gameboard);
        }
        else
        {
            gameboard[row][column]=2;
        }

        //boolean checks for win or draw
        boolean win=CheckWin(gameboard);
        boolean draw=CheckDraw(gameboard);

        //if no win or draw, prints game board and calls Player1 method for next turn
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
                System.out.println("Player "+gameboard[rows][0]+" wins by making a row!");
                PrintGameboard(gameboard);
                System.exit(0);
            }
            if (gameboard[0][rows]==gameboard[1][rows] && gameboard[1][rows]==gameboard[2][rows] && gameboard[0][rows]!=0) 
            {
                System.out.println("Player "+gameboard[0][rows]+" wins by making a column!");
                PrintGameboard(gameboard);
                System.exit(0);
            }
        }

        // Check diagonals for a win
        if (gameboard[0][0]==gameboard[1][1] && gameboard[1][1]==gameboard[2][2] && gameboard[0][0]!=0) 
        {
            System.out.println("Player "+gameboard[0][0]+" wins diagonally!");
            PrintGameboard(gameboard);
            System.exit(0);
        }
        if (gameboard[0][2]==gameboard[1][1] && gameboard[1][1]==gameboard[2][0] && gameboard[0][2]!=0)
        {
            System.out.println("Player "+gameboard[0][2]+" wins diagonally!");
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
