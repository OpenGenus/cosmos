import java.util.*;
class Example1
{
	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[] arr=new int[n];
		for(int i=0;i<n;i++)
		{
			arr[i]=sc.nextInt();
		}
		HashMap<Integer,Integer> map=new HashMap<Integer,Integer>();
		int c=0;
		for(int i=0;i<n;i++)
		{
			if(!map.containsKey(arr[i]))
			{
				map.put(arr[i],1);c++;
			}
		}
		System.out.println(c);
		sc.close();
	}
}
