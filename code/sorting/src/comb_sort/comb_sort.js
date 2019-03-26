// Part of Cosmos by OpenGenus Foundation
function is_array_sorted(arr) {
  var sorted = true;
  for (var i = 0; i < arr.length - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      sorted = false;
      break;
    }
  }
  return sorted;
}

// Array to sort
// var arr = [1,1,1,1,5,4,4,2,5,666,3,3,34,4,6,2,5];

var iteration_count = 0;
var gap = arr.length - 2;
var decrease_factor = 1.25;

// Until array is not sorted, repeat iterations
while (!is_array_sorted(arr)) {
  // If not first gap
  if (iteration_count > 0)
    // Calculate gap
    gap = gap == 1 ? gap : Math.floor(gap / decrease_factor);

  // Set front and back elements and increment to a gap
  var front = 0;
  var back = gap;
  while (back <= arr.length - 1) {
    // If elements are not ordered swap them
    if (arr[front] > arr[back]) {
      var temp = arr[front];
      arr[front] = arr[back];
      arr[back] = temp;
    }

    // Increment and re-run swapping
    front += 1;
    back += 1;
  }
  iteration_count += 1;
}

// Print the sorted array
//console.log(arr);
