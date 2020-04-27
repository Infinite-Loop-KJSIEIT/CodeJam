import java.util.*;
class Solution
{
    Scanner sc=new Scanner(System.in);
    
    void solve()
    {
        int n=sc.nextInt();
        
        if(n<30)
        {
            for(int i=0; i<n; ++i)
            {
                System.out.println((i+1) + " 1");
            }
        
            System.exit(0);
        }
        
    
        n=-30;
        int m=0;
        boolean left=true;
        for(int i=0; i<30; ++i)
        { 
            System.out.println((i+1)+" "+(left?1:i+1));
            int po=n>>i&1;
            if(po==1)
            {
                if(left==true)
                {
                    for(int j=1; j<=i; ++j)
                    {System.out.println((i+1)+" "+(j+1));}
                }
               else
               {
                   for(int j=i-1; j>=0; --j)
                    { System.out.println((i+1)+" "+(j+1));}
               }
        
               left=!left;
               ++m;
            }
        }
     
        for(int i=30; m!=0; --m, ++i)
        {
        //move to current row
         System.out.println((i+1)+" "+(left?1:i+1));
        }
    }
  public void main(String args[])
    {
        int t = sc.nextInt();
        for(int i=1; i<=t; ++i) {
        System.out.println("Case #"+i+":");
        solve();
    }
    }
}
