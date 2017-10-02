def selectionSort(unsorted):
	sorte = []
	for i in range(len(unsorted)):
		selected = unsorted[0]
		index=0
		for j in range(len(unsorted)):
			if unsorted[j] < selected:
				selected = unsorted[j]
				index=j
		sorte.append(selected)
		unsorted.pop(index)
	return sorte