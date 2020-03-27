import java.util.*;

class salary
{public static void main (String[] args) throws java.lang.Exception
	{try{
	    Scanner s =new Scanner(System.in);
	    int t = 0;
	    if(s.hasNextInt()){
	    	t=s.nextInt();
	    }
	     while(t>0){
	     	int n =0; 
	     	if(s.hasNextInt()){
	     		n=s.nextInt();
	     	}
	        int count=0,min=0;
	        int a[]=new int[n];
	        for(int i=0;i<n;i++){
	            a[i]=s.nextInt();
	            if(a[i]<a[min])
	                min=i;}
	        for(int i=0;i<n;i++)
	            count+=a[i]-a[min];
	        System.out.println(count);
	        t--;
	    }
	}catch(Exception e){}
	}
}