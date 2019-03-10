// Part of Cosmos by OpenGenus Foundation

// Sort a list using shaker sort (bidirectional bubble sort)
function shaker_sort(list) {
  let swapped = false;
  let length = list.length;

  do {
    // Testing from head to tail of list
    for (let i = 0; i < length - 1; i++) {
      if (list[i] > list[i + 1]) {
        let aux = list[i];
        list[i] = list[i + 1];
        list[i + 1] = aux;

        swapped = true;
      }
    }

    if (swapped === false) break;

    swapped = false;

    // Testing from tail to head of list
    for (let i = length - 2; i >= 0; i--) {
      if (list[i] > list[i + 1]) {
        let aux = list[i];
        list[i] = list[i + 1];
        list[i + 1] = aux;

        swapped = true;
      }
    }
  } while (swapped);

  return list;
}
