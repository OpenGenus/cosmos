function splitArray(array, parts) {
  let subArray = [];
  for (let i = 0; i <= array.length; i += parts) {
    subArray.push(array.slice(i, i + parts));
  }
  if (subArray[subArray.length - 1].length == 0) {
    subArray.pop();
  }
  return subArray;
}

for (let x = 1; x <= 10; ++x) {
  console.log(splitArray([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], x));
}
