import java.util.Scanner;
import java.lang.*;
class thread1 extends Thread
{
    public void fun()
    {
        try
        {
            System.out.println("Please, wait while we are processing.\n");Thread.sleep(2000);
            Thread.sleep(5000);
        }
        catch(Exception e)
        {
            //e.printStackTrace();
            System.out.println(e.getMessage());
        }
    }
}

public class PasswordStrengthChecker
{
    public static void main(String [] args)
    {
        Scanner input=new Scanner(System.in);
        System.out.println("Enter your password= ");
        String a=input.nextLine();
        thread1 obj=new thread1();
        obj.start();
        obj.fun();
        int count1=0,count2=0,count3=0;
        for(int i=0;i<a.length();i++)
        {
            if(a.charAt(i)!=' ')
            count1++;
        }
        
        //thread1 obj=new thread1();
        //obj.start();
        if(count1<8)
        System.out.println("Password Too Weak.\nStrength= <10%\nHint: Increase the length of your Password.");
        if(count1>=8)
        {
            for(int i=0;i<a.length();i++)
            {
                char c=a.charAt(i);
                if(Character.isUpperCase(c))
                {
                    count2++;
                }
                if(a.charAt(i)=='!'||a.charAt(i)=='@'||a.charAt(i)=='#'||a.charAt(i)=='$'||a.charAt(i)=='%'||a.charAt(i)=='&'||a.charAt(i)=='*')
                {
                    count3++;
                }
            }

            if(count2==0 && count3==0)
            {
                System.out.println("Weak Password.\nStrength= >30%\nHint: Try to use Upper Case Characters or Special Characters.");
            }
                
            else if(count2>0 && count3==0)
            {
                System.out.println("Somewhat Strong Password.\nStrength= 50%\nHint: Try to use Special Characters.");
            }
                
            else if(count2==0 && count3>0)
            {
                System.out.println("Strong Password.\nStrength= 80%\nHint: Try to use Upper Case Characters.");
            }
                
            else if(count2>0 && count3>0)
            {
                System.out.println("Very Strong Password.\nStrength= 100%");
                System.out.println("You can go by this!!");
            }
            
        }
    }
}
