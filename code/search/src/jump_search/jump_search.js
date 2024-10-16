let array = [0, 1, 2, 5, 10, 15, 20, 25, 30, 33];
let wanted = 2;

pos = jumpSearch(array, wanted);

if (pos == -1) {
  console.log("Value not found");
} else {
  console.log(`Value ${wanted} on position ${pos}`);
}

function jumpSearch(array, wanted) {
  const arrayLength = array.length;
  const block = getValueBlockSearch(arrayLength);
  const foundBlock = findBlockWithWanted(array, arrayLength, wanted, block);
  return findValueInBlock(array, arrayLength, foundBlock, wanted, block);
}

function findBlockWithWanted(array, arrayLength, wanted, block) {
  let step = block;
  let prevStep = 0;
  while (array[getStepPosition(step, arrayLength)] < wanted) {
    prevStep = step;
    step += block;
    if (prevStep >= arrayLength) {
      return -1;
    }
  }
  return prevStep;
}

function findValueInBlock(array, arrayLength, prevStep, wanted, block) {
  if (prevStep == -1) {
    return prevStep;
  }
  while (array[prevStep] < wanted) {
    prevStep += 1;
    if (prevStep == Math.min(block, arrayLength)) {
      return -1;
    }
  }
  if (array[prevStep] == wanted) {
    return prevStep;
  }
  return -1;
}

function getStepPosition(step, arrayLength) {
  return Math.min(step, arrayLength) - 1;
}

function getValueBlockSearch(length) {
  return Math.floor(Math.sqrt(length));
}
