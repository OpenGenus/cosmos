import java.util.*;

class COVID19{
	public static void main(String args[]){
		Scanner input = new Scanner(System.in);

		int test;
		test = input.nextInt();
		
		while(test-- >0)
		{
			int n;
			n = input.nextInt();
			int []x = new int[n];

			for(int i=0;i<n;i++)
				x[i]=input.nextInt();
				
			int mn=10,mx=0,curr=1;

			for(int i=1;i<n;i++)
			{
				if(x[i]-x[i-1]<=2)
					curr++;
				else
				{
					mx=Math.max(mx,curr);
					mn=Math.min(mn,curr);
					curr=1;
				}
			}

			if(curr!=0)
			{
				mx=Math.max(mx,curr);
				mn=Math.min(mn,curr);
			}

			mn=Math.min(mn,mx);

			System.out.println(mn + " " + mx);	
		}
		
	}
}