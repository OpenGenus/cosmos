/* Part of Cosmos by OpenGenus Foundation */
  var length;
  /* to create MAX  array */
  function heap_root(array, i) {
      var left = 2 * i + 1;
      var right = 2 * i + 2;
      var max = i;

      if (left < length && array[left] > array[max]) {
          max = left;
      }

      if (right < length && array[right] > array[max]) {
          max = right;
      }

      if (max != i) {
          swap(array, i, max);
          heap_root(array, max);
      }
  }

  function swap(array, index_A, index_B) {
      var temp = array[index_A];

      array[index_A] = array[index_B];
      array[index_B] = temp;
  }

  function heapSort(array) {

      length = array.length;

      for (var i = Math.floor(length / 2); i >= 0; i -= 1) {
          heap_root(array, i);
      }

      for (i = array.length - 1; i > 0; i--) {
          swap(array, 0, i);
          length--;


          heap_root(array, 0);
      }
  }

  // var arr = [3, 0, 2, 5, -1, 4, 1];
  // heapSort(arr);
  // console.log(arr);
