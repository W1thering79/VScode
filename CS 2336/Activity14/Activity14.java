public class Activity14 
{
    public static void main(String[] args)
    {
        PartTime partTimeEmployee =new PartTime(20,0);
        FullTime fullTimeEmployee=new FullTime();

        partTimeEmployee.name="Bob";
        fullTimeEmployee.name="John";

        partTimeEmployee.ID=101;
        fullTimeEmployee.ID=102;

        System.out.println("Part Time Employee:"); 
        System.out.println(partTimeEmployee.name);
        System.out.println("ID:"+partTimeEmployee.ID);
        System.out.println("Salary:$"+partTimeEmployee.getSalary()+"\n");


        System.out.println("Full Time Employee:");
        System.out.println(fullTimeEmployee.name);
        System.out.println("ID:"+fullTimeEmployee.ID);
        System.out.println("Salary:$"+fullTimeEmployee.getSalary()+"\n");
    }
}

class Employee
{
    String name;
    int ID;
    
}

class PartTime extends Employee
{
    int hours;
    int salary;

    public PartTime(int hours, int salary) 
    {
        this.hours=hours;
        this.salary=salary;

    }

    public int getSalary()
    {
        salary=hours*25;
        return salary;
    }
}

class FullTime extends Employee
{
    int salary=10000;

    public int getSalary()
    {
        return salary;
    }
}


