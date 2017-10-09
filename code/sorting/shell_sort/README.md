# Shellsort
The Shellshort algorithm is a search algorithm. It's a generalization of the insertion sort that allows the exchange of items that are far apart.

The method starts by sorting pair of elements far apart from each other in the array, then progressively reducing the gap between the elements to be compared.

It has a worst-case performance of O(n²) and a best-case performance of O(n log n).

## Pseudocode

	# Sort an array a[0...n-1].
	gaps = [701, 301, 132, 57, 23, 10, 4, 1]

	# Start with the largest gap and work down to a gap of 1
	foreach (gap in gaps)
	{
	    # Do a gapped insertion sort for this gap size.
	    # The first gap elements a[0..gap-1] are already in gapped order
	    # keep adding one more element until the entire array is gap sorted
	    for (i = gap; i < n; i += 1)
	    {
		# add a[i] to the elements that have been gap sorted
		# save a[i] in temp and make a hole at position i
		temp = a[i]
		# shift earlier gap-sorted elements up until the correct location for a[i] is found
		for (j = i; j >= gap and a[j - gap] > temp; j -= gap)
		{
		    a[j] = a[j - gap]
		}
		# put temp (the original a[i]) in its correct location
		a[j] = temp
	    }
	}


## Further Reading
[Wikipedia - Shellsort](https://en.wikipedia.org/wiki/Shellsort)

A large scale collaboration of [OpenGenus](https://github.com/opengenus)
