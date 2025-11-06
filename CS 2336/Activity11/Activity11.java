import java.util.Scanner;
public class Activity11 
{
   public static void main(String[] args) 
   {
    
    Scanner input=new Scanner(System.in);
    System.out.print("Enter number of students:");
    int numstudents=input.nextInt();
    

    Student[] students = new Student[numstudents];

    for (int i=0;i<numstudents;i++) 
    {
        System.out.println("Student "+(i+1)+":");

        System.out.println("Enter exam 1 grade:");
        int exam1=input.nextInt();

        System.out.println("Enter exam 2 grade:");
        int exam2=input.nextInt();
        
        students[i]=new Student(exam1, exam2, numstudents);
        
        Average(students[i]);
    }
    System.out.println("There are a total of "+Student.getNumstudents()+" students in the class.");
    input.close();
   } 



   static void Average(Student student)
   {
    int exam1=student.getExam1();
    int exam2=student.getExam2();
    double avggrade=(exam1+exam2)/2.0;
    System.out.format("The average grade is: %.2f\n\n", avggrade);
   }

}

class Student
{
    private int exam1;
    private int exam2;
    private static int numstudents=0;

    public Student(int exam1, int exam2, int numstudents) 
    {
        this.exam1=exam1;
        this.exam2=exam2;
        Student.numstudents+=1;
    }

    public int getExam1() 
    {
        return exam1;
    }

    public int getExam2() 
    {
        return exam2;
    }

    public static int getNumstudents() 
    {
        return numstudents;
    }
}
