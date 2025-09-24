public class Activity7 
{
    public static void main(String[] args) 
    {
        char[][] pattern={
            {'#','#','#','#','#'},
            {'#',' ',' ',' ','#'},
            {'#',' ',' ',' ','#'},
            {'#',' ',' ',' ','#'},
            {'#','#','#','#','#'}
        };   

        for (int row=0;row<5;row++)
        {
            for (int column=0;column<5;column++)
            {
                System.out.print(pattern[row][column]+" ");
            }
            System.out.println();
        }
    }    
}
