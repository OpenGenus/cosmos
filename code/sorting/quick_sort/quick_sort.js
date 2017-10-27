// Part of Cosmos by OpenGenus Foundation
// here arr is the array to be sorted

// startIdx is the initial index from which to start sorting.
// i.e. 0 for sorting whole array

// endIdx is the ending index from which to end sorting.
// i.e. array's length for sorting whole array

// expected call for the function is as follows:
// quickSort(array, 0, array.length - 1);

function  quickSort(arr, startIdx, endIdx)
{
	let i = startIdx,
		j = endIdx,
		temp,
		k = (startIdx + endIdx) / 2, //k is pivot index
		pivot = parseInt(arr[k.toFixed()]); /*k may be a fraction, toFixed takes it to the nearest integer*/

	while (i <= j)
	{
		while (parseInt(arr[i]) < pivot)
			i++;
		while (parseInt(arr[j]) > pivot)
			j--;
		if (i <= j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}

	if (startIdx < j)
		quickSort(arr, startIdx, j);
	if (i < endIdx)
		quickSort(arr, i, endIdx);
	return arr;
}
