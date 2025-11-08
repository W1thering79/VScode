import java.util.Arrays;

public class Triangle extends GeometricObject implements Comparable<Triangle> 
{

    private double[] sides=new double[3];

    public Triangle() 
    {
        this(1.0,1.0,1.0,1);
    }

    public Triangle(double side1, double side2, double side3, int color) 
    {
        super(color);
        this.sides[0]=side1;
        this.sides[1]=side2;
        this.sides[2]=side3;
    }

    public double getSide1() 
    {
        return sides[0];
    }

    public double getSide2() 
    {
        return sides[1];
    }

    public double getSide3() 
    {
        return sides[2];
    }

    @Override
    public double getPerimeter() 
    {
        return sides[0]+sides[1]+sides[2];
    }

    @Override
    public double getArea() 
    {
        if (!isValid()) 
        {
            return 0;
        }
        double perimeter=getPerimeter()/2.0;
        return Math.sqrt(perimeter*(perimeter-sides[0])*(perimeter-sides[1])*(perimeter-sides[2]));
    }

    private boolean isValid() 
    {
        return (sides[0]+sides[1]>sides[2]) && (sides[0]+sides[2]>sides[1]) && (sides[1]+sides[2]>sides[0]);
    }

    public String getType() 
    {
        if (!isValid()) 
        {
            return "Invalid";
        }

        double[] sortedsides={sides[0],sides[1],sides[2]};
        Arrays.sort(sortedsides);

        if (sortedsides[0]==sortedsides[2]) {
            return "Equilateral";
        }

        if ((sortedsides[0]*sortedsides[0])+(sortedsides[1]*sortedsides[1])==(sortedsides[2]*sortedsides[2]))
        {
            return "Right";
        }

        if (sortedsides[0]==sortedsides[1] || sortedsides[1]==sortedsides[2])
        {
            return "Isosceles";
        }
        return "Scalene";
    }

    @Override
    public int compareTo(Triangle t) 
    {
        return Double.compare(this.getArea(),t.getArea());
    }
}