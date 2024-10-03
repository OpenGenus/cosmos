public static void quicksort(int a[],int lo,int hi)
	{
		if(lo>=hi)
			return;
		
		int mid=(lo+hi)/2;
		int pivot=a[mid];
		int left=lo,right=hi;
		while(left<=right)// question1
		{
			while(a[left]<pivot)//question2
			{
				left++;
			}
			while(a[right]>pivot)//question3
			{
				right--;
			}
			if(left<=right)//question4
			{
				int temp=a[left];
				a[left]=a[right];
				a[right]=temp;
				left++;
				right--;
			}
		}
		quicksort(a,lo,right);
		quicksort(a,left,hi);
	}