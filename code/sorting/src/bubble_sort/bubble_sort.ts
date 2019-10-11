/* Part of Cosmos by OpenGenus Foundation */
export function bubbleSort(items: Array<number>): Array<number> {
	let swapped: boolean = false;
	do {
		swapped = false;
		// 1. Run through the list.
		items.forEach((item: number, index: number, items: Array<number>) => {
			// 2. Compare each adjacent pair of element
			if (item > items[index + 1]) {
				// 3. Swap elements if not in correct order
				const tmp = item;
				items[index] = items[index + 1];
				items[index + 1] = tmp;
				swapped = true;
			}
		});
	// 4. Repeat until no swap is needed
	} while(swapped)
	return items;
}

// console.log(bubbleSort([5,7,3,1,-7,6,2]));
