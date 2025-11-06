public class Activity9 
{
    public static void main(String[] args) 
    {
        Employee employee1 = new Employee();

        employee1.name="Chojipargo";
        employee1.numberOfHours=40;

        System.out.println("Employee Name: " + employee1.name);
        System.out.println("Hours Worked: " + employee1.numberOfHours);
        System.out.println("Calculated Salary: $" + employee1.calculateSalary());
    }
}
class Employee 
    {
    String name;
    int numberOfHours;
    static final double HOURLY_RATE=20.0;


    public double calculateSalary() 
    {
        double salary=numberOfHours*HOURLY_RATE;
        return salary;
    }
}