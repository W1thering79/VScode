public class Activity8 
{
    public static void main(String[] args)
    {
        int [][] matrix =
        {
            {1,2,3},
            {4,5,6},
            {7,8,9}
        };

        //Transposing the Matrix
        for (int row=0;row<matrix.length;row++) 
        {
            for (int column=row+1;column<matrix[row].length;column++) 
            {
            int temp=matrix[row][column];
            matrix[row][column]=matrix[column][row];
            matrix[column][row]=temp;
            }
        }

        //Printing the Transposed Matrix
        for (int row=0;row<matrix.length;row++)
        {
            for (int column=0;column<matrix[row].length;column++)
            {
                System.out.print(matrix[row][column]+" ");
            }
            System.out.println();
        }       
    }

}