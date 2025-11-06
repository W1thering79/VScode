public class Activity10 
{
    public static void main(String [] args)
    {
        Rectangle rect = new Rectangle();
        rect.width=10;
        rect.length=5;

        System.out.println("The area of the rectangle is: "+getArea(rect.width,rect.length));
        System.out.println("The perimeter of the rectangle is: "+getPerimeter(rect.width,rect.length));
        
    }

    public static int getArea(int width, int length)
    {
        int area=width*length;
        return area;
    }

    public static int getPerimeter(int width, int length)
    {
        int perimeter=((2*width)+(2*length));
        return perimeter;
    }
}

class Rectangle
{
    int width;
    int length;
}