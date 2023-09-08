public static int Search(int[] list, int data)
{
	int lo = 0;
	int mid = -1;
	int hi = list.Length - 1;
	int index = -1;

	while (lo <= hi)
	{
		mid = (int)(lo + (((double)(hi - lo) / (list[hi] - list[lo])) * (data - list[lo])));

		if (list[mid] == data)
		{
			index = mid;
			break;
		}
		else
		{
			if (list[mid] < data)
				lo = mid + 1;
			else
				hi = mid - 1;
		}
	}

	return index;
}
