/* Part of Cosmos by OpenGenus Foundation */
export function bubbleSort(items: number[]): number[] {
	const n = items.length;
	let swapped = false;
	do {
		swapped = false;
		// 1. Run through the list.
		for(let i = 0; i < n-1 ; i++) {
			// 2. Compare each adjacent pair of element
			if(items[i] > items[i + 1]) {
				// 3. Swap elements if not in correct order
				const tmp = items[i];
				items[i] = items[i + 1];
				items[i + 1] = tmp;
				swapped = true;
			}

		}
	// 4. Repeat until no swap is needed
	} while(swapped)
	return items;
}

// console.log(bubbleSort([5,7,3,1,-7,6,2]));
