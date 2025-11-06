public class Activity12 
{
    public static void main(String[] args) 
    {
        String[] str="I'm very uncreative so making a string for my Computer Science 2 class is difficult.".split(" ");
        int propername=0;

        for (int i=0;i<str.length;i++)
        {
            if (str[i].length()>0) 
            {
                char c=str[i].charAt(0);
                if (Character.isUpperCase(c)) 
                {
                    propername+=1;
                }
            }
        }
        System.out.println("The string is:");
        for (int i=0;i<str.length;i++)
        {
            System.out.print(str[i]+" ");
        }
        System.out.println("\n");
        System.out.println("There are a total of "+propername+" proper names in the string.");
    }
}
