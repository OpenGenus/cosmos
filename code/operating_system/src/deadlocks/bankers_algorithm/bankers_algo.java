package bankersalgo;
import java.util.*;

class bankersimplement{
	int max1;
}

class allocate{
	int max[][]=new int[10][10];
	int allo[][]=new int[10][10];
	int need[][]=new int[10][10];
	int visit[]=new int[10];
	int p,r;
	int instance[]=new int[10];
	int work[]=new int[10];
	int totala[]=new int[10];
	Scanner s=new Scanner(System.in);
		
	void accept()
	{
		System.out.println("\n\tEnter no. of processes :");
		p=s.nextInt();   //p=no. of processes
		System.out.println("\n\tEnter no. of resources :");
		r=s.nextInt();   //r=no. of resources
		System.out.println("\n\tEnter instances of resources :");
		for(int i=0;i<r;i++)
		{
			instance[i]=s.nextInt();     //array for storing instances of each resource
		}
		System.out.println("\n\tEnter maximum no. of instances required :");
		for(int i=0;i<p;i++)
		{
			for(int j=0;j<r;j++)
			{
				max[i][j]=s.nextInt();	  //max no. of res reqd by each process 2d matrix
			}
		}
		System.out.println("\n\tEnter allocated instances :");
		for(int i=0;i<p;i++)
		{
			for(int j=0;j<r;j++)
			{
				allo[i][j]=s.nextInt();   //allocated matrix
			}
		}		
		for(int i=0;i<p;i++)
		{
			for(int j=0;j<r;j++)
			{
				need[i][j]=max[i][j]-allo[i][j];    //need matrix
				if(need[i][j]<0)  //no negative need possible = 0 need
				{
					need[i][j]=0;
				}
			}
		}
		
			for(int i=0;i<r;i++)     //already allocated no. of instances of each resource in processes   array
			{
				for(int j=0;j<p;j++)
				{
				totala[i]=totala[i]+allo[j][i];
			    }
		    }
			for(int i=0;i<r;i++)          // useful resources array
			{
				
				work[i]=instance[i]-totala[i];
			   
		    }
	}
	
	void display()
	{
		System.out.println("\n\tInstances are :");
		for(int i=0;i<r;i++)
		{
			System.out.println(instance[i]);
		}
		
		System.out.println();
		System.out.println("\n\tMax");
		for(int i=0;i<p;i++)
		{
			System.out.print("P"+i);
			
			for(int j=0;j<r;j++)
			{
				System.out.print("\t"+max[i][j]);
			}
			System.out.println();
		}	
		System.out.println();
		
		System.out.println("\n\tAllocated instances");
		for(int i=0;i<p;i++)
		{
			System.out.print("P"+i);
			for(int j=0;j<r;j++)
			{
				System.out.print("\t"+allo[i][j]);
			}
			System.out.println();
		}	
		
		System.out.println();
		
		System.out.println("\n\tNeed");
		for(int i=0;i<p;i++)
		{
			System.out.print("P"+i);
			for(int j=0;j<r;j++)
			{
				System.out.print("\t"+need[i][j]);
			}
			System.out.println();
		}	
		
		System.out.println();
		
		System.out.println("\n\tTotal allocated ");
		for(int j=0;j<r;j++)
		{
			
			System.out.print("\t"+totala[j]);
		}
		
		System.out.println();
		
		System.out.println("\n\tWork ");
		for(int j=0;j<r;j++)
		{
			System.out.print("\t"+work[j]);
			
		}
		System.out.println();
	}
	
	
	void need1()
	{
		int count=p,x=0;
		System.out.println();
		System.out.println();
		System.out.println("\n\tSequence is :");
		int work1[]=new int[10];
		for(int i=0;i<r;i++)
		{
			work1[i]=work[i];
		}
		while(count>0)  //initially= no. of processes
		{
			for(int i=0;i<p;i++)
			{
				if(visit[i]==0)
				{		
					for(int j=0;j<r;j++)
					{
						if(need[i][j]<=work[j])
						{						
							x++;		  //counting resources' need fulfilled												
						}
							
					}		
					if(x==r)    //if need count = resources then allocate
					{
						for(int j=0;j<r;j++)
						{
							work[j]=work[j]+allo[i][j];		 //release allocated resources in work array			
						}
						visit[i]=1;   //should not be fulfilled again , as already is fulfilled						
						count--;
						x=0;
						System.out.println("P"+i);
						
					}
					x=0;
				}
			}
		}
		
		
		
		
		count=p;
		x=0;
		for(int i=0;i<p;i++)
		{
		   visit[i]=0;	
		}
		System.out.println("\n\tAnother Sequence is :");
		int ch[]=new int[3];
		while(count>0)
		{
			for(int i=0;i<p;i++)
			{
				if(visit[i]==0)
				{		
					for(int j=0;j<r;j++)
					{
						if(need[i][j]<=work1[j])
						{						
							x++;														
						}
							
					}		
					if(x==r)
					{
						for(int j=0;j<r;j++)
						{
							work1[j]=work1[j]+allo[i][j];					
						}
						visit[i]=1;						
						count--;												
						System.out.println("P"+i);	
						break;
					}	
					x=0;
				}
			}
		}
		System.out.println("\n\tSum is :");
		for(int i=0;i<r;i++)
		{
		System.out.print("\n"+work[i]);
		}
	}
}

public class bankers_algo
{

	public static void main(String[] args) {
		allocate a=new allocate();
		a.accept();
		a.display();
		a.need1();

	}

}
/*output:
 * Enter no. of processes
5
Enter no. of resources
3
Enter instances of resources
10
5
7
Enter maximum no. of instances required
7
5
3
3
2
2
9
0
2
2
2
2
4
3
3
Enter allocated instances
0
1
0
2
0
0
3
0
2
2
1
1
0
0
2
Instances are
10
5
7
max

	7	5	3
	3	2	2
	9	0	2
	2	2	2
	4	3	3
allocated instances

	0	1	0
	2	0	0
	3	0	2
	2	1	1
	0	0	2
need

	7	4	3
	1	2	2
	6	0	0
	0	1	1
	4	3	1
total allocated 
	7	2	5
work 
	3	3	2
Sequence is
p1
p3
p0
p2
p4

 Another Sequence is
p1
p3
p4
p0
p2
sum is

10
5
7*/
