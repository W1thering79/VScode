import java.util.Date;

public abstract class GeometricObject 
{

    private int color;
    private Date dateCreated;

    protected GeometricObject() 
    {
        this.color=1;
        this.dateCreated=new Date();
    }

protected GeometricObject(int color)
    {
        if(color<1 || color>7)
        {
            throw new IllegalArgumentException("Color must be between 1 and 7.");
        }
        this.color = color;
        this.dateCreated = new Date();
    }

    public int getColor() 
    {
        return color;
    }

    public void setColor(int color) 
    {
        this.color=color;
    }

    public Date getDateCreated() 
    {
        return dateCreated;
    }

    public abstract double getArea();

    public abstract double getPerimeter();
}