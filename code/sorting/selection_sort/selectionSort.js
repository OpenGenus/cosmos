/*use this sorting function as follows
var sortedArray = selectionSort(array);*/

function selectionSort(arr) {
    var length = arr.length;
    for (var i = 0; i < length - 1; i++) {
        var min = i;
        for (var j = i+1; j < length; j++) { // Find the minimum element from i'th to nth element
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        // Swap the minumum element found with i'th element
        var temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }

    return arr;
}
