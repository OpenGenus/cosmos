void main() {
  List<int> array = [5, 1, 4, 2, 8];
  List<int> sortedarray = bubbleSort(array);
  print(sortedarray);
}

bubbleSort(List<int> array) {
  int lengthOfArray = array.length;
  for (int i = 0; i < lengthOfArray - 1; i++) {
    print('Index i at pos: ${i}');
    for (int j = 0; j < lengthOfArray - i - 1; j++) {
      print('loop:${i}');
      print('index i and j at pos: ${i}  &  ${j}');

      if (array[j] > array[j + 1]) {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
  return (array);
}
