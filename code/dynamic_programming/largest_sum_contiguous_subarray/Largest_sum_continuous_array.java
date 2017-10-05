import java.util.Scanner;

public class Max_subarray_problem {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n;
        System.out.println("Enter the number of elements");
        n=sc.nextInt();
        int[] a=new int[n];
        System.out.println("Enter the value of Elements");
        for(int i=0;i<n;i++)
        {
            a[i]=sc.nextInt();
        }
       //int[] a={-1,-4,-3,-4};
       int m= findmaxsum(a,0,a.length-1);
       System.out.println(m);
    }

    private static int findmaxsum(int[] a, int l, int h) {
        int max;
       if(l==h)
       {
           return a[l];
       }
       else
       {
           int mid=(l+h)/2;
           int leftmaxsum;
         //   System.out.println(l+" "+mid+" "+h);
           leftmaxsum=findmaxsum(a,l,mid);
          // System.out.println(l+" "+mid+" "+h);
           int rightmaxsum=findmaxsum(a,mid+1,h);
           int crossmaxsum=findcrosssum(a,l,mid,h);
       
        max=Math.max(Math.max(leftmaxsum, rightmaxsum), crossmaxsum);
       
       }
      // System.out.println(max);
       return max;
      
    }

    private static int findcrosssum(int[] a, int l, int mid, int h) {
        int leftsum=Integer.MIN_VALUE;
        int lsum=0;
        int csum;
        for(int i=mid;i>=l;i--)
        {
            lsum=lsum+a[i];
            if(lsum>leftsum)
            {
                leftsum=lsum;
            }
        }
        int rightsum=Integer.MIN_VALUE;
        int rsum=0;
        for(int j=(mid+1);j<=h;j++)
        {
          rsum=rsum+a[j];
          if(rsum>rightsum)
          {
              rightsum=rsum;
          }
        }
        csum=rightsum+leftsum;
        return csum;
        
       }
    
}
