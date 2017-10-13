/**
* Shaker sort (bidirectional bubble sort)
* Orders in descending order
* @param array array to be sorted
*/
public static void shakerSort(int[] array) {
for (int i = 0; i < array.length/2; i++) {
boolean swapped = false;
for (int j = i; j < array.length - i - 1; j++) {
if (array[j] < array[j+1]) {
int tmp = array[j];
array[j] = array[j+1];
array[j+1] = tmp;
swapped = true;
}
}
for (int j = array.length - 2 - i; j > i; j--) {
if (array[j] > array[j-1]) {
int tmp = array[j];
array[j] = array[j-1];
array[j-1] = tmp;
swapped = true;
}
}
if(!swapped) break;
}
}
