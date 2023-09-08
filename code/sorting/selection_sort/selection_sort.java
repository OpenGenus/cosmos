
	public static void selection(int a[])
	{
		for(int i=0;i<a.length-1;i++)
		{
			for(int j=i;j<a.length;j++)
			{
				if(a[i]>a[j])
					swap(a,i,j);
			}
		}
	}
	public static void swap(int a[],int i,int j)
	{
		int temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		return;
	}
	