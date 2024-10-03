function binarySearch(array, key) {
    var lo = 0,
        hi = array.length - 1,
        mid,
        element;
    while (lo <= hi) {
        mid = Math.floor((lo + hi) / 2, 10);
        element = array[mid];
        if (element < key) {
            lo = mid + 1;
        } else if (element > key) {
            hi = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}
