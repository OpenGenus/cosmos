/* Part of Cosmos by OpenGenus Foundation */

package quicksort

func QuickSort(values []int) {
	sortNumbers(values,0,len(values)-1)
}

func sortNumbers(values []int, l int, r int) {
	if l >= r {
		return
	}

	pivot := values[l]
	i := l + 1;

	for j := l; j <= r; j++ {
		if pivot > values[j] {
			values[i], values[j] = values[j], values[i]
			i++
		}
	}

	values[l], values[i-1] = values [i-1], values[l]
	
	sortNumbers(values,l,i-2)
	sortNumbers(values,i,r)
}
