/*  A Dynamic Programming solution for Rod cutting problem
  Returns the best obtainable price for a rod of length a and
   price[] as prices of different pieces */

public class RodCutting
{
	private static int cutRod(int price[] , int a)
	{
         	int val[] = new int[a + 1];
		val[0] = 0;
		for (int i = 1; i <= a; ++i)
		{
			int max_val = Integer.MIN_VALUE;
			for (int j = 0; j < i; ++j)
			{
				max_val = Math.max(max_val,price[j] + val[i - j - 1]);
                                val[i] = max_val;
			}
		}

		return val[a];
	}

	//Testing Program 
	public static void main(String args[])
	{
		int arr[] =  {1, 5, 17, 18, 21};
		int size = arr.length;
		System.out.println("Maximum Obtainable Value is " + cutRod(arr, size));
	}
}
