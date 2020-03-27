import java.util.*;
class cnote
{public static void main (String[] args) throws java.lang.Exception{
	Scanner s = new Scanner(System.in);
	int t = s.nextInt();
	while(t>0)
	{
		int x = 0; int y =0; int k = 0; int n = 0;
		if(s.hasNextInt()){
			x = s.nextInt();
		}
		if(s.hasNextInt()){
			y = s.nextInt();
		}
		if(s.hasNextInt()){
			k = s.nextInt();
		}
		if(s.hasNextInt()){
			n = s.nextInt();
		}
		boolean flag = false;
		for(int i=0;i<n;i++)
		{
			int p =0; 
			int c =0;
		if(s.hasNextInt())
			p = s.nextInt();
		if(s.hasNextInt())
			c = s.nextInt();
		if(p>=(x-y)&&c<=k)
			flag=true;
		}
		if(flag)
			System.out.println("LuckyChef");
		else 
			System.out.println("UnluckyChef");
		t--;
	}
	}
}
